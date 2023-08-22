#include "Utils.h"

#include <iostream>
#include <cmath>

#include <libInterpolate/Interpolate.hpp>

// wrapper for libInterp 1D linear interpolation
double ChargedUpCv::Utils::Math::Lerp(std::vector<double> x, std::vector<double> y, double xVal)
{
    _1D::LinearInterpolator<double> lerp; // is creating this object slow??
    lerp.setData(x, y);
    return lerp(xVal);
}


Eigen::Vector2d ChargedUpCv::Utils::Math::TransposeCenter(double x, double y, double width, double height)
{
    return Eigen::Vector2d(x - sqrt(width), -y + sqrt(height));
}