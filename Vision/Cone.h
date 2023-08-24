#pragma once

#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
    

namespace ChargedUpCv::Vision 
{
    Eigen::Vector3d DetectCones(cv::Mat frame);
}