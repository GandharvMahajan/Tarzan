source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash

echo "Checking running ROS 2 nodes..."
ros2 node list | grep control_manager
if [ $? -ne 0 ]; then
    echo "ERROR: control_manager node is not running!"
    exit 1
fi

echo "ControlManager is running!"

echo "Testing Motors state publishing 4 times..."
for i in {1..4}
do
    ros2 topic pub /set_motor msgs_srvs/MotorsState "data: [{id: 1, rps: 10.5}, {id: 2, rps: 15.2}]" &
    sleep 1  # Adjust the sleep time as needed
done

echo "Finished publishing 4 messages."
