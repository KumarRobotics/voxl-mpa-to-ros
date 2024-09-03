/*******************************************************************************
 * Copyright 2021 ModalAI Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * 4. The Software is used solely in conjunction with devices provided by
 *    ModalAI Inc.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
#include <modal_pipe.h>
#include "voxl_mpa_to_ros2/interfaces/qvio_interface.h"
#include "voxl_mpa_to_ros2/utils/common_utils.h"
#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <px4_ros_com/frame_transforms.h>

static void _helper_cb(
    __attribute__((unused))int ch, 
                           char* data, 
                           int bytes, 
                           void* context);

QVIOInterface::QVIOInterface(
    rclcpp::Node::SharedPtr nh,
    const char *    name) :
    GenericInterface(nh, name)
{

    pipe_client_set_simple_helper_cb(m_channel, _helper_cb, this);

    if(pipe_client_open(m_channel, name, PIPE_CLIENT_NAME,
                EN_PIPE_CLIENT_SIMPLE_HELPER | CLIENT_FLAG_START_PAUSED,
                VIO_RECOMMENDED_READ_BUF_SIZE)){
        pipe_client_close(m_channel);//Make sure we unclaim the channel
        throw -1;
    }

}

void QVIOInterface::AdvertiseTopics(){

    char topicName[64];

    sprintf(topicName, "%s", m_pipeName);
    // pose_pub_ = m_rosNodeHandle->create_publisher<geometry_msgs::msg::PoseStamped>
    //     (topicName, rclcpp::SensorDataQoS());

    odom_pub_ = m_rosNodeHandle->create_publisher<nav_msgs::msg::Odometry>
        (topicName, rclcpp::SensorDataQoS());

    m_state = ST_AD;

}

void QVIOInterface::StopAdvertising(){

    // pose_pub_.reset();
    odom_pub_.reset();

    m_state = ST_CLEAN;

}

int QVIOInterface::GetNumClients(){
    // return pose_pub_->get_subscription_count() + odom_pub_->get_subscription_count();
    return odom_pub_->get_subscription_count();
}

// called when the simple helper has data for us
static void _helper_cb(__attribute__((unused))int ch, char* data, int bytes, void* context)
{

    // validate that the data makes sense
    int n_packets;
    vio_data_t* data_array = pipe_validate_vio_data_t(data, bytes, &n_packets);
    if(data_array == NULL) return;

    QVIOInterface *interface = (QVIOInterface *) context;
    if(interface->GetState() != ST_RUNNING) return;
    
    geometry_msgs::msg::PoseStamped& poseMsg = interface->GetPoseMsg();
    nav_msgs::msg::Odometry& odomMsg = interface->GetOdomMsg();

    for(int i=0;i<n_packets;i++){
        vio_data_t data = data_array[i];

        // poseMsg.header.stamp = _clock_monotonic_to_ros_time(interface->getNodeHandle(), data.timestamp_ns);
        odomMsg.header.stamp = _clock_monotonic_to_ros_time(interface->getNodeHandle(), data.timestamp_ns);

        // extract quaternion from {imu w.r.t vio} rotation matrix
        tf2::Matrix3x3 R(
            data.R_imu_to_vio[0][0],
            data.R_imu_to_vio[0][1],
            data.R_imu_to_vio[0][2],
            data.R_imu_to_vio[1][0],
            data.R_imu_to_vio[1][1],
            data.R_imu_to_vio[1][2],
            data.R_imu_to_vio[2][0],
            data.R_imu_to_vio[2][1],
            data.R_imu_to_vio[2][2]);
        tf2::Quaternion q;
        R.getRotation(q);

        poseMsg.pose.position.x = data.T_imu_wrt_vio[0];
        poseMsg.pose.position.y = data.T_imu_wrt_vio[1];
        poseMsg.pose.position.z = data.T_imu_wrt_vio[2];
        poseMsg.pose.orientation.x = q.getX();
        poseMsg.pose.orientation.y = q.getY();
        poseMsg.pose.orientation.z = q.getZ();
        poseMsg.pose.orientation.w = q.getW();
        // interface->pose_pub_->publish(poseMsg);

        odomMsg.pose.pose = poseMsg.pose;
        odomMsg.twist.twist.linear.x = data.vel_imu_wrt_vio[0];
        odomMsg.twist.twist.linear.y = data.vel_imu_wrt_vio[1];
        odomMsg.twist.twist.linear.z = data.vel_imu_wrt_vio[2];
        odomMsg.twist.twist.angular.x = data.imu_angular_vel[0];
        odomMsg.twist.twist.angular.y = data.imu_angular_vel[1];
        odomMsg.twist.twist.angular.z = data.imu_angular_vel[2];

        int triangle_sequence = 0;
        int counter = 0;

        for (int i = 6; i > 1; i--) { 
            // Set triangle sequence:
            if (i == 6) {
                triangle_sequence = 0;
            } else if(i == 5) {
                triangle_sequence = 1;
            } else if(i == 4) {
                triangle_sequence = 3;
            } else if(i == 3) {
                triangle_sequence = 6;
            } else if(i == 2) {
                triangle_sequence = 10;
            }
            for(int j = 0; j < i; j++) {

                // ROS_INFO_STREAM("i : " << i);
                // ROS_INFO_STREAM("Five sequence : " << j * 5);
                // ROS_INFO_STREAM("Triangle sequence : " << triangle_sequence);
                // ROS_INFO_STREAM("Counter: " << counter);
            int first_index = counter + triangle_sequence;
            int second_index = first_index + j * 5;
                // ROS_INFO_STREAM("first_index : " << first_index);
                // ROS_INFO_STREAM("second_index : " << second_index);
                odomMsg.pose.covariance[first_index] =   double(data.pose_covariance[counter]);
                odomMsg.pose.covariance[second_index] =  double(data.pose_covariance[counter]);
                odomMsg.twist.covariance[first_index] =  double(data.velocity_covariance[counter]);
                odomMsg.twist.covariance[second_index] = double(data.velocity_covariance[counter]);

            counter++;	

            }

        }
        odomMsg.pose.covariance[35] =  double(data.pose_covariance[20]);
        odomMsg.twist.covariance[35] = double(data.velocity_covariance[20]);

        interface->odom_pub_->publish(odomMsg);
    }
}
