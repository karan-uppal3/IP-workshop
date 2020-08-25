#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/IP-Workshop/fruits.png",0);

	int m = img.rows;
	int n = img.cols;

	int i,j,th=0;

	Mat a ( m+2 , n+2 , CV_8UC1 , Scalar(0) );

	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			a.at<uchar>(i+1,j+1) = img.at<uchar>(i,j);
		}
	}

	namedWindow ("output",0);
	createTrackbar ( "tracker" , "output" , &th , 500 );

	while(1)
	{
		Mat b ( m , n , CV_8UC1 , Scalar(0) );

		for ( i = 1 ; i < m+1 ; i++ )
		{
			for ( j = 1 ; j < n+1 ; j++ )
			{	
				float gy = a.at<uchar>(i+1,j-1) + a.at<uchar>(i+1,j) + a.at<uchar>(i+1,j) - a.at<uchar>(i-1,j-1) - a.at<uchar>(i-1,j) - a.at<uchar>(i-1,j+1); 
				float gx = a.at<uchar>(i-1,j+1) + a.at<uchar>(i,j+1) + a.at<uchar>(i-1,j+1) - a.at<uchar>(i-1,j-1) - a.at<uchar>(i,j-1) - a.at<uchar>(i+1,j-1); 
			
				float k = sqrt( gx*gx + gy*gy );

				if ( k > th )
					k = 255;
				else 
					k = 0;
			
				b.at<uchar>(i-1,j-1) = k;
			}
		}
		imshow("output",b);
		waitKey(1);
	}
}