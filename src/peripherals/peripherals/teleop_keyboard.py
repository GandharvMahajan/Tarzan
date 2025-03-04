#!/usr/bin/env python3
import curses
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class KeyboardTeleop(Node):
    def __init__(self, stdscr):
        super().__init__('keyboard_teleop')
        # Publisher to send Twist messages to the controller (make sure the topic matches your controller's subscription)
        self.publisher_ = self.create_publisher(Twist, 'controller/cmd_vel', 1)
        self.speed = 0.2      # forward (or backward) speed
        self.turn  = 0.5      # angular speed for turning
        self.stdscr = stdscr
        self.stdscr.nodelay(True)   # make getch non-blocking
        self.stdscr.keypad(True)
        self.get_logger().info("Keyboard Teleop Node Started: Use WASD to control the robot, Q to quit.")

    def run(self):
        twist = Twist()
        self.stdscr.addstr(0, 0, "W: forward, S: backward, A: left, D: right. Press Q to quit.")
        while rclpy.ok():
            # In every cycle, poll for key presses
            keys = set()
            while True:
                try:
                    key = self.stdscr.getkey()
                    keys.add(key.lower())
                except Exception:
                    # No more keys available to read this cycle
                    break

            linear = 0.0
            angular = 0.0

            # Set the forward/backward speed based on W/S.
            if 'w' in keys:
                linear = self.speed
            elif 's' in keys:
                linear = -self.speed

            # Only allow turning if there is a forward (or backward) command.
            if linear != 0:
                if 'a' in keys:
                    angular = self.turn
                elif 'd' in keys:
                    angular = -self.turn

            twist.linear.x = linear
            twist.angular.z = angular

            self.publisher_.publish(twist)

            # If Q is pressed, break out of the loop to quit.
            if 'q' in keys:
                break

            # Run at about 20Hz (adjust as needed)
            rclpy.spin_once(self, timeout_sec=0.05)

def main(stdscr):
    rclpy.init()
    teleop_node = KeyboardTeleop(stdscr)
    try:
        teleop_node.run()
    except KeyboardInterrupt:
        pass
    finally:
        teleop_node.destroy_node()
        rclpy.shutdown()

def main_wrapper():
    """
    This is what ROS 2 will actually call when you do 'ros2 run ... teleop_keyboard'.
    It doesn't require arguments, so it won't raise the TypeError.
    """
    curses.wrapper(main)

if __name__ == '__main__':
    # curses.wrapper initializes the curses environment and cleans up afterward.
    main_wrapper()
