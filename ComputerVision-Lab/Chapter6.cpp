#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//// ============ Color Detection ==================

Mat imgHSV, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

void main()
{
	// Import input image
	string path = "Resources/shapes.png";
	Mat img = imread(path);

	// Convert to HSV color space 
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("DetectColor", (1080, 720));
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true)
	{
		// Define the range of color want to detect
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		// Detect color 
		inRange(imgHSV, lower, upper, mask);

		imshow("image", img);
		imshow("HSV image", imgHSV);
		imshow("Mask image", mask);
		
		waitKey(1);
	}
}