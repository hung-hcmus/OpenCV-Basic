#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;



//// ============ Drawing shapes and write text ==================
void main()
{
	// Create blank image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// Adding shapes
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);

	// Adding text
	putText(img, "STOP", Point(180, 350), FONT_HERSHEY_COMPLEX, 2, Scalar(255, 255, 255), 2);

	imshow("image", img);
	waitKey(0);
}