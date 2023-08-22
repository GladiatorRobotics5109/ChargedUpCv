#include <vector>

#include <Eigen/Dense>

using Eigen::Vector2;

namespace ChargedUpCv::Utils
{   
    // wrapper for libInterp 1D linear interpolation
    double Lerp(std::vector<double> x, std::vector<double> y, double xVal);
    Eigen::Vector2d TransposeCenter(double x, double y, double width, double height);
}