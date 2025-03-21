'''
This class converts the twist command from keyboard or joystick to motor speeds and servo angle
'''
import logging
import math
from msgs_srvs.msg import MotorsState, MotorState 


logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG) 

class Ackermann:
    def __init__(self, wheelbase=0.145, track_width=0.133, wheel_diameter=0.067):
        self.wheelbase = wheelbase
        self.track_width = track_width
        self.wheel_diameter = wheel_diameter

    def speed_convert(self, speed):
        # convert speed from m/s to rotations/second
        return speed / (math.pi * self.wheel_diameter)
    
    def twist_to_wheel_cmd(self, twist_linear_x, twist_angular_z):
        servo_angle = 1500
        data = []
        # Always compute servo based on twist_angular_z (independent of linear velocity)
        if abs(twist_angular_z) > 1e-8:
            steering_angle = math.atan(
                self.wheelbase * twist_angular_z / (twist_linear_x if abs(twist_linear_x) > 1e-8 else 1e-8)
            )
            if abs(steering_angle) > math.radians(29):
                steering_angle = math.copysign(math.radians(29), steering_angle)
            servo_angle = 1500 + 2000 * math.degrees(-steering_angle) / 180

        # Calculate motor speeds if linear or angular velocity is non-trivial
        if abs(twist_linear_x) > 1e-8 or abs(twist_angular_z) > 1e-8:
            vr = twist_linear_x + twist_angular_z * (self.track_width / 2)
            vl = twist_linear_x - twist_angular_z * (self.track_width / 2)
            v_s = [self.speed_convert(v) for v in [0, vl, 0, -vr]]

            for i in range(len(v_s)):
                motor_state = MotorState()
                motor_state.id = i + 1
                motor_state.rps = float(v_s[i])
                data.append(motor_state)

            motors_state = MotorsState()
            motors_state.data = data
            logger.debug(f"Computed values: servo_theta={servo_angle}, motor_speed={motors_state}")
            return servo_angle, motors_state
        else:
            # No movement in linear or angular velocity => motors off, servo can still move
            for i in range(4):
                motor_state = MotorState()
                motor_state.id = i + 1
                motor_state.rps = 0.0
                data.append(motor_state)

            motors_state = MotorsState()
            motors_state.data = data
            logger.debug(f"Computed values: servo_theta={servo_angle}, motor_speed={motors_state}")
            return servo_angle, motors_state
