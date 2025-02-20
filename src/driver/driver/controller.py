import rclpy
import threading
from rclpy.node import Node
import signal
import ackermann
from nav_msgs.msg import Odometry
from std_srvs.srv import Trigger
import threading
from msgs_srvs.msg import MotorState, PWMServoStateDuration
from geometry_msgs.msg import Pose2D, Pose, Twist, PoseWithCovarianceStamped 


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
        self.x = 0.0
        self.y = 0.0
        self.pose_orientation_z = 0.0
        self.twist_linear_x = 0.0
        self.twist_linear_y = 0.0
        self.twist_angular_z = 0.0

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
            self.odometry = Odometry()
            self.odometry.header.frame_id = self.odom_frame_id
            self.odometry.child_frame_id = self.base_frame_id
            
            # these are mechanical characteristics of the robot, found experimentally I beleive.
            self.odom.pose.covariance = ODOM_POSE_COVARIANCE
            self.odom.twist.covariance = ODOM_TWIST_COVARIANCE

            # create a publisher for odometry
            self.odom_pub = self.create_publisher(Odometry, 'odom_raw', 1)

            # delta t time step for calculating movement in x an y of the odom frame
            dt = 1.0/50.0

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

            
            
