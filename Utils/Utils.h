#include <vector>

namespace ChargedUpCv::Utils
{   
    // wrapper for libInterp 1D linear interpolation
    double Lerp(std::vector<double> points, double t);
}