// Bs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
//#include "opencv2/videoio.hpp"
#include <opencv2\opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video.hpp>
#include <iostream>
#include <sstream>
using namespace cv;
using namespace std;
int main()
{
	Mat frame;
	Mat fgmask;
	int keyboard;
	Ptr<BackgroundSubtractorMOG2> pMOG2;
	pMOG2 = new BackgroundSubtractorMOG2();
	vector<String> file;
	String folder = "Image";
	glob(folder, file);
	int i = 0;
	frame = imread(file[0]);
	if (frame.empty()) {
		cout << "Unable to open first image ";
		return -1;
	}
	namedWindow("Frame");
	namedWindow("Fg mask");
	keyboard = 'r';
	while ((char)keyboard != 'q' && (char)keyboard != 27)
	{
		pMOG2->operator()(frame, fgmask);
		imshow("Frame", frame);
		imshow("Fg mask", fgmask);
		i++;
		frame = imread(file[i]);
		if (!frame.empty())
		{
			return -1;
		}
		keyboard = waitKey(30);
	}
	destroyAllWindows();
	return 0;
}

