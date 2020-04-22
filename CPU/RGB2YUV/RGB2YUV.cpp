// RGB2YUV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<opencv2/opencv.hpp>
#include<iostream>
#include <chrono> 
using namespace std::chrono;
using namespace std;
using namespace cv;
int main()
{
	try
	{

		Mat img = imread("mountain.png");

		if (!img.data)
		{
			std::cout << "Image not loaded";
			return -1;
		}
		auto start = high_resolution_clock::now();
		
		Mat RGB;
		
		cvtColor(img, RGB, COLOR_RGB2YUV);
		
		auto stop = high_resolution_clock::now();
		
		
		namedWindow("Display window", COLOR_RGB2YUV);
		imshow("Display window", img);

		namedWindow("Result window", WINDOW_AUTOSIZE);
		imshow("Result window", RGB);
		
		auto duration = duration_cast<milliseconds>(stop - start);
		
		cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
		
		//waitKey();
		
		return 0;
	}
	catch (cv::Exception & e)
	{
		cerr << e.msg << endl; // output exception message
	}

}
