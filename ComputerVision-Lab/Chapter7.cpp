#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void getContours(Mat imgDil, Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	// Save Conner Point in Polygon: If square has 4 Points, triangle has 3 Points,...
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objType;

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		if (area > 1000)
		{
			// Caculate the number of corner of Polygon
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			// Draw Bounding box
			boundRect[i] = boundingRect(conPoly[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 3);

			// Number of corner that obj has
			int objCor = (int) conPoly[i].size();
			// Classification Polygon
			if (objCor == 3) { objType = "Tri"; }
			if (objCor == 4) { 
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objType = "Square"; }
				else objType = "Rect"; 
			}
			if (objCor > 4) { objType = "Circle"; }
			putText(img, objType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 0.75, Scalar(0, 69, 255), 1);
		}
	}
}




// ============ Detect Shapes ==================

void main()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	imshow("Input Image", img);
	// 1. Pre-processing
	Mat imgGray, imgBlur, imgCanny, imgDil;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);// Blur
	Canny(imgBlur, imgCanny, 25, 75); // Canny Detection
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));// Dilation 
	dilate(imgCanny, imgDil, kernel);
	
	// Get Contours
	getContours(imgDil, img);

	imshow("Output Image", img);
	/*imshow("image gray", imgGray);
	imshow("image blur", imgBlur);
	imshow("image canny", imgCanny);
	imshow("image dilated", imgDil);*/


	waitKey(0);
}