#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/NavSatFix.h"

/*
ros::Publisher gps_robot_pub = n.advertise<sensor_msgs::NavSatFix>("/robot_gps", 1000);

void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
  ROS_INFO("Longitude: [%f] ; Latitude: [%f] ; Altitude: [%f]", msg->longitude, msg->latitude, msg->altitude);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "gps_node");
  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("/gps_mobile", 1000, gpsCallback);
  ros::spin();

  return 0;
}
*/

class gps_from_mobile_to_robot
{
public:
  gps_from_mobile_to_robot()
  {
 
    pub_ = n_.advertise<sensor_msgs::NavSatFix>("/robot_gps", 1);
    sub_ = n_.subscribe("/gps_mobile", 1, &SubscribeAndPublish::gpsCallback, this);
  }

  void callback(const sensor_msgs::NavSatFix::ConstPtr& msg)
  { 	
    ROS_INFO("Longitude: [%f] ; Latitude: [%f] ; Altitude: [%f]", msg->longitude, msg->latitude, msg->altitude);
  
    sensor_msgs::NavSatFix robot_gps;
    robot_gps.longitude = msg-> longitude;
    robot_gps.latitude = msg-> latitude
    robot_gps.altitude = msg-> altitude
    pub_.publish(robot_gps);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gps_node");

  gps_from_mobile_to_robot SAPObject;

  ros::spin();

  return 0;
}
