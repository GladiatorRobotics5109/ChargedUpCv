#include <iostream>
#include <vector>
#include <string>


#include <opencv2/opencv.hpp>


// #include "Vision/Cube.h"
// #include "Vision/Cone.h"
// #include "Vision/AprilTag.h"

#include "Utils/Utils.h"

using namespace ChargedUpCv;

int main(){
    
    // cv::VideoCapture cap(0);
    // cv::Mat frame;
    
    /*while (true) {
        cap.read(frame);

        //Vision::DetectCubes(frame);
        std::vector<double> dat = {0.0, 100.0};
        //double result = ChargedUpCv::Utils::Lerp(dat, 0.5);
        std::cout << "Lerp Result: " << std::endl;

    }*/

    std::vector<double> x = { 0.0, 1.0, 2.0, 3.0, 4.0 };
    std::vector<double> y = { 0.0, 5.0, 10.0, 15.0, 20.0 };

    std::cout << "Lerp Result: " << result << std::endl;

    return 0;
}