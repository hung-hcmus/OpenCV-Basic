#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;



//// ============ Resize and Crop ==================////
void main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResized, imgCrop;
	// Scale 
	resize(img, imgResized, Size(), 0.5, 0.5);

	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);

	imshow("Input image", img);
	imshow("Croped image", imgCrop);

	waitKey(0);
}