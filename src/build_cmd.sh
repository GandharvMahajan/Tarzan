colcon build --symlink-install
source install/setup.bash

if [ -z "$1" ]; then
    read -p "Please enter the package name to run: " package
else
    package=$1
fi

echo "Running ros2 package: $package"
ros2 run driver $package