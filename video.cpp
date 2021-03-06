#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap (0);

	int th1,th2;
	th1 = th2 = 0;

	namedWindow ("output",0);

	createTrackbar ( "Tracker1" , "output" , &th1 , 255 );
	createTrackbar ( "Tracker2" , "output" , &th2 , 255 );

	while (1)
	{
		Mat img ( 1000 , 1000 , CV_8UC3 , Scalar(0,0,0) );
		cap>>img;

		Mat a ( img.rows , img.cols , CV_8UC3 , Scalar(0,0,0) );

		Canny ( img , a , th1 , th2 );

		imshow("output",a);
		waitKey(1);


	}
}