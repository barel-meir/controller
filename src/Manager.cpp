//
// Created by barel on 10/6/23.
//

#include <chrono>
#include <memory>

#include "../include/controller/Manager.h"
using namespace std::chrono_literals;

Manager::Manager(): Node("rc_controller"), m_count_(0){
    initCallbacks();
    initTimers();
    initPublishers();
}

void Manager::initTimers(){
    m_timer_ = this->create_wall_timer(500ms, [this] { timer_callback(); });
}

void Manager::initCallbacks(){
    auto subscriber = create_subscription<mavros_msgs::msg::State>(
            "/mavros/state",
            10,
            [this](const mavros_msgs::msg::State::SharedPtr& msg) {
                RCLCPP_INFO(get_logger(), "Mavros State: %s", msg->mode.c_str());
                m_isArmed_ = msg->armed;
            }
    );
}

void Manager::initPublishers() {
    m_count_publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
}

void Manager::timer_callback() {
    auto message = std_msgs::msg::String();
    message.data = "barelllll Hello, world! " + std::to_string(m_count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    m_count_publisher_->publish(message);
}