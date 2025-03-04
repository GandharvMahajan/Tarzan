
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash

echo "Checking running ROS 2 nodes..."
ros2 node list | grep control_manager
if [ $? -ne 0 ]; then
    echo "ERROR: control_manager node is not running!"
    exit 1
fi

echo "ControlManager is running!"

echo "Publishing to ~/set_led topic 4 times..."
for i in {1..4}
do
    ros2 topic pub /pwm_servo/set_state msgs_srvs/PWMServoStateDuration "state: [{id: 1, position: 90, offset: 5}], duration: 1.5" &
    sleep 1  # Adjust the sleep time as needed
done

echo "Finished publishing 4 messages."



