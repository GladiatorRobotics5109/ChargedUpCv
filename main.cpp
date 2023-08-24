#include <iostream>
#include <vector>
#include <string>


#include <opencv2/opencv.hpp>
#include <Eigen/Dense>


#include "Vision/Cube.h"
#include "Vision/Cone.h"
#include "Vision/AprilTag.h"

#include "Utils/Utils.h"

using namespace ChargedUpCv;

int main()
{
    
    cv::VideoCapture cap(0);
    cv::Mat frame;
    
    while (true) {
        cap.read(frame);

        std::vector<Eigen::Vector3d> conePoses = Vision::DetectCones(frame);
        std::cout << "CONES:" << std::endl;
        for (int i = 0; i < conePoses.size(); i++)
        {
            Eigen::Vector3d pos = conePoses[i];
            std::cout << "    Cone " << i << ": (" << pos.x << ", " << pos.y << ", " << pos.z << ")" << std::endl;
        }

        std::vector<Eigen::Vector3d> cubePoses = Vision::DetectCubes(frame);
        std::cout << "CUBES:" << std::endl;
        for (int i = 0; i < cubePoses.size(); i++)
        {
            Eigen::Vector3d pos = cubePoses[i];
            std::cout << "    Cube " << i << ": (" << pos.x << ", " << pos.y << ", " << pos.z << ")" << std::endl;
        }
    }

    return 0;
}