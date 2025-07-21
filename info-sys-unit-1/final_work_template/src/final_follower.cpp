#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <bits/stdc++.h> // M_PI

using namespace std;

sensor_msgs::msg::LaserScan::SharedPtr latest_scan;

void callback_scan (const sensor_msgs::msg::LaserScan::SharedPtr msg) {
    latest_scan = msg;
}

int main (int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("onoff_follower_node");
    auto sub_scan = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 1, callback_scan);
    auto pub_cmd_vel = node->create_publisher<geometry_msgs::msg::TwistStamped>("cmd_vel", 1);
    rclcpp::WallRate loop(10);

    // 時間計測用
    printf("Are you READY?\nPlease push enter key.");
    getchar();
    
    while (rclcpp::ok()) {
        // キューに溜まったコールバックを実行
        rclcpp::spin_some(node); // LiDARからデータを取得

        if (latest_scan) {
	    // 0°方向の測定値を表示
        RCLCPP_INFO(rclcpp::get_logger("loop"), "%f [m]", latest_scan->ranges[270]);

	    // メッセージの作成
        auto msg_cmd_vel = geometry_msgs::msg::TwistStamped();
        msg_cmd_vel.header.stamp = node->get_clock()->now();
        msg_cmd_vel.header.frame_id = "base_footprint";
    
	    // x°での距離
        double d_270 = latest_scan->ranges[270];
        double d_315 = latest_scan->ranges[315]*sin(45*M_PI/180.0);

        msg_cmd_vel.twist.linear.x = 0.3
        msg_cmd_vel.twist.angular.z = 2.0*((0.5 - d_270) + (0.5 - d_315));

	    // メッセージの送信
        pub_cmd_vel->publish(msg_cmd_vel);
        }
        loop.sleep();
    }
    rclcpp::shutdown();
    return 0;
}
