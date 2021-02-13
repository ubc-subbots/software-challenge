#include <cstdio>
#include <cmath>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
using namespace std;

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class SineController : public rclcpp::Node
{
    rclcpp::TimerBase::SharedPtr timeCount = this->create_wall_timer(1ms, std::bind(&SineController::control, this));
    public:
        float time;
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        // Simple constructor
        SineController() : Node("Turtle Sine Controller"), time_(0)
        {
            time = 0;
            publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
            timer_ = this->create_wall_timer(10ms, std::bind(&SineController::control, this));
        }
        // Printing position of the turtle in given time
        void publish_pos(float pos1, float pos2, float pos3){
            cout<<"Time: "<< time << ", pos1: "<< pos1 <<", pos2: "<< pos2 <<", pos3: "<< pos3 << endl;
        }
    private:
        void control(){
            //This initializes the geometry signals
            auto turtle_pos = geometry_msgs::msg::Twist();
            //This sets the positions x,y,z according to the time.
            turtle_pos.linear.x = 2 * sin(M_PI*time) + 2 * cos(M_PI * time);
            turtle_pos.linear.y = 0.5;
            turtle_pos.linear.z = 0.5;
            //Publish position
            publish_pos(turtle_pos.linear.x,turtle_pos.linear.y,turtle_pos.linear.z);
            publisher_->publish(turtle_pos);
            //Increases time
            time = time + 0.05;
        }
};

int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;

  rclcpp::init(argc, argv);
  rclpp::spin(std::make_shared<SineController>());
  rclcpp::shutdown();
  return 0;
}
