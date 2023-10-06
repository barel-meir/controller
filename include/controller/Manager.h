//
// Created by barel on 10/6/23.
//

#ifndef BUILD_MANAGER_H
#define BUILD_MANAGER_H

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "/opt/ros/galactic/include/mavros_msgs/msg/state.hpp"

class Manager : public rclcpp::Node{
public:
    Manager();

private:
    void initCallbacks();
    void initPublishers();
    void initTimers();

    void timer_callback();

    rclcpp::TimerBase::SharedPtr m_timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_count_publisher_;
    size_t m_count_;
    std::atomic<bool> m_isArmed_ = false;

};


#endif //BUILD_MANAGER_H
