#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	int k = 1;
	namedWindow ("output",0);
	createTrackbar ("TrackerK","output",&k,200);

	while(1)
	{
		Mat img = imread ("/home/karan/Downloads/star_wars_the-rise-of-skywalker-2019_facebook_cover.jpg",0);

		int m = img.rows;
		int n = img.cols;

		for ( int i = 0 ; i < m ; i++ )
		{
			for ( int j =  0 ; j < n ; j++ )
			{
				img.at<uchar>(i,j) = float(img.at<uchar>(i,j))*k/100;
				if ( img.at<uchar>(i,j) > 255 )
						img.at<uchar>(i,j) = 255;
			}
		}
		imshow("output",img);
		waitKey(1);
	}
	waitKey(0);
}

