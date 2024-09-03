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

#ifndef ALL_MPA_INTERFACES
#define ALL_MPA_INTERFACES

#include "voxl_mpa_to_ros2/interfaces/generic_interface.h"
#include "voxl_mpa_to_ros2/interfaces/camera_interface.h"
#include "voxl_mpa_to_ros2/interfaces/imu_interface.h"
#include "voxl_mpa_to_ros2/interfaces/pose_vel_6dof_interface.h"
#include "voxl_mpa_to_ros2/interfaces/point_cloud_interface.h"
#include "voxl_mpa_to_ros2/interfaces/qvio_interface.h"
#include "voxl_mpa_to_ros2/interfaces/ai_detection_interface.h"

enum InterfaceType {
    INT_NOT_SUPPORTED=-2,
    INT_NONE=-1,
    INT_CAMERA,
    INT_STEREO,
    INT_IMU,
    INT_VIO,
    INT_PC,
    INT_6DOF,
    INT_AI
};

#endif
