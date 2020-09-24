#include <cstdio>
#include <cmath>
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class solution : public rclcpp::Node
{

  public:
    solution() : Node("solution")
    {
      time_ = 0;
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
      timer_ = this->create_wall_timer(10ms, std::bind(&solution::sine_motion, this));
    }

  private:
    void sine_motion()
    {
      auto signal = geometry_msgs::msg::Twist();
      signal.linear.x = 1;
      //signal.angular.z = cos(time_)/sqrt(pow(sin(time_),2)+pow(time_,2));
      signal.angular.z = -sin(time_);
      time_ += 0.01;
      RCLCPP_INFO(this->get_logger(), "Moving turtle with linear speed: '%f' and angular speed: '%f'", signal.linear.x, signal.angular.z);
      publisher_->publish(signal);
    }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  float time_;


};


  int main(int argc, char ** argv)
  {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<solution>());
    rclcpp::shutdown();
    return 0;
  }

