# Balor
Single camera ackermann drive embedded platform.

## kitt_msgs

git clone https://github.com/kittcar/kitt_msgs.git

## rosserial_arduino
To interface with ROS, [rosserial_arduino](http://wiki.ros.org/rosserial_arduino) is used.
It needs to be built from source, due to lack of support for the teensy in the debians (https://forum.pjrc.com/threads/40418-rosserial_arduino-for-Teensy).
```
cd ~/catkin_ws/src
git clone https://github.com/ros-drivers/rosserial.git --branch indigo-devel
```
To build, be sure to [set up catkin](#initialize-catkin-workspace) and get [kitt_msgs](#kitt_msgs).
```
cd ~/catkin_ws
catkin_make
source ~/catkin_ws/devel/setup.bash
mkdir -p sketchbook/libraries
rosrun rosserial_arduino make_libraries.py sketchbook/libraries
```
[Export library location to environment.](#rosserial-library)

## rosserial kinetic jade
For ROS Kinetic, the Jade branch of rosserial should be used.
```
git clone https://github.com/ros-drivers/rosserial.git --branch jade-devel
```

## catch2
[Catch2](https://github.com/catchorg/Catch2) is a cpp unit testing framework which supports [BDD](https://en.wikipedia.org/wiki/Behavior-driven_development).
It is a header only library which is used for unit testing.
It is recommended to be cloned into the `catkin_ws/src` directory but is not required.
```
cd ~/catkin_ws/src
git clone https://github.com/kittcar/Catch2.git
```
[Export header location to environment.](#catch2-single-include)

## Environment Variables
### rosserial library
To build for the platform, the location of the rosserial libraries needs to be exported.
```
export ROSSERIAL_LIB_PATH=$(cd path/to/libraries; pwd)
```

### catch2 single include
To build unit tests, the directory of the single header version of catch2 needs
to be exported.
```
export CATCH2_SINGLE_INCLUDE_DIR=$(cd path/to/Catch2/single_include; pwd)
```

## platformio
[Platform IO](https://platformio.org/) is a build system for embedded projects which supports our directory structure and is community friendly.
It can be installed with
```
pip install platformio
```

## Build
Ensure [environment variables have been exported](#environment-variables).
```
cd ~/catkin_ws/src/kitt_platform/balor
platformio run
```

## Build unit tests
Ensure [environment variables have been exported](#environment-variables).
```
cd ~/catkin_ws/src/kitt_platform/balor/lib/balor
mkdir build
cd build
cmake ..
make
make test
```
To see the test results in more detail, a custom build target is used.
```
make check
```

# Appendix

## Initialize Catkin Workspace
Balor is dependent on [ros](http://www.ros.org/).
The rosserial libraries must be built and then linked in.
These dependencies must be built in a [catkin workspace](http://wiki.ros.org/catkin/Tutorials/create_a_workspace).
This does not require installing all of ros.
The following can be done to set up a workspace from scratch.
The example given is for Ubuntu 14.01 (Trusty) and ROS Indigo, but has been tested on ROS Kinetic and 16.04 to work. [See note](#rosserial-kinetic-jade).

### Update keys
```
sudo sh -c "echo \"deb http://packages.ros.org/ros/ubuntu $(lsb_release -cs) main\" > /etc/apt/sources.list.d/ros-latest.list"
wget http://packages.ros.org/ros.key -O - | sudo apt-key add -
sudo apt-get -qq update
```
### Install packages
```
sudo apt-get install -y ros-indigo-catkin      \
                        python-rosdep          \
                        ros-indigo-rosbash     \
                        ros-indigo-roscpp      \
                        ros-indigo-roslib      \
                        ros-indigo-rospy       \
                        ros-indigo-common-msgs \
                        ros-indigo-topic-tools \
                        ros-indigo-tf          \
                        ros-indigo-ackermann-msgs
pip install -U rospkg catkin_pkg empy
```
### Update ROS dependencies
```
source /opt/ros/$ROS_DISTRO/setup.bash
sudo rosdep init
rosdep update
```
### Set up workspace
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
catkin_init_workspace
```
Note `catkin_ws` does not have to be used.
`kitt` or `kitt_ws` is another fine choice :D
