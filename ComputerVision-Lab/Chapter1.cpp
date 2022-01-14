#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;



//// ============ Import Image ==================
//void main()
//{
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	imshow("image", img);
//	waitKey(0);
//}



//// ============ Import Video ==================
//void main()
//{
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true)
//	{
//		cap.read(img);
//		imshow("video", img);
//		waitKey(20);
//	}
//}

// ============ Import Webcam ==================
void main()
{
	VideoCapture cap(0);
	Mat img;

	while (true)
	{
		cap.read(img);
		imshow("WebCam", img);
		waitKey(1);
	}
}