
#include "rclcpp/rclcpp.hpp"
#include "controller/Manager.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Manager>());
  rclcpp::shutdown();
  return 0;
}
