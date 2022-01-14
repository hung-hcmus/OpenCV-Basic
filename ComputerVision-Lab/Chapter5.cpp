#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//// ============ Warp Images ==================
float w = 250, h = 350;
Mat matrix, imgWarp;
void main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	// Card Pivot
	Point2f src[4] = { {535,142}, {771,190}, {405,395}, {674,457} };
	Point2f dst[4] = { {0.0f,0.0f}, {w,0.0f}, {0.0f,h}, {w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 8, Scalar(0, 0, 255), FILLED);
	}

	imshow("Input Image", img);
	imshow("Image Warp", imgWarp);

	waitKey(0);
}