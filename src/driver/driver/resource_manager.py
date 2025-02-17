import rclpy
import time
import math
from rclpy.node import Node
from .hardware_interface import Board, PacketReportKeyEvents
from sensor_msgs.msg import Imu, Joy
from msgs_srvs.msg import ButtonState, MotorsState, PWMServoStateDuration, LedState, BuzzerState
from msgs_srvs.srv import PWMServoState
from std_msgs.msg import UInt16, Bool
from std_srvs.srv import Trigger
import threading
import yaml


class ResourceManager(Node):
    def __init__(self, name):
        rclpy.init()
        super().__init__(name)
        self.board = Board()
        self.running = True

        # Enable board reception immediately and mark it as enabled.
        self.board.enable_reception()
        self.reception_enabled = True

        self.declare_parameter('imu_frame', 'imu_link')
        self.declare_parameter('init_finish', False)
        self.IMU_FRAME = self.get_parameter('imu_frame').value
        self.gravity = 9.80665
        
        # Hardcoded servo offset values:
        self.servo_offsets = {1: 0, 2: 0, 3: 4, 4: 0}

        # Publisher
        self.imu_pub = self.create_publisher(Imu, '~/imu_raw', 1)
        self.joy_pub = self.create_publisher(Joy, '~/joy', 1)
        self.button_pub = self.create_publisher(ButtonState, '~/button', 1)
        self.battery_pub = self.create_publisher(UInt16, '~/battery', 1)

        # Subscriptions
        self.create_subscription(LedState, '~/set_led', self.set_led_state, 5)
        self.create_subscription(BuzzerState, '~/set_buzzer', self.set_buzzer_state, 5)
        # self.create_subscription(OLEDState, '~/set_oled', self.set_oled_state, 5)
        self.create_subscription(MotorsState, '~/set_motor', self.set_motor_state, 10)
        self.create_subscription(Bool, '~/enable_reception', self.enable_reception_callback, 1)
        # self.create_subscription(RGBStates, '~/set_rgb', self.set_rgb_states, 10)
        self.create_subscription(PWMServoStateDuration, '~/pwm_servo/set_state', self.set_pwm_servo_state, 10)

        # Services 
        self.create_service(PWMServoState, '~/pwm_servo/get_state', self.get_pwm_servo_state)
        self.create_service(Trigger, '~/init_finish', self.get_node_state)

        # Load servo offsets from YAML file
        self.load_servo_offsets()

        # Initialize motor speeds to zero.
        # Only motors 2 and 4 are connected. 
        self.board.set_motor_speed([[1, 0], [2, 0], [3, 0], [4, 0]])
        self.clock = self.get_clock()
        threading.Thread(target=self.pub_callback, daemon=True).start()
        self.get_logger().info('\033[1;32m%s\033[0m' % 'start')

    def load_servo_offsets(self):
        """
        Load and apply PWM servo offsets from a hardcoded dictionary.
        The dictionary keys are servo IDs and values are the offsets.
        """
        
        # Iterate over servo IDs 1 to 4 and apply the offsets.
        for servo_id in range(1, 5):
            offset = self.servo_offsets.get(servo_id, 0)  # Default to 0 if not present
            try:
                self.board.pwm_servo_set_offset(servo_id, offset)
                self.get_logger().info(f"Set PWM servo {servo_id} offset to {offset}")
            except Exception as e:
                self.get_logger().error(f"Error setting PWM servo {servo_id} offset: {e}")  

    def get_node_state(self, request, response):
        response.success = True
        return response
    
    def pub_callback(self):
        while self.running:
            if self.reception_enabled:
                self.pub_button_data(self.button_pub)
                self.pub_joy_data(self.joy_pub)
                self.pub_imu_data(self.imu_pub)
                self.pub_battery_data(self.battery_pub)
                time.sleep(0.02)
            else:
                time.sleep(0.02)
        rclpy.shutdown()

    def enable_reception_callback(self, msg):
        self.get_logger().info(f"enable_reception {msg.data}")
        self.reception_enabled = msg.data
        self.board.enable_reception(msg.data)

    def set_led_state(self, msg):
        self.board.set_led(msg.on_time, msg.off_time, msg.repeat, msg.id)

    def set_buzzer_state(self, msg):
        self.board.set_buzzer(msg.freq, msg.on_time, msg.off_time, msg.repeat)

    def set_motor_state(self, msg):
        data = []
        for i in msg.data:
            data.append([i.id, i.rps])
        self.board.set_motor_speed(data)

    def set_pwm_servo_state(self, msg):
        data = []
        for i in msg.state:
            # If a position is specified, set the PWM servo position.
            if i.id and i.position:
                data.append([i.id[0], i.position[0]])
            # If an offset is specified, update the servo offset.
            if i.id and i.offset:
                self.board.pwm_servo_set_offset(i.id[0], i.offset[0])
        if data:
            self.board.pwm_servo_set_position(msg.duration, data)

    def get_pwm_servo_state(self, request, response):
        states = []
        for i in request.cmd:
            data = PWMServoState()
            if i.position:
                state = self.board.pwm_servo_read_position(i.id)
                if state is not None:
                    data.position = state
            if i.offset:
                state = self.board.pwm_servo_read_offset(i.id)
                if state is not None:
                    data.offset = state
            states.append(data)
        response.state = states
        response.success = True
        return response
    
    def pub_battery_data(self, pub):
        data = self.board.get_battery()
        if data is not None:
            msg = UInt16()
            msg.data = data
            pub.publish(msg)
    
    def pub_button_data(self, pub):
        data = self.board.get_button()
        if data is not None:
            key_id, key_event = data
            state_map = {
                PacketReportKeyEvents.KEY_EVENT_PRESSED: 1,
                PacketReportKeyEvents.KEY_EVENT_LONGPRESS: 2,
                PacketReportKeyEvents.KEY_EVENT_LONGPRESS_REPEAT: 3,
                PacketReportKeyEvents.KEY_EVENT_RELEASE_FROM_LP: 4,
                PacketReportKeyEvents.KEY_EVENT_RELEASE_FROM_SP: 0,
                PacketReportKeyEvents.KEY_EVENT_CLICK: 5,
                PacketReportKeyEvents.KEY_EVENT_DOUBLE_CLICK: 6,
                PacketReportKeyEvents.KEY_EVENT_TRIPLE_CLICK: 7,
            }
            state = state_map.get(key_event, -1)

            if state != -1:
                msg = ButtonState()
                msg.id = key_id
                msg.state = state
                pub.publish(msg)
            else:
                self.get_logger().error(f"Unhandled button event: {key_event}")

    def pub_joy_data(self, pub):
        data = self.board.get_gamepad()
        if data is not None:
            msg = Joy()
            msg.axes = data[0]
            msg.buttons = data[1]
            msg.header.stamp = self.clock.now().to_msg()
            pub.publish(msg)

    def pub_imu_data(self, pub):
        data = self.board.get_imu()
        if data is not None:
            ax, ay, az, gx, gy, gz = data
            msg = Imu()
            msg.header.frame_id = self.IMU_FRAME
            msg.header.stamp = self.clock.now().to_msg()

            # Set orientation (if available, otherwise set to zero)
            msg.orientation.w = 0.0
            msg.orientation.x = 0.0
            msg.orientation.y = 0.0
            msg.orientation.z = 0.0

            # Convert acceleration from g's to m/s²
            msg.linear_acceleration.x = ax * self.gravity
            msg.linear_acceleration.y = ay * self.gravity
            msg.linear_acceleration.z = az * self.gravity

            # Convert angular velocity from degrees/s to radians/s
            msg.angular_velocity.x = math.radians(gx)
            msg.angular_velocity.y = math.radians(gy)
            msg.angular_velocity.z = math.radians(gz)

            msg.orientation_covariance = [0.01, 0.0, 0.0,
                                          0.0, 0.01, 0.0,
                                          0.0, 0.0, 0.01]
            msg.angular_velocity_covariance = [0.01, 0.0, 0.0,
                                               0.0, 0.01, 0.0,
                                               0.0, 0.0, 0.01]
            msg.linear_acceleration_covariance = [0.0004, 0.0, 0.0,
                                                  0.0, 0.0004, 0.0,
                                                  0.0, 0.0, 0.004]
            pub.publish(msg)


def main():
    node = ResourceManager('resource_manager')
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        # Safely stop motors on shutdown.
        node.board.set_motor_speed([[1, 0], [2, 0], [3, 0], [4, 0]])
        node.destroy_node()
        rclpy.shutdown()
        print('shutdown resource manager')
    finally:
        print('shutdown resource manager finish')


if __name__ == '__main__':
    main()
