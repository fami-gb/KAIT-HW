#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>

void callback_pose (const turtlesim::msg::Pose::SharedPtr msg) {
    RCLCPP_INFO (rclcpp::get_logger("callback"), "x:%f y:%f th:%f",
        msg->x, msg->y, msg->theta*360.0/M_PI);
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("turtlesim_pose_node");
    auto sub_pose = node->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 1, callback_pose);

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}