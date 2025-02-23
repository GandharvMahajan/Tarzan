#!/bin/bash
# Bash script to test ROS 2 ControlManager node presence

source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash

echo "Checking running ROS 2 nodes..."
ros2 node list | grep control_manager
if [ $? -ne 0 ]; then
    echo "ERROR: control_manager node is not running!"
    exit 1
fi

echo "ControlManager is running!"