#include <iostream>
#include <chrono> 
#include "opencv2/opencv.hpp"

using namespace std::chrono;
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{		
        auto start = chrono::high_resolution_clock::now();
        cv::Mat h_img1 = cv::imread("Rainier.bmp");
        //Define device variables
        cv::cuda::GpuMat d_result1, d_img1;
        //Upload Image to device
        d_img1.upload(h_img1);

        //Convert image to different color spaces
        cv::cuda::cvtColor(d_img1, d_result1, cv::COLOR_RGB2GRAY);


        cv::Mat h_result1, h_result2, h_result3, h_result4;
        //Download results back to host
        d_result1.download(h_result1);
        
        auto end = chrono::high_resolution_clock::now();
        cout << "Elapsed time in nanoseconds : "
            << chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 10e-6
            << " ms" << endl;

        
        cv::imshow("Result in Gray ", h_result1);
        waitKey();

	
	return 0;

	}

