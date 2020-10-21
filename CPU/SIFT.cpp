#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/xfeatures2d/nonfree.hpp"
#include<iostream>
#include <chrono> 

using namespace std::chrono;
using namespace cv;
using namespace std;

int main(int argc, const char* argv[])
{

    const cv::Mat input = cv::imread("rgray8.bmp", 0); //Load as grayscale
   
  
    cv::Ptr<cv::SiftFeatureDetector> detector = cv::SiftFeatureDetector::create();

    std::vector<cv::KeyPoint> keypoints;

    detector->detect(input, keypoints);
    
    cv::Mat desc;
    detector->compute(input, keypoints, desc);


    // Add results to image and save.
    cv::Mat output;
    cv::drawKeypoints(input, keypoints, output);
    cv::imwrite("sift_result.bmp", output);



    waitKey();

    return 0;
}