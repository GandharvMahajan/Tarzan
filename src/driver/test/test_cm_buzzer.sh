
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash

echo "Checking running ROS 2 nodes..."
ros2 node list | grep control_manager
if [ $? -ne 0 ]; then
    echo "ERROR: control_manager node is not running!"
    exit 1
fi

echo "ControlManager is running!"

echo "Publishing to ~/set_led topic 10 times..."
for i in {1..10}
do
    ros2 topic pub /set_buzzer msgs_srvs/BuzzerState "{freq: 500, on_time: 1.0, off_time: 1.0, repeat: 2}" &
    sleep 1  # Adjust the sleep time as needed
done

echo "Finished publishing 10 messages."