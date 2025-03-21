import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from msgs_srvs.msg import BuzzerState

class TeleopJoy(Node):
    def __init__(self):
        super().__init__('teleop_joy')

        # declare parameters for maximum speed
        self.declare_parameter('max_motor_speed', 0.2)
        self.declare_parameter('max_servo_steering', 0.5)
        self.max_motor_speed = self.get_parameter('max_motor_speed').value
        self.max_servo_steering = self.get_parameter('max_servo_steering').value

        # create a subscriber for topic /joy
        self.joy_subscriber = self.create_subscription(Joy, '/joy', self.joy_callback, 10)

        # Publisher to the cmd_vel topic
        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )

        # Publisher for buzzer
        self.buzzer_publisher = self.create_publisher(BuzzerState, '/control_manager/set_buzzer', 10)

        # Track whether the X button was pressed previously (to avoid spamming buzzer)
        self.last_x_pressed = False

        self.get_logger().info("Teleop Joy node started. Listening to joystick inputs...")

    def joy_callback(self, msg: Joy):
        # -- 1) Handle motor commands (left stick Y) --------------------------
        # Typically left stick Y is msg.axes[1]; invert sign if needed
        motor_speed_input = msg.axes[1]
        # Scale it
        motor_speed = motor_speed_input * self.max_motor_speed

        # -- 2) Handle servo commands (right stick X) ------------------------
        # Typically right stick X is msg.axes[3]
        servo_input = msg.axes[2]
        # Scale it
        servo_steer = servo_input * self.max_servo_steering

        # Publish Twist (this will be processed by your ackermann code,
        # controlling the servo from angular.z and the motors from linear.x)
        twist = Twist()
        twist.linear.x = motor_speed
        twist.angular.z = servo_steer
        self.cmd_vel_publisher.publish(twist)

        # -- 3) Handle buzzer when X button is pressed -----------------------
        # For an Xbox controller, “X” is often msg.buttons[2].
        # Check the actual button indices by printing msg.buttons if unsure.
        x_button_pressed = (msg.buttons[3] == 1)

        if x_button_pressed and not self.last_x_pressed:
            # Publish a single beep whenever X transitions from not pressed to pressed
            buzzer_msg = BuzzerState()
            buzzer_msg.freq = 2500
            buzzer_msg.on_time = 0.05
            buzzer_msg.off_time = 0.01
            buzzer_msg.repeat = 1
            self.buzzer_publisher.publish(buzzer_msg)

        # Update tracking
        self.last_x_pressed = x_button_pressed

def main():
    rclpy.init()
    node = TeleopJoy()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
