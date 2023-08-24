#include "Utils.h"

#include <iostream>
#include <cmath>

// wrapper for libInterp 1D linear interpolation
double ChargedUpCv::Utils::Lerp(const std::vector<double> x, const std::vector<double> y, double xVal)
{
    _1D::LinearInterpolator<double> lerp;
    lerp.setData(x, y);
    return lerp(xVal);
}

Eigen::Vector2d ChargedUpCv::Utils::TransposeCenter(double x, double y, double width, double height)
{
    return Eigen::Vector2d(x - floor(width / 2), -y + floor(height / 2));
}