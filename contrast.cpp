#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	int th = 0,k = 0;
	namedWindow ("output",0);

	createTrackbar ("TrackerT","output",&th,255);
	createTrackbar ("TrackerK","output",&k,50);

	while(1)
	{
		Mat img = imread ("/home/karan/Pictures/Webcam/2019-12-07-124858.jpg",0);

		int m = img.rows;
		int n = img.cols;

		for ( int i = 0 ; i < m ; i++ )
		{
			for ( int j =  0 ; j < n ; j++ )
			{
				if ( img.at<uchar>(i,j) > th )
				{
					img.at<uchar>(i,j) += k;
					if ( img.at<uchar>(i,j) > 255 )
						img.at<uchar>(i,j) = 255;
				}
				else
				{
					img.at<uchar>(i,j) -= k;
					if ( img.at<uchar>(i,j) < 0 )
						img.at<uchar>(i,j) = 0;
				}
			}
		}
		imshow("output",img);
		waitKey(1);
	}
	waitKey(0);
}
