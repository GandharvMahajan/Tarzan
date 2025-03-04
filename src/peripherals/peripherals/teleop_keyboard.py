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
        # Persistent state for keys
        self.key_state = {'w': False, 'a': False, 's': False, 'd': False}

    def update_key_state(self):
        """Poll for key events and update the key_state."""
        try:
            while True:
                key = self.stdscr.getkey()
                key = key.lower()
                if key in self.key_state:
                    self.key_state[key] = True
                elif key == 'q':
                    self.key_state['q'] = True
        except Exception:
            # No more keys in the buffer
            pass
    
    def clear_key_state(self):
        """Clear transient keys (for simplicity, assume keys are only momentary)"""
        for k in self.key_state:
            self.key_state[k] = False
    
    def run(self):
        self.stdscr.addstr(0, 0, "W: forward, S: backward, A: left, D: right. Press Q to quit.")
        while rclpy.ok():
            self.update_key_state()

            # Determine velocities based on persistent state
            linear = 0.0
            angular = 0.0

            if self.key_state.get('w'):
                linear = self.speed
            elif self.key_state.get('s'):
                linear = -self.speed

            if linear != 0:
                if self.key_state.get('a'):
                    angular = self.turn
                elif self.key_state.get('d'):
                    angular = -self.turn

            twist = Twist()
            twist.linear.x = linear
            twist.angular.z = angular
            self.publisher_.publish(twist)

            if self.key_state.get('q'):
                break

            # Sleep briefly before next poll
            time.sleep(0.05)
            self.clear_key_state()

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
    curses.wrapper(main)

if __name__ == '__main__':
    main_wrapper()