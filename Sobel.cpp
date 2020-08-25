#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/Downloads/sobel1.jpg",0);

	int m = img.rows;
	int n = img.cols;

	int i,j;

	Mat a ( m+2 , n+2 , CV_8UC1 , Scalar(0) );

	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			a.at<uchar>(i+1,j+1) = img.at<uchar>(i,j);
		}
	}

	Mat hor ( m , n , CV_8UC1 , Scalar(0) );

	for ( i = 1 ; i < m+1 ; i++ )
	{
		for ( j = 1 ; j < n+1 ; j++ )
		{
			int k = a.at<uchar>(i+1,j-1) + 2*a.at<uchar>(i+1,j) + a.at<uchar>(i+1,j) - a.at<uchar>(i-1,j-1) - 2*a.at<uchar>(i-1,j) - a.at<uchar>(i-1,j+1); 
			if ( k > 255 )
				k = 255;
			else if ( k < 0 )
				k = 0;
			
			hor.at<uchar>(i-1,j-1) = k;
		}
	}

	namedWindow ("outputh",0);
	imshow("outputh",hor);

	Mat ver ( m , n , CV_8UC1 , Scalar(0) );

	for ( i = 1 ; i < m+1 ; i++ )
	{
		for ( j = 1 ; j < n+1 ; j++ )
		{
			int k = a.at<uchar>(i-1,j+1) + 2*a.at<uchar>(i,j+1) + a.at<uchar>(i-1,j+1) - a.at<uchar>(i-1,j-1) - 2*a.at<uchar>(i,j-1) - a.at<uchar>(i+1,j-1); 
			if ( k > 255 )
				ver.at<uchar>(i-1,j-1) = 255;
			else if ( k < 0 )
				ver.at<uchar>(i-1,j-1) = 0;
			else
				ver.at<uchar>(i-1,j-1) = k;
		}
	}	

	namedWindow ("outputv",0);
	imshow("outputv",ver);
	waitKey(0);

}