/*******************************************************************************
 * Copyright 2020 ModalAI Inc.
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

#ifndef CAMERA_MPA_INTERFACE
#define CAMERA_MPA_INTERFACE

#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <image_transport/image_transport.h>
#include <image_transport/publisher.h>
#include <image_transport/camera_publisher.h>

#include "generic_interface.h"

class CameraInterface: public GenericInterface
{
public:
    CameraInterface(ros::NodeHandle rosNodeHandle,
                    ros::NodeHandle rosNodeHandleParams,
                    const char*     camName);

    ~CameraInterface() { };

    int  GetNumClients();
    void AdvertiseTopics();
    void StopAdvertising();

    sensor_msgs::Image& GetImageMsg(){
        return m_imageMsg;
    }


    image_transport::Publisher& GetPublisher(){
        return m_rosImagePublisher;
    }

    ros::Publisher& GetCameraInfoPublisher(){
        return m_cameraInfoPublisher;
    }

    sensor_msgs::CameraInfo& GetCameraInfoMsg(){
        // load lens params from EEPROM
        double fx   = 111.094;
        double fy   = 111.094;
        double rad0 = -0.205357;
        double rad1 = 0.0361391;
        double rad2 = 0;

        // when flipping the image, tangential distortion must be flipped
        // and primciple point reflected over the center of the image
        double px, py, tan0, tan1;
        px   = 110.916;
        py   = 87.1842;
        tan0 = -0.00138012;
        tan1 = 0.000235194;

        // distortion parameters. 5-param radtan model identical to factory sensor cal
        m_cameraInfoMsg.distortion_model = "plumb_bob";
        m_cameraInfoMsg.D.resize(5);
        m_cameraInfoMsg.D[0] = rad0;
        m_cameraInfoMsg.D[1] = rad1;
        m_cameraInfoMsg.D[2] = tan0;
        m_cameraInfoMsg.D[3] = tan1;
        m_cameraInfoMsg.D[4] = rad2;

        // Intrinsic camera matrix for the raw (distorted) images.
        m_cameraInfoMsg.K[0] = fx;
        m_cameraInfoMsg.K[1] = 0;
        m_cameraInfoMsg.K[2] = px;
        m_cameraInfoMsg.K[3] = 0;
        m_cameraInfoMsg.K[4] = fy;
        m_cameraInfoMsg.K[5] = py;
        m_cameraInfoMsg.K[6] = 0;
        m_cameraInfoMsg.K[7] = 0;
        m_cameraInfoMsg.K[8] = 1;

        // Rectification matrix STEREO CAM ONLY, leave as identity for monocular
        m_cameraInfoMsg.R[0] = 1;
        m_cameraInfoMsg.R[1] = 0;
        m_cameraInfoMsg.R[2] = 0;
        m_cameraInfoMsg.R[3] = 0;
        m_cameraInfoMsg.R[4] = 1;
        m_cameraInfoMsg.R[5] = 0;
        m_cameraInfoMsg.R[6] = 0;
        m_cameraInfoMsg.R[7] = 0;
        m_cameraInfoMsg.R[8] = 1;

        // Projection matrix
        m_cameraInfoMsg.P[0] = fx;
        m_cameraInfoMsg.P[1] = 0;
        m_cameraInfoMsg.P[2] = px;
        m_cameraInfoMsg.P[3] = 0;  // Tx for stereo offset
        m_cameraInfoMsg.P[4] = 0;
        m_cameraInfoMsg.P[5] = fy;
        m_cameraInfoMsg.P[6] = py;
        m_cameraInfoMsg.P[7] = 0;  // Ty for stereo offset
        m_cameraInfoMsg.P[8] = 0;
        m_cameraInfoMsg.P[9] = 0;
        m_cameraInfoMsg.P[10] = 1;
        m_cameraInfoMsg.P[11] = 0;

        return m_cameraInfoMsg;
    }

private:

    sensor_msgs::Image                     m_imageMsg;                   ///< Image message
    sensor_msgs::CameraInfo                m_cameraInfoMsg;              ///< Camera Info message
    image_transport::Publisher             m_rosImagePublisher;          ///< Image publisher
    ros::Publisher                         m_cameraInfoPublisher;
};
#endif
