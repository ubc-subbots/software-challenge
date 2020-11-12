#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>


using namespace std::chrono_literals;


class SinePublisher : public rclcpp::Node
{
    private:
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr sine_pub;
        rclcpp::TimerBase::SharedPtr timer_;
        size_t count_;
        float time = 0.0;

        void timer_callback()
        {
            time += 0.001;
            geometry_msgs::msg::Twist motion;
            motion.linear.x = 0.5;
            motion.linear.y = sin(2 * M_PI * time);
            motion.linear.z = 0.4;
            //RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", motion.angular.z);
            sine_pub->publish(motion);
        }

    public:
        SinePublisher()
        : Node("sine_publisher"), count_(0)
        {
            sine_pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 1);
            timer_ = this->create_wall_timer(
            1ms, std::bind(&SinePublisher::timer_callback, this));
        }

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SinePublisher>());
    rclcpp::shutdown();
    return 0;
}