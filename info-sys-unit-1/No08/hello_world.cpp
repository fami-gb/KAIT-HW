#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("hello_world_node");
    rclcpp::WallRate loop(1);
    
    while (rclcpp::ok()) {
        RCLCPP_INFO (rclcpp::get_logger("loop"), "Hello World");
        RCLCPP_DEBUG (rclcpp::get_logger("loop"), "This is Debug Text");
        RCLCPP_WARN (rclcpp::get_logger("loop"), "Warning");
        RCLCPP_ERROR (rclcpp::get_logger("loop"), "Error has occurred");
        RCLCPP_FATAL (rclcpp::get_logger("loop"), "Fatal error has occurred");
        loop.sleep();
    }

    rclcpp::shutdown();
    return 0;
}