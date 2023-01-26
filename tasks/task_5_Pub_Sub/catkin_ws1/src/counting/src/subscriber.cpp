#include <ros/ros.h>
#include <std_msgs/int32.h>

void countercallback(const std_msgs::int32::ConstPtr& msg){
    ROS_INFO("%d",msg->data);
}
int main(int argc,char** argv){
    ros::init(argc,argv,"topic_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("counter",1000,countercallback);
    ros::spain();
    return 0;
}