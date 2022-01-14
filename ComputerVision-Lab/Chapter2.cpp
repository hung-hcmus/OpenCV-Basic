#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//// ============ Basic Function ================== ////
void main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	// Blur
	GaussianBlur(img, imgBlur, Size(3,3), 3, 0);
	// Edge Detection
	Canny(imgBlur, imgCanny, 50, 150);

	// Dilation - Incressing the thickness
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	// Erode - Decressing the thickness
	erode(imgDil, imgErode, kernel);

	imshow("Original Image", img);
	//imshow("Affter", imgGray);
	//imshow("Image Blur", imgGray);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil );
	imshow("Image Erode", imgErode);

	waitKey(0);
}