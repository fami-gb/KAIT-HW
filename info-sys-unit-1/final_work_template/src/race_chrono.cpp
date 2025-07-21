#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <geometry_msgs/msg/twist_stamped.hpp>

class RaceChrono : public rclcpp::Node
{
public:
	RaceChrono() : Node("race_chrono_node")
	{
		tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
		tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
		sub_cmd_vel_ = this->create_subscription<geometry_msgs::msg::TwistStamped>(
			"cmd_vel", 10, 
			std::bind(&RaceChrono::callback_cmd_vel, this, std::placeholders::_1));
		init_flag = 0;
		x_o = 0.0;
		y_o = -2.0;
		state = 0;
		RCLCPP_INFO(this->get_logger(), "Waiting for start...");
	}

private:
	void callback_cmd_vel(const geometry_msgs::msg::TwistStamped::SharedPtr msg)
	{
		if(init_flag == 0) {
			init_stamp = rclcpp::Time(msg->header.stamp);
		}

		auto dt = rclcpp::Time(msg->header.stamp) - init_stamp;
		
		if(init_flag == 0) {
			init_flag = 1;
			RCLCPP_INFO(this->get_logger(), "%f[sec]: START", dt.seconds());
		}

		geometry_msgs::msg::TransformStamped t;
		try {
			t = tf_buffer_->lookupTransform("odom", "base_footprint", tf2::TimePointZero);
		}
		catch (const tf2::TransformException& ex)
		{
			//RCLCPP_WARN(rclcpp::get_logger("TransformException"), "%s", ex.what());
			return;
		}
		
		float x = t.transform.translation.x;
		float y = t.transform.translation.y;
				
		//RCLCPP_INFO(this->get_logger(), "%lf:  %f %f", dt.seconds(), x, y);	
		
		if(fabs(x) < 1.0 && fabs(y) < 1.0) {
			RCLCPP_INFO(this->get_logger(), "%f[sec]: Off course.", dt.seconds());
			rclcpp::shutdown();
		}
		if(crossing_start_line(x, y, x_o, y_o))
		{
			if(state%2 == 1) {
				state ++;
				if(state < 5) {
					RCLCPP_INFO(this->get_logger(), "%f[sec]: LAP%d", dt.seconds(), state/2);
				}
				else {
					RCLCPP_INFO(this->get_logger(), "%f[sec]: GOAL", dt.seconds());
					rclcpp::shutdown();
				}
			}
		}
		if(crossing_opposite_line(x, y, x_o, y_o))
		{
			if(state%2 == 0) state ++;
			//RCLCPP_INFO(this->get_logger(), "state %d", state);
		}
		x_o = x;
		y_o = y;
	}

	bool crossing_start_line(float current_x, float current_y, float last_x, float last_y)
	{
		float start_ya = -1.0;
		float start_yb = -3.0;
		
		if(last_x < 0.0 && current_x > 0.0
		  && last_y > start_yb && last_y < start_ya
		  && current_y > start_yb && current_y < start_ya) {
			if(current_x * last_x < 0.0) return true;
		}
		
		return false;
	}

	bool crossing_opposite_line(float current_x, float current_y, float last_x, float last_y)
	{
		float start_ya = 1.0;
		float start_yb = 3.0;
		
		if(last_x > 0.0 && current_x < 0.0
		  && last_y < start_yb && last_y > start_ya
		  && current_y < start_yb && current_y > start_ya) {
			if(current_x * last_x < 0.0) return true;
		}
		
		return false;
	}

	std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
	std::shared_ptr<tf2_ros::TransformListener> tf_listener_{nullptr};
	rclcpp::Subscription<geometry_msgs::msg::TwistStamped>::SharedPtr sub_cmd_vel_;
	rclcpp::Time init_stamp;
	int init_flag;
	float x_o, y_o;
	int state;
};

int main(int argc, char** argv)
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<RaceChrono>());
	rclcpp::shutdown();
	return 0;
}
