#include <cstdio>
#include <ctime>
#include <math.h>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/msg/pose.hpp>

using std::placeholders::_1;
using namespace std::chrono_literals;

class Solution : public rclcpp::Node
{
  public:
  Solution() : Node("solution"), time_(0)
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
    timer_ = this->create_wall_timer(10ms, std::bind(&Solution::timer_callback, this));
    subscription_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&Solution::turtle_callback, this, _1));
  }

  private:

  void turtle_callback(const turtlesim::msg::Pose::SharedPtr msg) const
  {
  }

  void timer_callback(){
    auto new_msg = geometry_msgs::msg::Twist();
    new_msg.linear.x = 20;
    new_msg.angular.y = 20*sin(double(time_)/100);
    new_msg.angular.z = 20*cos(double(time_)/100);
    publisher_->publish(new_msg);
  }
  double lin_vel_ = 5.0;
  int time_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Solution>());
  rclcpp::shutdown();
  return 0;
}
