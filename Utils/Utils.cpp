#include "Utils.h"

#include <iostream>
#include <cmath>

#include <libInterpolate/Interpolate.hpp>

// wrapper for libInterp 1D linear interpolation
double ChargedUpCv::Utils::Lerp(std::vector<double> x, std::vector<double> y, double xVal)
{
    _1D::LinearInterpolator<double> lerp;
    lerp.setData(x, y);
    double result = lerp(xVal);
}