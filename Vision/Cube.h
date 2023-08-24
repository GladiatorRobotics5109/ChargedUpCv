#pragma once

#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

#include <vector>

namespace ChargedUpCv::Vision 
{
    std::vector<Eigen::Vector3d> DetectCubes(cv::Mat frame);
}