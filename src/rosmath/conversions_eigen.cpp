#include "rosmath/conversions_eigen.h"
#include "rosmath/conversions.h"

namespace rosmath {

// POINTS

void convert(   const geometry_msgs::Point& from, 
                Eigen::Vector3d& to)
{
    to.x() = from.x;
    to.y() = from.y;
    to.z() = from.z;
}

void convert(   const Eigen::Vector3d& from,
                geometry_msgs::Point& to)
{
    to.x = from.x();
    to.y = from.y();
    to.z = from.z();
}

void convert(   const geometry_msgs::Point32& from, 
                Eigen::Vector3f& to)
{
    to.x() = from.x;
    to.y() = from.y;
    to.z() = from.z;
}

void convert(   const Eigen::Vector3f& from,
                geometry_msgs::Point32& to)
{
    to.x = from.x();
    to.y = from.y();
    to.z = from.z();
}

void convert(   const geometry_msgs::Vector3& from, 
                Eigen::Vector3d& to)
{
    to.x() = from.x;
    to.y() = from.y;
    to.z() = from.z;
}

void convert(   const Eigen::Vector3d& from,
                geometry_msgs::Vector3& to)
{
    to.x = from.x();
    to.y = from.y();
    to.z = from.z();
}

// ROATATIONS
void convert(   const geometry_msgs::Quaternion& from, 
                Eigen::Quaterniond& to)
{
    to = Eigen::Quaterniond(from.w, from.x, from.y, from.z);
}

void convert(   const Eigen::Quaterniond& from,
                geometry_msgs::Quaternion& to)
{
    to.x = from.x();
    to.y = from.y();
    to.z = from.z();
    to.w = from.w();
}

// TRANSFORMATIONS

void convert(   const geometry_msgs::Transform& from,
                Eigen::Affine3d& to)
{
    Eigen::Vector3d translation;
    convert(from.translation, translation);
    Eigen::Quaterniond rotation;
    convert(from.rotation, rotation);
    to.setIdentity();
    to.linear() = rotation.matrix();
    to.translation() = translation;
}

void convert(   const Eigen::Affine3d& from,
                geometry_msgs::Transform& to)
{
    Eigen::Quaterniond q(from.rotation());
    convert(q, to.rotation);
    convert(from.translation(), to.translation);
}

void convert(   const geometry_msgs::Pose& from,
                Eigen::Affine3d& to)
{
    Eigen::Vector3d translation;
    convert(from.position, translation);
    Eigen::Quaterniond rotation;
    convert(from.orientation, rotation);
    to.setIdentity();
    to.linear() = rotation.matrix();
    to.translation() = translation;
}

void convert(   const Eigen::Affine3d& from,
                geometry_msgs::Pose& to)
{
    Eigen::Quaterniond q(from.rotation());
    convert(q, to.orientation);
    convert(from.translation(), to.position);
}

// OPERATORS

// POINTS

Eigen::Vector3d& operator<<=(
    Eigen::Vector3d& to,
    const geometry_msgs::Point& from)
{
    convert(from, to);
    return to;
}

geometry_msgs::Point& operator<<=(
    geometry_msgs::Point& to,
    const Eigen::Vector3d& from)
{
    convert(from, to);
    return to;
}

Eigen::Vector3f& operator<<=(
    Eigen::Vector3f& to,
    const geometry_msgs::Point32& from)
{
    convert(from, to);
    return to;
}

geometry_msgs::Point32& operator<<=(
    geometry_msgs::Point32& to,
    const Eigen::Vector3f& from)
{
    convert(from, to);
    return to;
}

Eigen::Vector3d& operator<<=(
    Eigen::Vector3d& to,
    const geometry_msgs::Vector3& from)
{
    convert(from, to);
    return to;
}

geometry_msgs::Vector3& operator<<=(
    geometry_msgs::Vector3& to,
    const Eigen::Vector3d& from)
{
    convert(from, to);
    return to;
}

// ROTATIONS

Eigen::Quaterniond& operator<<=(
    Eigen::Quaterniond& to,
    const geometry_msgs::Quaternion& from)
{
    convert(from, to);
    return to;
}

geometry_msgs::Quaternion& operator<<=(
    geometry_msgs::Quaternion& to,
    const Eigen::Quaterniond& from)
{
    convert(from, to);
    return to;
}

// TRANSFORMATIONS

Eigen::Affine3d& operator<<=(
    Eigen::Affine3d& to, 
    const geometry_msgs::Transform& from)
{
    convert(from, to);
    return to;
}

geometry_msgs::Transform& operator<<=(
    geometry_msgs::Transform& to, 
    const Eigen::Affine3d& from)
{
    convert(from, to);
    return to;
}

Eigen::Affine3d& operator<<=(   Eigen::Affine3d& to, 
                                const geometry_msgs::Pose& from)
{
    convert(from, to);
    return to;
}

geometry_msgs::Pose& operator<<=(  geometry_msgs::Pose& to, 
                                    const Eigen::Affine3d& from)
{
    convert(from, to);
    return to;
}


} // namespace rosmath