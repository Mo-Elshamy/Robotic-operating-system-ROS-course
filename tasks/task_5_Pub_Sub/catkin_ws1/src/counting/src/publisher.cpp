#include <ros/ros.h>
#include <std_msgs/int32.h>

int main(int argc ,char** argv){
    ros::init(argc,argv ,"topic_publisher");
    ros::NodeHandle nh;

    ros::Rate loop_rate(2);
    ros::Publisher pub = nh.advertise<std_msgs::int32>("counter",1000);

    std_msgs::int32 count;
    count.data = 100;
    while (ros::ok){
        pub.publish(count);
        ros::spainOnce();
        loop_rate.sleep();
        ++count.data;
    }
    return 0;
}