'''
Controller class takes in the twist commands from the user keyboard or joystick and sets the motor speeds and servo theta of the robot. it also publishes the odom_raw topic which tells the robot position in the odom frame.
This controller doesn't use any sensor not even IMU to calculate position of the robot. It calculates position by integrating the command velocity (/cmd_vel topic) from the keyboard or joystick
'''
import rclpy
import threading
from rclpy.node import Node
import signal
from driver import ackermann
from nav_msgs.msg import Odometry
from std_srvs.srv import Trigger
import threading
from msgs_srvs.msg import MotorState, PWMServoState, PWMServoStateDuration
from geometry_msgs.msg import Pose2D, Pose, Twist, PoseWithCovarianceStamped 
import time
import math

ODOM_POSE_COVARIANCE = list(map(float, 
                        [1e-3, 0, 0, 0, 0, 0, 
                        0, 1e-3, 0, 0, 0, 0,
                        0, 0, 1e6, 0, 0, 0,
                        0, 0, 0, 1e6, 0, 0,
                        0, 0, 0, 0, 1e6, 0,
                        0, 0, 0, 0, 0, 1e3]))

ODOM_TWIST_COVARIANCE = list(map(float, 
                        [1e-3, 0, 0, 0, 0, 0, 
                         0, 1e-3, 0, 0, 0, 0,
                         0, 0, 1e6, 0, 0, 0,
                         0, 0, 0, 1e6, 0, 0,
                         0, 0, 0, 0, 1e6, 0,
                         0, 0, 0, 0, 0, 1e3]))

ODOM_POSE_COVARIANCE_STOP = list(map(float, 
                            [1e-9, 0, 0, 0, 0, 0, 
                             0, 1e-3, 1e-9, 0, 0, 0,
                             0, 0, 1e6, 0, 0, 0,
                             0, 0, 0, 1e6, 0, 0,
                             0, 0, 0, 0, 1e6, 0,
                             0, 0, 0, 0, 0, 1e-9]))

ODOM_TWIST_COVARIANCE_STOP = list(map(float, 
                            [1e-9, 0, 0, 0, 0, 0, 
                              0, 1e-3, 1e-9, 0, 0, 0,
                              0, 0, 1e6, 0, 0, 0,
                              0, 0, 0, 1e6, 0, 0,
                              0, 0, 0, 0, 1e6, 0,
                              0, 0, 0, 0, 0, 1e-9]))

# conver rotation data from roll, pitch, yaw to quaternion because pose.pose.orientation uses quaternion but we calculate robot orientation in rpy (although roll and pitch is 0, and yaw is pose_orientation_z)
def rpy2qua(roll, pitch, yaw):
    cy = math.cos(yaw*0.5)
    sy = math.sin(yaw*0.5)
    cp = math.cos(pitch*0.5)
    sp = math.sin(pitch*0.5)
    cr = math.cos(roll * 0.5)
    sr = math.sin(roll * 0.5)
    
    q = Pose()
    q.orientation.w = cy * cp * cr + sy * sp * sr
    q.orientation.x = cy * cp * sr - sy * sp * cr
    q.orientation.y = sy * cp * sr + cy * sp * cr
    q.orientation.z = sy * cp * cr - cy * sp * sr
    return q.orientation

class Controller(Node):
    def __init__(self, name):
        rclpy.init()
        super().__init__(name)
        # pose.pose.position.z	0.0	No vertical movement
        # pose.pose.orientation.x	0.0	No roll
        # pose.pose.orientation.y	0.0	No pitch
        # twist.twist.linear.z	0.0	No vertical velocity
        # twist.twist.angular.x	0.0	No roll
        # twist.twist.angular.y	0.0	No pitch

        # Initialize all other variables
        # position x and y and theta in odom frame
        self.pose_position_x = 0.0
        self.pose_position_y = 0.0
        self.pose_orientation_z = 0.0

        # velocity in x and y and angular velocity in z
        self.twist_linear_x = 0.0
        self.twist_linear_y = 0.0
        self.twist_angular_z = 0.0

        # this will be needed to calculate the dt or delta time for each publisher loop
        self.current_time = None
        self.last_time = None

        # Create a custom shutdown for the node, gracefully shutting down the node when user interrupts
        signal.signal(signal.SIGINT, self.shutdown)

        self.ackermann = ackermann.Ackermann(wheelbase=0.145, track_width=0.133, wheel_diameter=0.067)

        # Declare parameters
        self.declare_parameter('pub_odom_topic', True)
        self.declare_parameter('base_frame_id', 'base_footprint')
        self.declare_parameter('odom_frame_id', 'odom')
        self.declare_parameter('linear_correction_factor', 1.00)

        self.pub_odom_topic = self.get_parameter('pub_odom_topic').value
        self.base_frame_id = self.get_parameter('base_frame_id').value
        self.odom_frame_id = self.get_parameter('odom_frame_id').value

        self.linear_correction_factor = self.get_parameter('linear_correction_factor').value

        # start clock for setting the header in messages, some messages do need that. get_clock is inherited from the Node (parent) class.
        self.clock = self.get_clock()
        
        # Initializing the odom topic
        if self.pub_odom_topic:
            # Odometry contains header (stamp and frame_id), child_frame, pose (position x,y,z | orientation x,y,z,w and covariance) and twist (linear vel x,y,z | angular vel x, y, z and covariance)
            self.odom = Odometry()
            self.odom.header.frame_id = self.odom_frame_id
            self.odom.child_frame_id = self.base_frame_id
            
            # these are mechanical characteristics of the robot, found experimentally I beleive.
            self.odom.pose.covariance = ODOM_POSE_COVARIANCE
            self.odom.twist.covariance = ODOM_TWIST_COVARIANCE

            # create a publisher for odometry
            self.odom_pub = self.create_publisher(Odometry, 'odom_raw', 1)

            # delta t time step for calculating movement in x an y directions in the odom frame
            self.dt = 1.0/50.0

            # start the thread,  daemon = True means that process will end if node is ended if Daemon = False, the thread will complete before closing the node.
            threading.Thread(target=self.calculate_odometry, daemon=True).start()

        # create a publisher for motors and servos
        self.motor_pub = self.create_publisher(MotorState, '/control_manager/set_motor',1)
        self.servo_state_pub = self.create_publisher(PWMServoStateDuration, '/control_manager/pwm_servo/set_state', 10)

        # Publish pose (position + orientation) with covariance
        self.pose_pub = self.create_publisher(PoseWithCovarianceStamped, 'set_pose', 1)

        # Subscribers   
        # teleop_twist_keyboard node publishes a twist command through the keyboard on the topic /cmd_vel
        self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_callback, 1)

        # create service for node operation
        self.create_service(Trigger, '~/init_finish', self.get_node_state)

    def get_node_state(self, request, response):
        response.success = True
        return response

    # Custom shutdown
    def shutdown(self, signum, frame):
        self.get_logger().info('\033[1;32m%s\033[0m' % 'shutdown')
        rclpy.shutdown()

    def cmd_vel_callback(self, msg):
        # clipping all the values
        if msg.linear.x > 0.2:
            msg.linear.x = 0.2
        if msg.linear.x < -0.2:
            msg.linear.x = -0.2
        if msg.linear.y > 0.2:
            msg.linear.y = 0.2
        if msg.linear.y < -0.2:
            msg.linear.y = -0.2
        if msg.angular.z > 0.5:
            msg.angular.z = 0.5
        if msg.angular.z < -0.5:
            msg.angular.z = -0.5

        # setting the forward velocity of the robot from the cmd_vel x velocity (coming from keyboard) 
        self.twist_linear_x = msg.linear.x
        
        # if angular z velocity is not zero, which means if the robot is not going straight forward or backward, then we want to set the servo theta
        if msg.angular.z != 0:
            # calculate the radius of curvature
            r = self.twist_linear_x / msg.angular.z
            # if the radius of curvature is zero then the angular z is inf which again means the robot is going straight forward or backward if r is not 0 then set robot's angular z velocity from the keyboard
            if r == 0:
                self.twist_angular_z = 0.0
            else:
                self.twist_angular_z = msg.angular.z

            # setting the servo position and duration, the position is set at every 20 ms duartion which corresponds to 50 Hz which ensures that the servo movement is smooth
            servo_state = PWMServoState() # this message only contains id, position and offset
            servo_state.id = 3 # servo is connected to third pwm pin

            # get the servo angle and motor speeds as [theta, MotorsState], set speed function changes keyboard commands to servo theta and motor speeds
            servo_theta_and_motor_speed = self.ackermann.twist_to_wheel_cmd(self.twist_linear_x, self.twist_angular_z)

            self.get_logger().info(f"Servo: {servo_theta_and_motor_speed}, Motor: {servo_theta_and_motor_speed}")

            # publish the motor speed
            self.motor_pub.publish(servo_theta_and_motor_speed[1])

            if servo_theta_and_motor_speed[0] is not None:
                servo_state.position = int(servo_theta_and_motor_speed[0])
                # set the servo_state message in Servo state duration message
                servo_state_duration = PWMServoStateDuration()
                servo_state_duration.state = [servo_state]
                servo_state_duration.duration = 0.02 # for smooth movement
                self.servo_state_pub.publish(servo_state_duration)
            
            else:
                # Moving straigh, set only the motor speeds
                self.twist_angular_z = 0.0
                servo_theta_and_motor_speed = self.ackermann.set_speed(self.twist_linear_x, self.twist_angular_z)
                self.motor_pub.publish(servo_theta_and_motor_speed[1])

    # Function for publishing the position of the robot in odom frame 
    def calculate_odometry(self):
        while True:
            self.current_time = time.time()

            if self.last_time is None:
                self.dt = 0.0
            else:
                self.dt = self.current_time - self.last_time
            
            self.odom.header.stamp = self.clock.now().to_msg()

            # we will calculate the position of the robot through it's velocity becuase keyboard commands doesn't give us position directly, it only gives velocity and angular velocity. This integration is numerical and small errors in velocity from sensors keep adding up in position.
            # Calculate small delta in position from delta_t
            delta_pose_position_x = self.twist_linear_x * self.dt * math.cos(self.pose_orientation_z)
            delta_pose_position_y = self.twist_linear_x * self.dt * math.sin(self.pose_orientation_z)
            delta_pose_orientation_z = self.twist_angular_z * self.dt

            # Numerical integration
            self.pose_position_x += delta_pose_position_x
            self.pose_position_y += delta_pose_position_y
            self.pose_orientation_z += delta_pose_orientation_z

            # set the odometry 
            self.odom.pose.pose.position.x = self.linear_correction_factor * self.pose_position_x
            self.odom.pose.pose.position.y = self.linear_correction_factor * self.pose_position_y
            self.odom.pose.pose.orientation = rpy2qua(0,0,self.pose_orientation_z)
            self.odom.twist.twist.linear.x = self.twist_linear_x
            self.odom.twist.twist.linear.y = self.twist_linear_y
            self.odom.twist.twist.angular.z = self.twist_angular_z

            if self.twist_linear_x == 0 and self.twist_linear_y == 0 and self.twist_angular_z == 0:
                self.odom.pose.covariance = ODOM_POSE_COVARIANCE_STOP
                self.odom.twist.covariance = ODOM_TWIST_COVARIANCE_STOP
            else:
                self.odom.pose.covariance = ODOM_POSE_COVARIANCE
                self.odom.twist.covariance = ODOM_TWIST_COVARIANCE
            # publish odom
            self.odom_pub.publish(self.odom)
            self.last_time = self.current_time
            time.sleep(0.02)

def main():
    node = Controller('controller')
    rclpy.spin(node)

if __name__ == "__main__":
    main()





            
