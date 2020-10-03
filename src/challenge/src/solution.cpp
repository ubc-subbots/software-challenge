
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/duration.hpp"
#include "rcl/time.h"
#include "rclcpp/visibility_control.hpp"

#include "rclcpp/function_traits.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/scope_exit.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp/utilities.hpp"

#include <math.h>
//#include <cstdio>
#include <cmath>

#define PI 3.14159
#define PERIOD_FACTOR 10.0
using namespace std::literals::chrono_literals;

enum action
{
  FORWARD,
  REVERSE,
  STOPPED,
};


class Turtle_motion : public rclcpp::Node
{
  int count = 0;

  float current_time = 0;
  //rclcpp::Time::Time
  // create the timer using TimerBase
  rclcpp::TimerBase::SharedPtr timeCount = this->create_wall_timer(1ms, std::bind(&Turtle_motion::sinusoidal_trajectory, this));
  // identify the publisher
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr send_state = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 100);

  public:
    // empty Turtle_motion node constructorS
    Turtle_motion() : Node("in_motion"){}

    void printStats(float x, float y, float z){ // print out time elapsed, and linear position
      RCLCPP_INFO(this->get_logger(), "xx time: %.0f s, (x, y, z) = (%.2f, %.2f, %.2f)", current_time, 
      x, y, z);
    }

    // main control for the trajectory

    void control(){
      // incase it runs for more than 20 seconds
      if(current_time <= 3.0)
        sinusoidal_trajectory();
      else
        stop();
    } 
  private:
    void sinusoidal_trajectory()
    {

      auto turtle = geometry_msgs::msg::Twist(); // initialize geometry_msgs signal
      current_time += 0.001;


      turtle.linear.y = 2 * cos(2 * PI * current_time / PERIOD_FACTOR);
      turtle.linear.x = 0.3;
      turtle.linear.z = 0.4;

      send_state->publish(turtle);


      // should only update the log every second!
      count++;
      if ( count == 1000){
        printStats(turtle.linear.x, turtle.linear.y, turtle.linear.z);
        count = 0;
      }
    }

    void stop(){
      current_time = current_time;
    }

};


int main(int argc, char ** argv)
{ 
    rclcpp::init(argc, argv); // initialize rclcpp

    auto node = std::make_shared<Turtle_motion>();
      // initialization 
    // repeatly run the turtle sim motion

    // start the moving command
    rclcpp::spin(node);
    return 0;
}
