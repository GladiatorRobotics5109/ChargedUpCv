#include "Cone.h"

#include "../Utils/Utils.h"
#include "../Utils/Constants.h"

#include <cmath>

using namespace ChargedUpCv;

std::vector<Eigen::Vector3d> ChargedUpCv::Vision::detectCones(cv::Mat frame) 
{
    std::vector<Eigen::Vector3d> conePoses;

    // generate mask
    cv::Mat hsv = cv::cvtColor(frame, cv::COLOR_BGR2HSV);
    std::vector<int> lowerYellow = { 20, 68, 100 };
    std::vector<int> upperYellow = { 25, 255, 255 };
    std::Mat mask = cv::inRange(hsv, lowerYellow, upperYellow);
    
    // find countours of cone
    cv::Mat result = cv::bitwise_and(frame, frame, mask = mask);
    result = cv::cvtColor(result, cv::COLOR_BGR2GRAY);
    std::vector<std::vector<cv::Point>> countours;
    cv::Mat contourOutput = result.clone();;
    cv::findContours(contourOutput, countours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
   
   
    std::vector<int> largestAreas;
    std::vector<tuple<int,int>> largestPoses;
    int sizeThreshold = 3200;
    int largestArea = 0;
    for (int i = 0; i < contours.size(); i++)
    {
        std::vector<cv::Point> countour = contours[i];

        int curArea = cv::countourArea(contours[i]);

        cv::Rect rect = cv::boundingRect(countour);
        cv::rectangle(frame, rect.tl(), rect.br(), Scalar(0,255,0), 5);

        int cx = cmath::floor(rect.x - rect.width);
        int cy = cmath::floor(rect.y - rect.height);

        if (curArea > sizeThreshold) 
        {
            largestAreas.push_back(curArea);
            largestPose.push_back(make_tuple(cx, cy));
        }
    }

    for (int i = 0; i < largestAreas.size(); i++)
    {
        // camrea config
        // aspecRatio 25:18
        // resolution: 1000x720
        // xResolution = 1000;
        // yResolution = 720;
        // vFov = 45.575;
        // hFov = 63.299;
		// xAngle = (xPos / 1000) * (hFov / 2)
		// yAngle = (yPos / 720) * (vFov / 2)

        // get angle
        double angleZ = (largestPoses[i][0] / Constants::XResolution) * (Constants::HFov / 2);
        double angleX = (largestPoses[i][1] / Constants::YResolution) * (Constants::VFov / 2);
        angleX = (2 * angleX) - 22.785 // apply offset
		angleX *= -1
		angleZ = (2 * angleZ) - 30 // apply offset
        
        // get dist
        double dist = Utils::Lerp(Constants::XValsCone, Constants::YVals, largestAreas[i]);

        // get pos
        double radX = angleX * (M_PI/180)
		double radZ = angleZ * (M_PI/180)
        Eigen::Vector3d conePos = Eigen::Vector3d(
            sin(radX) * distance * sin(radZ), // horizontal axis (x)
            cos(radX) * distance, // vertical axis (y)
            sin(radX) * distance * cos(radZ) // depth axis (z)
        )

        conePoses.push_back(conePos);
    }

    return conePoses;
}
