#include <vector>

#include <Eigen/Dense>

using Eigen::Vector2;

namespace ChargedUpCv::Utils
{
    class Math
    {
    public:
        // wrapper for libInterp 1D linear interpolation
        static double Lerp(std::vector<double> x, std::vector<double> y, double xVal);
        static Eigen::Vector2d TransposeCenter(double x, double y, double width, double height);
    };
}