#include <Servo.h> 
#include <ros.h>
#include <sensor_msgs/JointState.h>


ros::NodeHandle  nh;

Servo servo0;
Servo servo1;
Servo servo2;
double targets[3] = {90,90,90};
double positions[3] = {90,90,90};

void servo_cb( const sensor_msgs::JointState& cmd_msg){
  //set servo angle, should be from 0-180  
  servo0.write(radiansToDegrees(cmd_msg.position[0]));
  servo1.write(radiansToDegrees(cmd_msg.position[1]));
  servo2.write(radiansToDegrees(cmd_msg.position[2]));
  
}


ros::Subscriber<sensor_msgs::JointState> sub("joint_states", servo_cb);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  
  servo0.attach(9);
  servo1.attach(10);
  servo2.attach(11); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}
double radiansToDegrees(float position_radians)
{
  
  
  
  return position_radians * 57.2958;
  
}