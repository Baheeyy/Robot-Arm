# Robot-Arm
This project was created as a part of "Industiral Robotics" course 

In this project i used moveit and rosserial to control and simulate a 4DOF robot arm

## Running the code

Firstly you need to build the catkin workspace <br>
```
cd catkin_wd
catkin_make
```

To start Rviz and begin simulating:<br>
```
roslaunch new_robot_config demo.launch 
```

To initialize serial connection with microcontroller:<br>
```
rosrun rosserial_arduino serial_node.py _port:=/dev/{PORT}
```
