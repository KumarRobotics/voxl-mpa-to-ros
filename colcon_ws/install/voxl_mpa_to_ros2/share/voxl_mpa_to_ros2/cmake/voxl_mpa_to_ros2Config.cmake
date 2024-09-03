# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_voxl_mpa_to_ros2_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED voxl_mpa_to_ros2_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(voxl_mpa_to_ros2_FOUND FALSE)
  elseif(NOT voxl_mpa_to_ros2_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(voxl_mpa_to_ros2_FOUND FALSE)
  endif()
  return()
endif()
set(_voxl_mpa_to_ros2_CONFIG_INCLUDED TRUE)

# output package information
if(NOT voxl_mpa_to_ros2_FIND_QUIETLY)
  message(STATUS "Found voxl_mpa_to_ros2: 0.0.4 (${voxl_mpa_to_ros2_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'voxl_mpa_to_ros2' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${voxl_mpa_to_ros2_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(voxl_mpa_to_ros2_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${voxl_mpa_to_ros2_DIR}/${_extra}")
endforeach()
