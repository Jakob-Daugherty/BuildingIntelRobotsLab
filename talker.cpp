//talker.cpp 
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv) 
{
	ros::init(argc,argv,"talker");
	ros::start();
	ROS_INFO_STREAM("Talker Start");
	ros::NodeHandle chat;
	ros::Publisher chatter_pub = chat.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(1);
	int count = 0;
	loop_rate.sleep();
	while(ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss << "Hello world" << count;
		msg.data = ss.str();
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
	ros::shutdown();
	return 0;

}
