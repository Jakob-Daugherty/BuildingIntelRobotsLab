//listener

# include "ros/ros.h"
# include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main (int argc, char **argv)
{
ros::init(argc, argv, "listener");
ros::start();
ROS_INFO_STREAM("Listener Start");
ros::NodeHandle chat;
ros::Subscriber sub = chat.subscribe("chatter", 1000, chatterCallback);
ros::spin();
ros::shutdown();
return 0;
}
