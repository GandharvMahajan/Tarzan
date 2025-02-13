# STM32 Python SDK for robot hardware control (Ackerman chassis only)
import enum
import time
import queue
import struct
import serial
import threading

# Communication packet parsing states.
# Packet format: [0xAA, 0x55, Length, Function, ID, Data..., Checksum]
class PacketControllerState(enum.IntEnum):
    STATE_STARTBYTE1 = 0
    STATE_STARTBYTE2 = 1
    STATE_LENGTH = 2
    STATE_FUNCTION = 3
    STATE_DATA = 4
    STATE_CHECKSUM = 5

# Supported packet functions (control features available over the serial port)
class PacketFunction(enum.IntEnum):
    PACKET_FUNC_SYS = 0         # System functions
    PACKET_FUNC_LED = 1         # LED control
    PACKET_FUNC_BUZZER = 2      # Buzzer control
    PACKET_FUNC_MOTOR = 3       # Motor control
    PACKET_FUNC_PWM_SERVO = 4   # PWM servo control (servos on board numbered 1-4)
    PACKET_FUNC_BUS_SERVO = 5   # Bus servo control
    PACKET_FUNC_KEY = 6         # Key/button events
    PACKET_FUNC_IMU = 7         # IMU data
    PACKET_FUNC_GAMEPAD = 8     # Gamepad data
    PACKET_FUNC_SBUS = 9        # SBUS remote control data
    PACKET_FUNC_OLED = 10       # OLED display text setting
    PACKET_FUNC_RGB = 11        # RGB LED control
    PACKET_FUNC_NONE = 12

# Button event flags
class PacketReportKeyEvents(enum.IntEnum):
    KEY_EVENT_PRESSED = 0x01
    KEY_EVENT_LONGPRESS = 0x02
    KEY_EVENT_LONGPRESS_REPEAT = 0x04
    KEY_EVENT_RELEASE_FROM_LP = 0x08
    KEY_EVENT_RELEASE_FROM_SP = 0x08
    KEY_EVENT_CLICK = 0x20
    KEY_EVENT_DOUBLE_CLICK = 0x40
    KEY_EVENT_TRIPLE_CLICK = 0x80

# Precomputed CRC8 lookup table
crc8_table = [
    0, 94, 188, 226, 97, 63, 221, 131, 194, 156, 126, 32, 163, 253, 31, 65,
    157, 195, 33, 127, 252, 162, 64, 30, 95, 1, 227, 189, 62, 96, 130, 220,
    35, 125, 159, 193, 66, 28, 254, 160, 225, 191, 93, 3, 128, 222, 60, 98,
    190, 224, 2, 92, 223, 129, 99, 61, 124, 34, 192, 158, 29, 67, 161, 255,
    70, 24, 250, 164, 39, 121, 155, 197, 132, 218, 56, 102, 229, 187, 89, 7,
    219, 133, 103, 57, 186, 228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154,
    101, 59, 217, 135, 4, 90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36,
    248, 166, 68, 26, 153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185,
    140, 210, 48, 110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205,
    17, 79, 173, 243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14, 80,
    175, 241, 19, 77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82, 176, 238,
    50, 108, 142, 208, 83, 13, 239, 177, 240, 174, 76, 18, 145, 207, 45, 115,
    202, 148, 118, 40, 171, 245, 23, 73, 8, 86, 180, 234, 105, 55, 213, 139,
    87, 9, 235, 181, 54, 104, 138, 212, 149, 203, 41, 119, 244, 170, 72, 22,
    233, 183, 85, 11, 136, 214, 52, 106, 43, 117, 151, 201, 74, 20, 246, 168,
    116, 42, 200, 150, 21, 75, 169, 247, 182, 232, 10, 84, 215, 137, 107, 53
]

# Calculate the CRC8 checksum for a given data bytes array.
def checksum_crc8(data):
    check = 0
    for b in data:
        check = crc8_table[check ^ b]
    return check & 0x00FF

# SBUS status (typically used for remote control data)
class SBusStatus:
    def __init__(self):
        self.channels = [0] * 16
        self.channel_17 = False
        self.channel_18 = False
        self.signal_loss = True
        self.fail_safe = False


# Main Board class to handle serial communication and hardware commands.
class Board:
    # Mapping gamepad button names to bit masks.
    buttons_map = {
        'GAMEPAD_BUTTON_MASK_L2': 0x0001,
        'GAMEPAD_BUTTON_MASK_R2': 0x0002,
        'GAMEPAD_BUTTON_MASK_SELECT': 0x0004,
        'GAMEPAD_BUTTON_MASK_START': 0x0008,
        'GAMEPAD_BUTTON_MASK_L3': 0x0020,
        'GAMEPAD_BUTTON_MASK_R3': 0x0040,
        'GAMEPAD_BUTTON_MASK_CROSS': 0x0100,
        'GAMEPAD_BUTTON_MASK_CIRCLE': 0x0200,
        'GAMEPAD_BUTTON_MASK_SQUARE': 0x0800,
        'GAMEPAD_BUTTON_MASK_TRIANGLE': 0x1000,
        'GAMEPAD_BUTTON_MASK_L1': 0x4000,
        'GAMEPAD_BUTTON_MASK_R1': 0x8000
    }

    def __init__(self, device="/dev/ttyACM0", baudrate=1000000, timeout=10):
        self.enable_recv = False
        self.frame = []
        self.recv_count = 0

        # Initialize serial port.
        self.port = serial.Serial(None, baudrate, timeout=timeout)
        self.port.rts = False
        self.port.dtr = False
        self.port.setPort(device)
        self.port.open()

        self.state = PacketControllerState.STATE_STARTBYTE1
        self.servo_read_lock = threading.Lock()
        self.pwm_servo_read_lock = threading.Lock()

        # Queues for storing received data.
        self.sys_queue = queue.Queue(maxsize=1)
        self.key_queue = queue.Queue(maxsize=1)
        self.imu_queue = queue.Queue(maxsize=1)
        self.gamepad_queue = queue.Queue(maxsize=1)
        self.sbus_queue = queue.Queue(maxsize=1)
        self.bus_servo_queue = queue.Queue(maxsize=1)
        self.pwm_servo_queue = queue.Queue(maxsize=1)

        # Map packet functions to their corresponding parser methods.
        self.parsers = {
            PacketFunction.PACKET_FUNC_SYS: self.packet_report_sys,
            PacketFunction.PACKET_FUNC_KEY: self.packet_report_key,
            PacketFunction.PACKET_FUNC_IMU: self.packet_report_imu,
            PacketFunction.PACKET_FUNC_GAMEPAD: self.packet_report_gamepad,
            PacketFunction.PACKET_FUNC_BUS_SERVO: self.packet_report_serial_servo,
            PacketFunction.PACKET_FUNC_SBUS: self.packet_report_sbus,
            PacketFunction.PACKET_FUNC_PWM_SERVO: self.packet_report_pwm_servo
        }

        time.sleep(0.5)
        threading.Thread(target=self.recv_task, daemon=True).start()

    # System packet parser: store system data.
    def packet_report_sys(self, data):
        try:
            self.sys_queue.put_nowait(data)
        except queue.Full:
            pass

    # Key/button packet parser.
    def packet_report_key(self, data):
        try:
            self.key_queue.put_nowait(data)
        except queue.Full:
            pass

    # IMU data packet parser.
    def packet_report_imu(self, data):
        try:
            self.imu_queue.put_nowait(data)
        except queue.Full:
            pass

    # Gamepad data packet parser.
    def packet_report_gamepad(self, data):
        try:
            self.gamepad_queue.put_nowait(data)
        except queue.Full:
            pass

    # SBUS (remote control) data packet parser.
    def packet_report_sbus(self, data):
        try:
            self.sbus_queue.put_nowait(data)
        except queue.Full:
            pass

    # Bus servo data packet parser.
    def packet_report_serial_servo(self, data):
        try:
            self.bus_servo_queue.put_nowait(data)
        except queue.Full:
            pass

    # PWM servo data packet parser.
    def packet_report_pwm_servo(self, data):
        try:
            self.pwm_servo_queue.put_nowait(data)
        except queue.Full:
            pass

    # Get battery voltage (in mAh).
    def get_battery(self):
        if self.enable_recv:
            try:
                data = self.sys_queue.get(block=False)
                if data[0] == 0x04:
                    return struct.unpack('<H', data[1:])[0]
                else:
                    return None
            except queue.Empty:
                return None
        else:
            print('Enable reception first with enable_reception()!')
            return None
        
    # Get button status. Returns (button_id, status) where status 0=clicked, 1=pressed.
    def get_button(self):
        if self.enable_recv:
            try:
                data = self.key_queue.get(block=False)
                key_id = data[0]
                key_event = PacketReportKeyEvents(data[1])
                if key_event == PacketReportKeyEvents.KEY_EVENT_CLICK:
                    return key_id, 0
                elif key_event == PacketReportKeyEvents.KEY_EVENT_PRESSED:
                    return key_id, 1
            except queue.Empty:
                return None
        else:
            print('Enable reception first with enable_reception()!')
            return None
        
    # Get IMU data: returns ax, ay, az, gx, gy, gz.
    def get_imu(self):
        if self.enable_recv:
            try:
                return struct.unpack('<6f', self.imu_queue.get(block=False))
            except queue.Empty:
                return None
        else:
            print('Enable reception first with enable_reception()!')
            return None

    # Get gamepad data: returns (axes, buttons)
    def get_gamepad(self):
        if self.enable_recv:
            try:
                gamepad_data = struct.unpack("<HB4b", self.gamepad_queue.get(block=False))
                # Initialize axes and buttons arrays.
                axes = [0.0] * 8
                buttons = [0] * 16
                for b in self.buttons_map:
                    if self.buttons_map[b] & gamepad_data[0]:
                        if b == 'GAMEPAD_BUTTON_MASK_R2':
                            axes[4] = 1.0
                        elif b == 'GAMEPAD_BUTTON_MASK_L2':
                            axes[5] = 1.0
                        elif b == 'GAMEPAD_BUTTON_MASK_CROSS':
                            buttons[0] = 1
                        elif b == 'GAMEPAD_BUTTON_MASK_CIRCLE':
                            buttons[1] = 1
                        elif b == 'GAMEPAD_BUTTON_MASK_SQUARE':
                            buttons[3] = 1
                        elif b == 'GAMEPAD_BUTTON_MASK_TRIANGLE':
                            buttons[4] = 1
                        elif b == 'GAMEPAD_BUTTON_MASK_L1':
                            buttons[6] = 1
                        elif b == 'GAMEPAD_BUTTON_MASK_R1':
                            buttons[7] = 1
                        elif b == 'GAMEPAD_BUTTON_MASK_SELECT':
                            buttons[10] = 1
                        elif b == 'GAMEPAD_BUTTON_MASK_START':
                            buttons[11] = 1
               
                if gamepad_data[2] > 0:
                    axes[0] = -gamepad_data[2] / 127
                elif gamepad_data[2] < 0:
                    axes[0] = -gamepad_data[2] / 128

                if gamepad_data[3] > 0:
                    axes[1] = gamepad_data[3] / 127
                elif gamepad_data[3] < 0:
                    axes[1] = gamepad_data[3] / 128

                if gamepad_data[4] > 0:
                    axes[2] = -gamepad_data[4] / 127
                elif gamepad_data[4] < 0:
                    axes[2] = -gamepad_data[4] / 128

                if gamepad_data[5] > 0:
                    axes[3] = gamepad_data[5] / 127
                elif gamepad_data[5] < 0:
                    axes[3] = gamepad_data[5] / 128
            
                if gamepad_data[1] == 9:
                    axes[6] = 1.0
                elif gamepad_data[1] == 13:
                    axes[6] = -1.0
                
                if gamepad_data[1] == 11:
                    axes[7] = -1.0
                elif gamepad_data[1] == 15:
                    axes[7] = 1.0
                return axes, buttons
            except queue.Empty:
                return None
        else:
            print('Enable reception first with enable_reception()!')
            return None

    # Write a buffer to the serial port with the given function and data.
    def buf_write(self, func, data):
        buf = [0xAA, 0x55, int(func)]
        buf.append(len(data))
        buf.extend(data)
        buf.append(checksum_crc8(bytes(buf[2:])))
        buf = bytes(buf)
        self.port.write(buf)
        # Uncomment below to print outgoing buffer for debugging.
        # print(buf)

    # LED control command.
    def set_led(self, on_time, off_time, repeat=1, led_id=1):
        on_time_ms = int(on_time * 1000)
        off_time_ms = int(off_time * 1000)
        self.buf_write(PacketFunction.PACKET_FUNC_LED, struct.pack("<BHHH", led_id, on_time_ms, off_time_ms, repeat))

    # Buzzer control command.
    def set_buzzer(self, freq, on_time, off_time, repeat=1):
        on_time_ms = int(on_time * 1000)
        off_time_ms = int(off_time * 1000)
        self.buf_write(PacketFunction.PACKET_FUNC_BUZZER, struct.pack("<HHHH", freq, on_time_ms, off_time_ms, repeat))

    # Motor control command.
    # speeds: list of tuples (motor_id, speed)
    def set_motor_speed(self, speeds):
        data = [0x01, len(speeds)]
        for motor_id, speed in speeds:
            data.extend(struct.pack("<Bf", int(motor_id - 1), float(speed)))
        self.buf_write(PacketFunction.PACKET_FUNC_MOTOR, data)
    
    # RGB LED control command.
    # pixels: list of tuples (led_index, r, g, b)
    def set_rgb(self, pixels):
        data = [0x01, len(pixels)]
        for index, r, g, b in pixels:
            data.extend(struct.pack("<BBBB", int(index - 1), int(r), int(g), int(b)))
        self.buf_write(PacketFunction.PACKET_FUNC_RGB, data)
        
    # OLED text display command.
    def set_oled_text(self, line, text):
        data = [line, len(text)]  # The second byte is the length of the string (including the null terminator, if needed)
        data.extend(bytes(text, encoding='utf-8'))
        self.buf_write(PacketFunction.PACKET_FUNC_OLED, data)

    # PWM servo command: set position with a given duration.
    # positions: list of tuples (servo_id, position)
    def pwm_servo_set_position(self, duration, positions):
        duration_ms = int(duration * 1000)
        data = [0x01, duration_ms & 0xFF, 0xFF & (duration_ms >> 8), len(positions)]
        for servo_id, pos in positions:
            data.extend(struct.pack("<BH", servo_id, pos))
        self.buf_write(PacketFunction.PACKET_FUNC_PWM_SERVO, data)

    # PWM servo command: set servo offset.
    def pwm_servo_set_offset(self, servo_id, offset):
        data = struct.pack("<BBb", 0x07, servo_id, int(offset))
        self.buf_write(PacketFunction.PACKET_FUNC_PWM_SERVO, data)

    # Helper method to send a PWM servo read command and unpack the response.
    def pwm_servo_read_and_unpack(self, servo_id, cmd, unpack):
        with self.servo_read_lock:
            self.buf_write(PacketFunction.PACKET_FUNC_PWM_SERVO, [cmd, servo_id])
            data = self.pwm_servo_queue.get(block=True)
            servo_id_ret, cmd_ret, info = struct.unpack(unpack, data)
            return info

    # PWM servo command: read servo offset.
    def pwm_servo_read_offset(self, servo_id):
        return self.pwm_servo_read_and_unpack(servo_id, 0x09, "<BBb")

    # PWM servo command: read servo position.
    def pwm_servo_read_position(self, servo_id):
        return self.pwm_servo_read_and_unpack(servo_id, 0x05, "<BBH")

    ################################################
    def bus_servo_enable_torque(self, servo_id, enable):
        if enable:
            data = struct.pack("<BB", 0x0B, servo_id)
        else:
            data = struct.pack("<BB", 0x0C, servo_id)
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)
        time.sleep(0.02)

    def bus_servo_set_id(self, servo_id_now, servo_id_new):
        data = struct.pack("<BBB", 0x10, servo_id_now, servo_id_new)
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)
        time.sleep(0.02)

    def bus_servo_set_offset(self, servo_id, offset):
        data = struct.pack("<BBb", 0x20, servo_id, int(offset))
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)
        time.sleep(0.02)

    def bus_servo_save_offset(self, servo_id):
        data = struct.pack("<BB", 0x24, servo_id)
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)
        time.sleep(0.02)

    def bus_servo_set_angle_limit(self, servo_id, limit):
        data = struct.pack("<BBHH", 0x30, servo_id, int(limit[0]), int(limit[1]))
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)
        time.sleep(0.02)

    def bus_servo_set_vin_limit(self, servo_id, limit):
        data = struct.pack("<BBHH", 0x34, servo_id, int(limit[0]), int(limit[1]))
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)
        time.sleep(0.02)

    def bus_servo_set_temp_limit(self, servo_id, limit):
        data = struct.pack("<BBb", 0x38, servo_id, int(limit))
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)
        time.sleep(0.02)

    def bus_servo_stop(self, servo_id):
        data = [0x03, len(servo_id)] 
        data.extend(struct.pack("<"+'B'*len(servo_id), *servo_id))
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)

    def bus_servo_set_position(self, duration, positions):
        duration = int(duration * 1000)
        data = [0x01, duration & 0xFF, 0xFF & (duration >> 8), len(positions)] # 0x00 is bus servo sub command
        for i in positions:
            data.extend(struct.pack("<BH", i[0], i[1]))
        self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, data)

    def bus_servo_read_and_unpack(self, servo_id, cmd, unpack):
        with self.servo_read_lock:
            self.buf_write(PacketFunction.PACKET_FUNC_BUS_SERVO, [cmd, servo_id])
            data = self.bus_servo_queue.get(block=True)
            servo_id, cmd, success, *info = struct.unpack(unpack, data)
            if success == 0:
                return info

    def bus_servo_read_id(self, servo_id=254):
        return self.bus_servo_read_and_unpack(servo_id, 0x12, "<BBbB")

    def bus_servo_read_offset(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x22, "<BBbb")
    
    def bus_servo_read_position(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x05, "<BBbh")

    def bus_servo_read_vin(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x07, "<BBbH")
    
    def bus_servo_read_temp(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x09, "<BBbB")

    def bus_servo_read_temp_limit(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x3A, "<BBbB")

    def bus_servo_read_angle_limit(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x32, "<BBb2H")

    def bus_servo_read_vin_limit(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x36, "<BBb2H")

    def bus_servo_read_torque_state(self, servo_id):
        return self.bus_servo_read_and_unpack(servo_id, 0x0D, "<BBbb")
    
    ############################################################

    # Enable or disable data reception.
    def enable_reception(self, enable=True):
        self.enable_recv = enable

    # Reception task running in a separate thread.
    def recv_task(self):
        while True:
            if self.enable_recv:
                recv_data = self.port.read()
                if recv_data:
                    for dat in recv_data:
                        # Process one byte at a time based on the current state.
                        if self.state == PacketControllerState.STATE_STARTBYTE1:
                            if dat == 0xAA:
                                self.state = PacketControllerState.STATE_STARTBYTE2
                            continue
                        elif self.state == PacketControllerState.STATE_STARTBYTE2:
                            if dat == 0x55:
                                self.state = PacketControllerState.STATE_FUNCTION
                            else:
                                self.state = PacketControllerState.STATE_STARTBYTE1
                            continue
                        elif self.state == PacketControllerState.STATE_FUNCTION:
                            if dat < int(PacketFunction.PACKET_FUNC_NONE):
                                self.frame = [dat, 0]
                                self.state = PacketControllerState.STATE_LENGTH
                            else:
                                self.frame = []
                                self.state = PacketControllerState.STATE_STARTBYTE1
                            continue
                        elif self.state == PacketControllerState.STATE_LENGTH:
                            self.frame[1] = dat
                            self.recv_count = 0
                            if dat == 0:
                                self.state = PacketControllerState.STATE_CHECKSUM
                            else:
                                self.state = PacketControllerState.STATE_DATA
                            continue
                        elif self.state == PacketControllerState.STATE_DATA:
                            self.frame.append(dat)
                            self.recv_count += 1
                            if self.recv_count >= self.frame[1]:
                                self.state = PacketControllerState.STATE_CHECKSUM
                            continue
                        elif self.state == PacketControllerState.STATE_CHECKSUM:
                            crc8 = checksum_crc8(bytes(self.frame))
                            if crc8 == dat:
                                func = PacketFunction(self.frame[0])
                                data = bytes(self.frame[2:])
                                if func in self.parsers:
                                    self.parsers[func](data)
                            else:
                                print("Checksum failed")
                            self.state = PacketControllerState.STATE_STARTBYTE1
                            continue
            else:
                time.sleep(0.01)
        self.port.close()
        print("END...")


def bus_servo_test(board):
    board.bus_servo_set_position(1, [[1, 500], [2, 500]])
    time.sleep(1)
    board.bus_servo_set_position(2, [[1, 0], [2, 0]])
    time.sleep(1)
    board.bus_servo_stop([1, 2])
    time.sleep(1)
    
    servo_id = 1
    board.bus_servo_set_id(254, servo_id)
    servo_id = board.bus_servo_read_id()
    if servo_id is not None:
        servo_id = servo_id[0]
        
        offset_set = -10
        board.bus_servo_set_offset(servo_id, offset_set)
        board.bus_servo_save_offset(servo_id)
        
        vin_l, vin_h = 4500, 14500
        board.bus_servo_set_vin_limit(servo_id, [vin_l, vin_h])

        temp_limit = 85
        board.bus_servo_set_temp_limit(servo_id, temp_limit)

        angle_l, angle_h = 0, 1000
        board.bus_servo_set_angle_limit(servo_id, [angle_l, angle_h])
        
        board.bus_servo_enable_torque(servo_id, 1)

        print('id:', board.bus_servo_read_id(servo_id))
        print('offset:', board.bus_servo_read_offset(servo_id), offset_set)
        print('vin:', board.bus_servo_read_vin(servo_id))
        print('temp:', board.bus_servo_read_temp(servo_id))
        print('position:', board.bus_servo_read_position(servo_id))
        print('angle_limit:', board.bus_servo_read_angle_limit(servo_id), [angle_l, angle_h])
        print('vin_limit:', board.bus_servo_read_vin_limit(servo_id), [vin_l, vin_h])
        print('temp_limit:', board.bus_servo_read_temp_limit(servo_id), temp_limit)
        print('torque_state:', board.bus_servo_read_torque_state(servo_id))



def pwm_servo_test(board):
    servo_id = 1
    # Define target positions (these values are example limits).
    # Adjust these numbers according to your servo's specific range.
    left_position = 500     # one extreme position (e.g., fully left)
    right_position = 2500   # the other extreme position (e.g., fully right)
    center_position = 1500  # center position

    # Duration for the servo to reach each position (in seconds)
    move_duration = 0.5

    print("Moving PWM servo to left extreme...")
    board.pwm_servo_set_position(move_duration, [[servo_id, left_position]])
    time.sleep(move_duration + 0.5)  # extra delay for smooth transition

    print("Moving PWM servo to right extreme...")
    board.pwm_servo_set_position(move_duration, [[servo_id, right_position]])
    time.sleep(move_duration + 0.5)

    print("Moving PWM servo back to center...")
    board.pwm_servo_set_position(move_duration, [[servo_id, center_position]])
    time.sleep(move_duration + 0.5)

if __name__ == "__main__":
    board = Board()
    board.enable_reception()
    print("START...")
    # Example commands:
    board.set_led(0.1, 0.9, repeat=1, led_id=1)
    board.set_buzzer(1900, 0.05, 0.01, repeat=1)
    
    pwm_servo_test(board)
#    bus_servo_test(board)
#    board.bus_servo_set_position(1, [[1, 700], [2, 500]])
