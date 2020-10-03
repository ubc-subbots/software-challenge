#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class TurtlePublisher : public rclcpp::Node
{
  public:
    TurtlePublisher()
    : Node("turtle_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&TurtlePublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      double time = rclcpp::Node::now().nanoseconds() / 1e9;
      geometry_msgs::msg::Twist message;
      message.linear.x = sqrt(sin(time) * sin(time) + 1) * 0.2;
      message.angular.z = cos(time) / (sin(time) * sin(time) + 1);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%f', '%f'", message.linear.x, message.angular.z);
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    size_t count_;
  };

  int main(int argc, char * argv[])
  {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlePublisher>());
    rclcpp::shutdown();
    return 0;
  }
