#pragma once

#include <vector>

namespace ChargedUpCv
{
    class Constants
    {
    public:
        // camera constants
        const static int XResolution = 1000;
        const static int YResolution = 720;
        const static double HFov = 63.299;
        const static double HFov = 45.575;
        // lerp constants
        std::vector<double> XValsCone = { 105000, 50000, 28000, 18000, 12700, 9300, 7400, 5800, 4300, 4000, 3200 };
        std::vector<double> XValsCube = { 60000, 34900, 21000, 14000, 9000, 8000, 6500, 5700, 4200, 4000,3300 };
        std::vector<double> YVals = { 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3 };                       
    }
}