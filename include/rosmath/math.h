#ifndef ROSMATH_MATH_H
#define ROSMATH_MATH_H

// global deps
#include <Eigen/Dense>
#include <limits>

// global ros deps
// geometry_msgs
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Point32.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PolygonStamped.h>
#include <geometry_msgs/AccelStamped.h>
#include <geometry_msgs/InertiaStamped.h>
#include <geometry_msgs/WrenchStamped.h>
#include <geometry_msgs/TwistStamped.h>

// TODO: covs
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TwistWithCovarianceStamped.h>

// TODO: nav_msgs
#include <nav_msgs/Path.h>

// internal deps
#include "conversions.h"
#include "template.h"

namespace rosmath {

using RotatableTypes = std::tuple<
    geometry_msgs::Point, 
    geometry_msgs::Vector3,
    geometry_msgs::Point32,
    geometry_msgs::Pose,
    geometry_msgs::Quaternion>;

using TransformableTypes = std::tuple<
    geometry_msgs::Transform, 
    geometry_msgs::Point, 
    geometry_msgs::Vector3,
    geometry_msgs::Point32,
    geometry_msgs::Quaternion,
    geometry_msgs::Pose,
    boost::array<double, 36>, // cov
    geometry_msgs::PoseWithCovariance,
    geometry_msgs::TwistWithCovariance,
    geometry_msgs::Polygon,
    geometry_msgs::Accel,
    geometry_msgs::Inertia,
    geometry_msgs::Wrench,
    geometry_msgs::Twist>;

using TransformableTypesStamped = std::tuple<
    geometry_msgs::TransformStamped, 
    geometry_msgs::PointStamped, 
    geometry_msgs::Vector3Stamped,
    geometry_msgs::QuaternionStamped,
    geometry_msgs::PoseStamped,
    geometry_msgs::PolygonStamped,
    geometry_msgs::AccelStamped,
    geometry_msgs::InertiaStamped,
    geometry_msgs::WrenchStamped,
    geometry_msgs::TwistStamped,
    geometry_msgs::PoseWithCovarianceStamped,
    geometry_msgs::TwistWithCovarianceStamped>;

constexpr double EPS_DBL = std::numeric_limits<double>::epsilon() * 10.0;
constexpr float EPS_FLT = std::numeric_limits<float>::epsilon() * 10.0;


geometry_msgs::Vector3 RPY( const double& roll,
                            const double& pitch,
                            const double& yaw);

geometry_msgs::Quaternion rpy2quat(const double& roll, 
                                   const double& pitch,
                                   const double& yaw);
geometry_msgs::Quaternion rpy2quat(const geometry_msgs::Vector3& rpy);

geometry_msgs::Vector3 quat2rpy(const geometry_msgs::Quaternion& q);


// functions
geometry_msgs::Point    neg(const geometry_msgs::Point& p);
geometry_msgs::Vector3  neg(const geometry_msgs::Vector3& p);
geometry_msgs::Point32  neg(const geometry_msgs::Point32& p);

// equal? already implemented. 
// but: maybe self implement due to hard precision unequalities
// 
bool equal( const geometry_msgs::Point& a,
            const geometry_msgs::Point& b);
bool equal( const geometry_msgs::Vector3& a,
            const geometry_msgs::Vector3& b);
bool equal( const geometry_msgs::Point32& a,
            const geometry_msgs::Point32& b);
bool equal( const geometry_msgs::PointStamped& a,
            const geometry_msgs::PointStamped& b);

// ADD
geometry_msgs::Point    add(const geometry_msgs::Point& a, 
                            const geometry_msgs::Point& b);
geometry_msgs::Vector3  add(const geometry_msgs::Vector3& a, 
                            const geometry_msgs::Vector3& b);
geometry_msgs::Point32  add(const geometry_msgs::Point32& a,
                            const geometry_msgs::Point32& b);
geometry_msgs::Point    add(const geometry_msgs::Point& p, 
                            const double& scalar);
geometry_msgs::Vector3  add(const geometry_msgs::Vector3& p, 
                            const double& scalar);
geometry_msgs::Point32  add(const geometry_msgs::Point32& p, 
                            const float& scalar);
geometry_msgs::Point    add(const geometry_msgs::Point& p,
                            const geometry_msgs::Vector3& v);

geometry_msgs::Quaternion add(
    const geometry_msgs::Quaternion& a,
    const geometry_msgs::Quaternion& b);

// SUBSTRACT
geometry_msgs::Point    sub(const geometry_msgs::Point& a, 
                            const geometry_msgs::Point& b);
geometry_msgs::Vector3  sub(const geometry_msgs::Vector3& a, 
                            const geometry_msgs::Vector3& b);
geometry_msgs::Point32  sub(const geometry_msgs::Point32& a,
                            const geometry_msgs::Point32& b);
geometry_msgs::Point    sub(const geometry_msgs::Point& p, 
                            const double& scalar);
geometry_msgs::Vector3  sub(const geometry_msgs::Vector3& p, 
                            const double& scalar);
geometry_msgs::Point32  sub(const geometry_msgs::Point32& p, 
                            const float& scalar);

geometry_msgs::Quaternion sub(
    const geometry_msgs::Quaternion& a,
    const geometry_msgs::Quaternion& b);

// MULTIPLY
geometry_msgs::Point mult(  const geometry_msgs::Point& p,
                            const double& scalar);

geometry_msgs::Point mult(  const double& scalar,
                            const geometry_msgs::Point& p);

geometry_msgs::Vector3 mult( const geometry_msgs::Vector3& p, 
                             const double& scalar );

geometry_msgs::Vector3 mult( const double& scalar,
                             const geometry_msgs::Vector3& p );

geometry_msgs::Point32 mult( const geometry_msgs::Point32& p, 
                             const float& scalar );

geometry_msgs::Point32 mult( const float& scalar,
                             const geometry_msgs::Point32& p );

geometry_msgs::Quaternion mult( const geometry_msgs::Quaternion& p, 
                                const double& scalar );

geometry_msgs::Quaternion mult( const double& scalar,
                                const geometry_msgs::Quaternion& p );

geometry_msgs::Point mult(  const geometry_msgs::Transform& T, 
                            const geometry_msgs::Point& p);

geometry_msgs::Point mult(  const geometry_msgs::Quaternion& q,
                            const geometry_msgs::Point& p);

geometry_msgs::Point32 mult(    const geometry_msgs::Transform& T, 
                                const geometry_msgs::Point32& p);

geometry_msgs::Point32 mult(    const geometry_msgs::Quaternion& q, 
                                const geometry_msgs::Point32& p);

geometry_msgs::Vector3 mult(    const geometry_msgs::Transform& T, 
                                const geometry_msgs::Vector3& p);

geometry_msgs::Vector3 mult( const geometry_msgs::Quaternion& q,
                             const geometry_msgs::Vector3& p);

geometry_msgs::Transform mult(  const geometry_msgs::Transform& A, 
                                const geometry_msgs::Transform& B);

geometry_msgs::Quaternion mult(  const geometry_msgs::Quaternion& a, 
                                const geometry_msgs::Quaternion& b);

geometry_msgs::Pose mult(  const geometry_msgs::Transform& T, 
                                const geometry_msgs::Pose& p);

geometry_msgs::Polygon mult(  const geometry_msgs::Transform& T, 
                                const geometry_msgs::Polygon& p);

geometry_msgs::Accel mult( const geometry_msgs::Transform& T,
                            const geometry_msgs::Accel& a);

geometry_msgs::Inertia mult(const geometry_msgs::Transform& T,
                            const geometry_msgs::Inertia& inertia);

geometry_msgs::Wrench mult(const geometry_msgs::Transform& T,
                            const geometry_msgs::Wrench& w);

geometry_msgs::Twist mult(const geometry_msgs::Transform& T,
                            const geometry_msgs::Twist& twist);

// TODO: check covariance functions
boost::array<double, 36> multCov(const geometry_msgs::Transform& T, 
    const boost::array<double, 36>& covariance);

geometry_msgs::PoseWithCovariance mult(
    const geometry_msgs::Transform& T,
    const geometry_msgs::PoseWithCovariance& p);

geometry_msgs::TwistWithCovariance mult(
    const geometry_msgs::Transform& T,
    const geometry_msgs::TwistWithCovariance& twist);

// stamped
geometry_msgs::TransformStamped mult(
    const geometry_msgs::TransformStamped& A,
    const geometry_msgs::TransformStamped& B);

geometry_msgs::PointStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::PointStamped& p);

geometry_msgs::Vector3Stamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::Vector3Stamped& v);

geometry_msgs::PoseStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::PoseStamped& p);

geometry_msgs::PoseArray mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::PoseArray& parr);

geometry_msgs::PolygonStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::PolygonStamped& p);

geometry_msgs::AccelStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::AccelStamped& a);

geometry_msgs::InertiaStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::InertiaStamped& inertia);

geometry_msgs::WrenchStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::WrenchStamped& wrench);

geometry_msgs::TwistStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::TwistStamped& twist);

geometry_msgs::PoseWithCovarianceStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::PoseWithCovarianceStamped& p);

geometry_msgs::TwistWithCovarianceStamped mult(
    const geometry_msgs::TransformStamped& T,
    const geometry_msgs::TwistWithCovarianceStamped& twist);

// shortcut: vector of transformables
template<typename GeomT, typename TupleEnabler<GeomT, TransformableTypes>::type* = nullptr>
std::vector<GeomT> mult(const geometry_msgs::Transform& T,
    const std::vector<GeomT>& data);

template<typename GeomT, typename TupleEnabler<GeomT, TransformableTypesStamped>::type* = nullptr>
std::vector<GeomT> mult(const geometry_msgs::TransformStamped& T,
    const std::vector<GeomT>& data);

template<typename GeomT, typename TupleEnabler<GeomT, RotatableTypes>::type* = nullptr>
std::vector<GeomT> mult(const geometry_msgs::Quaternion& q,
    const std::vector<GeomT>& data);

// DIVIDE
geometry_msgs::Point        div(const geometry_msgs::Point& p, 
                                const double& scalar);
geometry_msgs::Vector3      div(const geometry_msgs::Vector3& p,
                                const double& scalar);
geometry_msgs::Point32      div(const geometry_msgs::Point32& p,
                                const double& scalar);
geometry_msgs::Quaternion   div(const geometry_msgs::Quaternion& p,
                                const double& scalar);

double  dot(    const geometry_msgs::Point& a,
                const geometry_msgs::Point& b);
double  dot(    const geometry_msgs::Vector3& a,
                const geometry_msgs::Vector3& b);
float   dot(    const geometry_msgs::Point32& a,
                const geometry_msgs::Point32& b);

geometry_msgs::Point    cross(  const geometry_msgs::Point& a,
                                const geometry_msgs::Point& b);
geometry_msgs::Vector3  cross(  const geometry_msgs::Vector3& a,
                                const geometry_msgs::Vector3& b);
geometry_msgs::Point32  cross(  const geometry_msgs::Point32& a,
                                const geometry_msgs::Point32& b);

geometry_msgs::Quaternion inv(const geometry_msgs::Quaternion& q);
geometry_msgs::Transform  inv(const geometry_msgs::Transform& T);
geometry_msgs::Pose       inv(const geometry_msgs::Pose& p);
geometry_msgs::TransformStamped  inv(const geometry_msgs::TransformStamped& T);


double norm(const geometry_msgs::Point& p);
double norm(const geometry_msgs::Vector3& p);
float  norm(const geometry_msgs::Point32& p);
double norm(const geometry_msgs::Quaternion& q);

double sum(const geometry_msgs::Point& p);
double sum(const geometry_msgs::Vector3& p);
float  sum(const geometry_msgs::Point32& p);
double sum(const geometry_msgs::Quaternion& q);

void normalize(geometry_msgs::Quaternion& q);
void identity(geometry_msgs::Quaternion& q);
void identity(geometry_msgs::Transform& T);

// Transformations


// Operators

// EQUAL operator
// bool operator==(const geometry_msgs::Point& a,
//                 const geometry_msgs::Point& b);
// bool operator==(const geometry_msgs::Vector3& a,
//                 const geometry_msgs::Vector3& b);
// bool operator==(const geometry_msgs::Point32& a,
//                 const geometry_msgs::Point32& b);
// bool operator==(const geometry_msgs::PointStamped& a,
//                 const geometry_msgs::PointStamped& b);

// NOT EQUAL
// bool operator!=(const geometry_msgs::Point& a,
//                 const geometry_msgs::Point& b);
// bool operator!=(const geometry_msgs::Vector3& a,
//                 const geometry_msgs::Vector3& b);
// bool operator!=(const geometry_msgs::Point32& a,
//                 const geometry_msgs::Point32& b);
// bool operator!=(const geometry_msgs::PointStamped& a,
//                 const geometry_msgs::PointStamped& b);


// NEGATE
geometry_msgs::Point operator-(
    const geometry_msgs::Point& p);

geometry_msgs::Vector3 operator-(
    const geometry_msgs::Vector3& p);

geometry_msgs::Point32 operator-(
    const geometry_msgs::Point32& p);

// PLUS
geometry_msgs::Point operator+(
    const geometry_msgs::Point& a,
    const geometry_msgs::Point& b);

geometry_msgs::Vector3 operator+(
    const geometry_msgs::Vector3& a,
    const geometry_msgs::Vector3& b);

geometry_msgs::Point32 operator+(
    const geometry_msgs::Point32& a,
    const geometry_msgs::Point32& b);

geometry_msgs::Point operator+(
    const geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Vector3 operator+(
    const geometry_msgs::Vector3& p,
    const double& scalar);

geometry_msgs::Point32 operator+(
    const geometry_msgs::Point32& p,
    const float& scalar);

geometry_msgs::Quaternion operator+(
    const geometry_msgs::Quaternion& a,
    const geometry_msgs::Quaternion& b);

geometry_msgs::Point operator+(
    const geometry_msgs::Point& p,
    const geometry_msgs::Vector3& v);

// PLUS=
geometry_msgs::Point operator+=(
    geometry_msgs::Point& a,
    const geometry_msgs::Point& b);

geometry_msgs::Vector3 operator+=(
    geometry_msgs::Vector3& a,
    const geometry_msgs::Vector3& b);

geometry_msgs::Point32 operator+=(
    geometry_msgs::Point32& a,
    const geometry_msgs::Point32& b);

geometry_msgs::Point operator+=(
    geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Vector3 operator+=(
    geometry_msgs::Vector3& p,
    const double& scalar);

geometry_msgs::Point32 operator+=(
    geometry_msgs::Point32& p,
    const float& scalar);

// MINUS
geometry_msgs::Point operator-(
    const geometry_msgs::Point& a,
    const geometry_msgs::Point& b);

geometry_msgs::Vector3 operator-(
    const geometry_msgs::Vector3& a,
    const geometry_msgs::Vector3& b);

geometry_msgs::Point32 operator-(
    const geometry_msgs::Point32& a,
    const geometry_msgs::Point32& b);

geometry_msgs::Point operator-(
    const geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Vector3 operator-(
    const geometry_msgs::Vector3& p,
    const double& scalar);

geometry_msgs::Point32 operator-(
    const geometry_msgs::Point32& p,
    const float& scalar);

geometry_msgs::Quaternion operator-(
    const geometry_msgs::Quaternion& a,
    const geometry_msgs::Quaternion& b);

// MINUS=
geometry_msgs::Point operator-=(
    geometry_msgs::Point& a,
    const geometry_msgs::Point& b);

geometry_msgs::Vector3 operator-=(
    geometry_msgs::Vector3& a,
    const geometry_msgs::Vector3& b);

geometry_msgs::Point32 operator-=(
    geometry_msgs::Point32& a,
    const geometry_msgs::Point32& b);

geometry_msgs::Point operator-=(
    geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Vector3 operator-=(
    geometry_msgs::Vector3& p,
    const double& scalar);

geometry_msgs::Point32 operator-=(
    geometry_msgs::Point32& p,
    const float& scalar);

// MULTIPLY
geometry_msgs::Point operator*(  
    const geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Point operator*(  
    const double& scalar,
    const geometry_msgs::Point& p);

geometry_msgs::Vector3 operator*( 
    const geometry_msgs::Vector3& p, 
    const double& scalar );

geometry_msgs::Vector3 operator*( 
    const double& scalar,
    const geometry_msgs::Vector3& p );

geometry_msgs::Point32 operator*( 
    const geometry_msgs::Point32& p, 
    const float& scalar );

geometry_msgs::Point32 operator*( 
    const float& scalar,
    const geometry_msgs::Point32& p );

geometry_msgs::Quaternion operator*( 
    const geometry_msgs::Quaternion& p, 
    const double& scalar );

geometry_msgs::Quaternion operator*( 
    const double& scalar,
    const geometry_msgs::Quaternion& p );

double operator*(
    const geometry_msgs::Point& a,
    const geometry_msgs::Point& b);

template<typename GeomT, typename TupleEnabler<GeomT, RotatableTypes>::type* = nullptr>
GeomT operator*(const geometry_msgs::Quaternion& T,
                const GeomT& data);

template<typename GeomT, typename TupleEnabler<GeomT, TransformableTypes>::type* = nullptr>
GeomT operator*(const geometry_msgs::Transform& T,
                const GeomT& data);

// STAMPED
template<typename GeomT, typename TupleEnabler<GeomT, TransformableTypesStamped>::type* = nullptr>
GeomT operator*(const geometry_msgs::TransformStamped& T,
                const GeomT& data);

// VECTOR
template<typename GeomT, typename TupleEnabler<GeomT, TransformableTypes>::type* = nullptr>
std::vector<GeomT> operator*(const geometry_msgs::Transform& T,
    const std::vector<GeomT>& data);

template<typename GeomT, typename TupleEnabler<GeomT, TransformableTypesStamped>::type* = nullptr>
std::vector<GeomT> operator*(const geometry_msgs::TransformStamped& T,
    const std::vector<GeomT>& data);

template<typename GeomT, typename TupleEnabler<GeomT, RotatableTypes>::type* = nullptr>
std::vector<GeomT> operator*(const geometry_msgs::Quaternion& q,
    const std::vector<GeomT>& data);

geometry_msgs::Point operator*=(  
    geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Vector3 operator*=(  
    geometry_msgs::Vector3& p,
    const double& scalar);

geometry_msgs::Point32 operator*=(  
    geometry_msgs::Point32& p,
    const float& scalar);

// DIVIDE
geometry_msgs::Point operator/(
    const geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Vector3 operator/(
    const geometry_msgs::Vector3& p,
    const double& scalar);

geometry_msgs::Point32 operator/(
    const geometry_msgs::Point32& p,
    const double& scalar);

geometry_msgs::Quaternion operator/(
    const geometry_msgs::Quaternion& p,
    const double& scalar);

geometry_msgs::Point operator/=(
    geometry_msgs::Point& p,
    const double& scalar);

geometry_msgs::Vector3 operator/=(
    geometry_msgs::Vector3& p,
    const double& scalar);

geometry_msgs::Point32 operator/=(
    geometry_msgs::Point32& p,
    const double& scalar);

geometry_msgs::Quaternion operator/=(
    geometry_msgs::Quaternion& p,
    const double& scalar);

// inverse operator
geometry_msgs::Quaternion operator~(
    const geometry_msgs::Quaternion& q);
    
geometry_msgs::Transform operator~(
    const geometry_msgs::Transform& T);

geometry_msgs::Pose operator~(
    const geometry_msgs::Pose& p);

geometry_msgs::TransformStamped operator~(
    const geometry_msgs::TransformStamped& T);

}

#include "math.tcc"

#endif // ROSMATH_MATH_H