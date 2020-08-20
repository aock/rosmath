#ifndef ROSMATH_CONVERSIONS_EIGEN_H
#define ROSMATH_CONVERSIONS_EIGEN_H

#include <Eigen/Dense>
#include "conversions.h"

namespace rosmath {

///////////////////////////////////////////
//
// CONVERSION FUNCTIONS
//
/////////////

// POINTS
void convert(   const geometry_msgs::Point& from, 
                Eigen::Vector3d& to);

void convert(   const Eigen::Vector3d& from,
                geometry_msgs::Point& to);

void convert(   const geometry_msgs::Point32& from, 
                Eigen::Vector3f& to);

void convert(   const Eigen::Vector3f& from,
                geometry_msgs::Point32& to);

void convert(   const geometry_msgs::Vector3& from, 
                Eigen::Vector3d& to);

void convert(   const Eigen::Vector3d& from,
                geometry_msgs::Vector3& to);

// ROTATIONS
void convert(   const geometry_msgs::Quaternion& from, 
                Eigen::Quaterniond& to);

void convert(   const Eigen::Quaterniond& from,
                geometry_msgs::Quaternion& to);


// TRANSFORMATIONS
void convert(   const geometry_msgs::Transform& from,
                Eigen::Affine3d& to);

void convert(   const Eigen::Affine3d& from,
                geometry_msgs::Transform& to);

void convert(   const geometry_msgs::Pose& from,
                Eigen::Affine3d& to);

void convert(   const Eigen::Affine3d& from,
                geometry_msgs::Pose& to);

void convert(   const geometry_msgs::Pose& from,
                geometry_msgs::Transform& to);

void convert(   const geometry_msgs::Transform& from,
                geometry_msgs::Pose& to);


///////////////////////////////////////////
//
// CONVERSION OPERATOR: 
// <<= for first convert than assign
//
/////////////

// POINTS
Eigen::Vector3d& operator<<=(   Eigen::Vector3d& to,
                                const geometry_msgs::Point& from);

geometry_msgs::Point& operator<<=(  geometry_msgs::Point& to,
                                    const Eigen::Vector3d& from);

Eigen::Vector3f& operator<<=(   Eigen::Vector3f& to,
                                const geometry_msgs::Point32& from);

geometry_msgs::Point32& operator<<=(    geometry_msgs::Point32& to,
                                        const Eigen::Vector3f& from);

Eigen::Vector3d& operator<<=(   Eigen::Vector3d& to,
                                const geometry_msgs::Vector3& from);

geometry_msgs::Vector3& operator<<=(    geometry_msgs::Vector3& to,
                                        const Eigen::Vector3d& from);

// ROTATIONS
Eigen::Quaterniond& operator<<=(    Eigen::Quaterniond& to,
                                    const geometry_msgs::Quaternion& from);

geometry_msgs::Quaternion& operator<<=( geometry_msgs::Quaternion& to,
                                        const Eigen::Quaterniond& from);

// TRANSFORMATIONS
Eigen::Affine3d& operator<<=(   Eigen::Affine3d& to, 
                                const geometry_msgs::Transform& from);

geometry_msgs::Transform& operator<<=(  geometry_msgs::Transform& to, 
                                        const Eigen::Affine3d& from);


} // namespace rosmath

#endif // ROSMATH_CONVERSIONS_EIGEN_H