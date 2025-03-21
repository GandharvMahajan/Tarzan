import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Launch node from 'driver' package
        Node(
            package='driver', 
            executable='controller',  
            name='motor_controller',
            output='screen'
        ),

        # Launch node from 'driver' package
        Node(
            package='driver', 
            executable='control_manager',  
            name='control_manager',
            output='screen'
        ),

        # Launch node from 'peripherals' package
        Node(
            package='peripherals', 
            executable='teleop_joy',  
            name='joystick_handler',
            output='screen'
        ),

        # Launch node from internal package
        Node(
            package='joy', 
            executable='joy_node',  
            name='joy_node',
            output='screen'
        )


    ])