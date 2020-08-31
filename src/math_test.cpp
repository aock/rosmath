#include <ros/ros.h>
#include <rosmath/rosmath.h>
#include <iostream>

using namespace rosmath;

bool testGeneralMath()
{
    bool ret = true;

    // multiply, divide
    geometry_msgs::Point p;
    p.x = 1.0;
    p.y = 2.0;
    p.z = 3.0;
    p = p * 2.0;
    p /= 2.0;
    p *= 2.0;
    p = p / 2.0;
    if(p.x != 1.0 || p.y != 2.0 || p.z != 3.0)
    {
        ROS_WARN_STREAM("error: multiply, divide\n" << p);
        ret = false;
    }

    

    // add, subtract
    p = p + 2.0;
    p -= 2.0;
    p += 2.0;
    p = p - 2.0;
    if(p.x != 1.0 || p.y != 2.0 || p.z != 3.0)
    {
        ROS_WARN_STREAM("error: add/sub point and scalar\n" << p);
        ret = false;
    }

    geometry_msgs::Point p2;
    p2.x = 4.0;
    p2.y = 6.0;
    p2.z = 8.0;

    p = p - p2;
    p += p2;
    p -= p2;
    p = p + p2;
    if(p.x != 1.0 || p.y != 2.0 || p.z != 3.0)
    {
        ROS_WARN_STREAM("error: add/sub point and point\n" << p);
        ret = false;
    }

    return ret;
}

bool testTransformPoint()
{
    bool ret = true;


    geometry_msgs::Point p;
    p.x = 10.0;
    p.y = 5.0;
    p.z = 1.0;

    geometry_msgs::Transform T;
    T.rotation.w = 1.0;
    T.translation.x = 1.0;
    geometry_msgs::Point p2 = mult(T, p);

    p2 = T * p;

    auto p3 = T.rotation * p;

    // x=0, y=0.5, z=0.0, w=0.5
    Eigen::Quaterniond q(0.5, 0.0, 0.5, 0.0);
    q.normalize();
    geometry_msgs::Quaternion q2;
    q2 <<= q;
    Eigen::Quaterniond qinv = q.inverse();
    auto q2inv = ~q2;
    
    T * ~T;

    return ret;
}

bool testStamped()
{
    bool ret = true;

    geometry_msgs::TransformStamped A, B, C;
    
    A.header.frame_id = "map";
    A.child_frame_id = "base_link";
    A.transform.translation.x = 5.0;
    A.transform.translation.y = 2.0;
    identity(A.transform.rotation);
    
    B.header.frame_id = "base_link";
    B.child_frame_id = "camera";
    B.transform.translation.z = 1.0;
    identity(B.transform.rotation);

    C.header.frame_id = "camera";
    C.child_frame_id = "camera_optical";
    C.transform.rotation = ros2optical();
    
    auto D = A * B * C;

    if(D.header.frame_id != "map" || D.child_frame_id != "camera_optical")
    {
        ROS_WARN_STREAM("ERROR. transform stamped: frame ids");
        ret = false;
    }

    bool exception_throwed = false;
    try{
        C * B; // frame mismatch
    } catch(TransformException ex) {
        exception_throwed = true;
    }
    ret &= exception_throwed;

    ~C * ~B;
    if(B.header.frame_id != (~~B).header.frame_id )
    {
        ret = false;
    }

    // Point stamped
    geometry_msgs::PointStamped p;
    p.header.frame_id = "camera_optical";
    p.point.x = 2.0;

    auto p2 = D * p;
    auto p3 = ~D * p2;


    if(!equal(p3, p))
    {
        ROS_WARN_STREAM("transform error. p and p3 different:\n" << p << "\n" << p3);
        
        std::cout << 2.0*std::numeric_limits<double>::epsilon() << std::endl;
        ret = false;
    }

    exception_throwed = false;
    try{
        ~D * p;
    } catch(TransformException ex) {
        exception_throwed = true;
    }
    ret &= exception_throwed;

    return ret;
}

std::string result(bool res)
{
    if(res)
    {
        return "success";
    } else {
        return "failure";
    }
}

void test( std::string name, bool (*f)(void) )
{
    std::cout << "-- " << name << ": " << result(f()) << std::endl;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "rosmath_math_test_node");

    std::cout << "Tests of rosmath library: Math" << std::endl;

    test("General Math", testGeneralMath);
    test("Point Transformation", testTransformPoint);
    test("Stamped Transformation", testStamped);

    return 0;
}