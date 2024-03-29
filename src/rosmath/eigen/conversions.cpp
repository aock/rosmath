#include "Eigen/Dense"

#include "rosmath/eigen/conversions.h"
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

void convert(   const geometry_msgs::Point& from, 
                Eigen::Vector3f& to)
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

void convert(   const Eigen::Vector3f& from,
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

void convert(   const geometry_msgs::Point32& from, 
                Eigen::Vector3d& to)
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

void convert(   const Eigen::Vector3d& from,
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

void convert(   const geometry_msgs::Vector3& from, 
                Eigen::Vector3f& to)
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

void convert(   const Eigen::Vector3f& from,
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
    to.x() = from.x;
    to.y() = from.y;
    to.z() = from.z;
    to.w() = from.w;
}

void convert(   const geometry_msgs::Quaternion& from, 
                Eigen::Quaternionf& to)
{
    to.x() = from.x;
    to.y() = from.y;
    to.z() = from.z;
    to.w() = from.w;
}

void convert(   const Eigen::Quaterniond& from,
                geometry_msgs::Quaternion& to)
{
    to.x = from.x();
    to.y = from.y();
    to.z = from.z();
    to.w = from.w();
}

void convert(   const Eigen::Quaternionf& from,
                geometry_msgs::Quaternion& to)
{
    to.x = from.x();
    to.y = from.y();
    to.z = from.z();
    to.w = from.w();
}

void convert(   const geometry_msgs::Quaternion& from,
                Eigen::Matrix3d& to)
{
    Eigen::Quaterniond qeig;
    convert(from, qeig);
    to = qeig.toRotationMatrix();
}

void convert(   const geometry_msgs::Quaternion& from,
                Eigen::Matrix3f& to)
{
    Eigen::Quaternionf qeig;
    convert(from, qeig);
    to = qeig.toRotationMatrix();
}

void convert(   const Eigen::Matrix3d& from,
                geometry_msgs::Quaternion& to)
{
    Eigen::Quaterniond q(from);
    convert(q, to);
}

void convert(   const Eigen::Matrix3f& from,
                geometry_msgs::Quaternion& to)
{
    Eigen::Quaternionf q(from);
    convert(q, to);
}

void convert(   const Eigen::Matrix3d& from, 
                Eigen::Quaterniond& to)
{
    to = from;
}

void convert(   const Eigen::Quaterniond& from, 
                Eigen::Matrix3d& to)
{
    to = from.toRotationMatrix();
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
    to.linear() = rotation.toRotationMatrix();
    to.translation() = translation;
}

void convert(   const geometry_msgs::Transform& from,
                Eigen::Affine3f& to)
{
    Eigen::Vector3f translation;
    convert(from.translation, translation);
    Eigen::Quaternionf rotation;
    convert(from.rotation, rotation);
    to.setIdentity();
    to.linear() = rotation.toRotationMatrix();
    to.translation() = translation;
}

void convert(   const Eigen::Affine3d& from,
                geometry_msgs::Transform& to)
{
    Eigen::Quaterniond q(from.rotation());
    convert(q, to.rotation);
    const Eigen::Vector3d tmp = from.translation();
    convert(tmp, to.translation);
}

void convert(   const Eigen::Affine3f& from,
                geometry_msgs::Transform& to)
{
    Eigen::Quaternionf q(from.rotation());
    convert(q, to.rotation);
    const Eigen::Vector3f tmp = from.translation();
    convert(tmp, to.translation);
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

void convert(   const geometry_msgs::Pose& from,
                Eigen::Affine3f& to)
{
    Eigen::Vector3f translation;
    convert(from.position, translation);
    Eigen::Quaternionf rotation;
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
    const Eigen::Vector3d tmp = from.translation();
    convert(tmp, to.position);
}

void convert(   const Eigen::Affine3f& from,
                geometry_msgs::Pose& to)
{
    Eigen::Quaternionf q(from.rotation());
    convert(q, to.orientation);
    const Eigen::Vector3f tmp = from.translation();
    convert(tmp, to.position);
}

// OTHER
// void convert(   const boost::array<double, 36>& covdata);

void convert(   const std::vector<double>& from, 
                Eigen::MatrixXd& to)
{
    int N = sqrt(from.size());

    if(N*N != from.size())
    {
        // ERROR
        throw std::runtime_error("Cannot find quadratic matrix size");
    }
    to.resize(N,N);
    for(int i=0; i<from.size(); i++)
    {
        to(i / N, i % N) = from[i];
    }
}

void convert(   const std::vector<double>& from, 
                Eigen::VectorXd& to)
{
    int N = from.size();
    to.resize(N);
    for(int i=0; i<N; i++)
    {
        to(i) = from[i];
    }
}

// OPERATORS

// POINTS

// Eigen::Vector3d& operator<<=(
//     Eigen::Vector3d& to,
//     const geometry_msgs::Point& from)
// {
//     convert(from, to);
//     return to;
// }

// geometry_msgs::Point& operator<<=(
//     geometry_msgs::Point& to,
//     const Eigen::Vector3d& from)
// {
//     convert(from, to);
//     return to;
// }

// Eigen::Vector3f& operator<<=(
//     Eigen::Vector3f& to,
//     const geometry_msgs::Point32& from)
// {
//     convert(from, to);
//     return to;
// }

// geometry_msgs::Point32& operator<<=(
//     geometry_msgs::Point32& to,
//     const Eigen::Vector3f& from)
// {
//     convert(from, to);
//     return to;
// }

// Eigen::Vector3d& operator<<=(
//     Eigen::Vector3d& to,
//     const geometry_msgs::Vector3& from)
// {
//     convert(from, to);
//     return to;
// }

// geometry_msgs::Vector3& operator<<=(
//     geometry_msgs::Vector3& to,
//     const Eigen::Vector3d& from)
// {
//     convert(from, to);
//     return to;
// }

// ROTATIONS

// Eigen::Quaterniond& operator<<=(
//     Eigen::Quaterniond& to,
//     const geometry_msgs::Quaternion& from)
// {
//     convert(from, to);
//     return to;
// }

// geometry_msgs::Quaternion& operator<<=(
//     geometry_msgs::Quaternion& to,
//     const Eigen::Quaterniond& from)
// {
//     convert(from, to);
//     return to;
// }


// Eigen::Matrix3d& operator<<=(    
//     Eigen::Matrix3d& to,
//     const geometry_msgs::Quaternion& from)
// {
//     convert(from, to);
//     return to;
// }

// geometry_msgs::Quaternion& operator<<=( 
//     geometry_msgs::Quaternion& to,
//     const Eigen::Matrix3d& from)
// {
//     convert(from, to);
//     return to;
// }


// Eigen::Quaterniond& operator<<=( 
//     Eigen::Quaterniond& to,
//     const Eigen::Matrix3d& from)
// {
//     convert(from, to);
//     return to;
// }

// Eigen::Matrix3d& operator<<=(
//     Eigen::Matrix3d& to,
//     const Eigen::Quaterniond& from)
// {
//     convert(from, to);
//     return to;
// }

// // TRANSFORMATIONS

// Eigen::Affine3d& operator<<=(
//     Eigen::Affine3d& to, 
//     const geometry_msgs::Transform& from)
// {
//     convert(from, to);
//     return to;
// }

// geometry_msgs::Transform& operator<<=(
//     geometry_msgs::Transform& to, 
//     const Eigen::Affine3d& from)
// {
//     convert(from, to);
//     return to;
// }

// Eigen::Affine3d& operator<<=(   Eigen::Affine3d& to, 
//                                 const geometry_msgs::Pose& from)
// {
//     convert(from, to);
//     return to;
// }

// geometry_msgs::Pose& operator<<=(  geometry_msgs::Pose& to, 
//                                     const Eigen::Affine3d& from)
// {
//     convert(from, to);
//     return to;
// }


} // namespace rosmath