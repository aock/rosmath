#ifndef ROSMATH_RANDOM_H
#define ROSMATH_RANDOM_H

#include "math.h"
#include <random>
namespace rosmath {

namespace random {

constexpr static double SQRT2PI = std::sqrt(2 * M_PI);

std::default_random_engine engine;

void seed(size_t seed)
{
    engine = std::default_random_engine(seed);
}

size_t uniform_number(
    const size_t min,
    const size_t max);

std::vector<size_t> uniform_numbers(
    const size_t min,
    const size_t max,
    const size_t size);

double uniform_number(
    const double min,
    const double max);

std::vector<double> uniform_numbers(
    const double min,
    const double max,
    const size_t size);

double uniform_angle();

geometry_msgs::Point uniform_point(
    const geometry_msgs::Point pmin, 
    const geometry_msgs::Point pmax);

std::vector<geometry_msgs::Point> uniform_points(
    const geometry_msgs::Point pmin, 
    const geometry_msgs::Point pmax,
    const size_t size
);

geometry_msgs::Quaternion uniform_quaternion();
geometry_msgs::Quaternion uniform_quaternion(
    const geometry_msgs::Vector3 axis);

void uniform_fill(
    std::vector<size_t>& data, 
    const size_t min,
    const size_t max);

void uniform_fill(
    std::vector<double>& data, 
    const double min,
    const double max);

void uniform_fill(
    std::vector<geometry_msgs::Point>& data, 
    const geometry_msgs::Point pmin, 
    const geometry_msgs::Point pmax);

double normal_number(
    const double mu,
    const double sigma);

geometry_msgs::Point normal_point(
    const geometry_msgs::Point mu,
    const geometry_msgs::Point sigma);

geometry_msgs::Quaternion normal_quaternion(
    const double sx, const double sy, const double sz);

std::vector<double> normal_numbers(
    const double mu, 
    const double sigma,
    const size_t size);

std::vector<geometry_msgs::Point> normal_points(
    const geometry_msgs::Point mu,
    const geometry_msgs::Point sigma,
    const size_t size);

void normal_fill(
    std::vector<double>& data,
    const double mu,
    const double sigma);

void normal_fill(
    std::vector<geometry_msgs::Point>& data,
    const geometry_msgs::Point mu,
    const geometry_msgs::Point sigma);

double mahalanobis_dist(
    const Eigen::VectorXd& mean, 
    const Eigen::MatrixXd& covInv,
    const Eigen::VectorXd& X);

/**
 * @brief General Normal Distribution Class
 * 
 * Improved Version of http://blog.sarantop.com/notes/mvn
 * 
 * TODO: 
 * - Test class functions for correctness
 * - Implement multivariate fit to X and Y values
 */
class Normal {
public:
    Normal(const Eigen::VectorXd& mean, 
            const Eigen::MatrixXd& cov);

    ~Normal();

    double mahalanobisDist(const Eigen::VectorXd& X) const;

    // N(X)
    double pdf(const Eigen::VectorXd& X) const;

    Eigen::VectorXd pdf(const Eigen::MatrixXd& X) const;

    Eigen::VectorXd mean() const;
    Eigen::MatrixXd cov() const;
    Eigen::MatrixXd covInv() const;
    double covDet() const;
    
    // sample
    Eigen::VectorXd sample() const;

    Eigen::MatrixXd samples(size_t N) const;

    static Normal fit(const Eigen::MatrixXd& sX);

    static Normal fit(
        const Eigen::MatrixXd& sX, 
        const Eigen::VectorXd& sY);

    double kld(const Normal& N) const;

    // is this a joint?
    Normal joint(const Normal& N) const;

    Normal transform(const Eigen::MatrixXd& T) const;

private:
    Eigen::VectorXd m_mean;
    Eigen::MatrixXd m_cov;

    // other

    // PDF
    Eigen::MatrixXd m_cov_inv;
    double m_det;

    // Transform for samples
    Eigen::MatrixXd m_transform;
};


Normal joint(const std::vector<Normal>& Ns);

} // namespace random

} // namespace rosmath

#endif // ROSMATH_RANDOM_H