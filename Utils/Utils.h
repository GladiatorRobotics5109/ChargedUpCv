#pragma once

#include <vector>

#include <Eigen/Dense>

#include <libInterpolate/Interpolate.hpp>

using Eigen::Vector2;

namespace ChargedUpCv::Utils
{
    // wrapper for libInterp 1D linear interpolation
    double Lerp(const std::vector<double> x, const std::vector<double> y, const double xVal);
    Eigen::Vector2d TransposeCenter(const double x, const double y, const double width, const double height);
}