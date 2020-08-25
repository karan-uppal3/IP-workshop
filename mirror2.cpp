#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ( "/home/karan/Downloads/wp2660704.jpg" , 1 );

	int m = img.rows;
	int n = img.cols;

	Mat a ( m , n*2 , CV_8UC3 , Scalar(0,0,0) );

	for ( int i = 0 ; i < m ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
		{
			a.at<Vec3b>(i,j)[0] = a.at<Vec3b>(i,2*n-j)[0] = img.at<Vec3b>(i,j)[0];
			a.at<Vec3b>(i,j)[1] = a.at<Vec3b>(i,2*n-j)[1] = img.at<Vec3b>(i,j)[1];
			a.at<Vec3b>(i,j)[2] = a.at<Vec3b>(i,2*n-j)[2] = img.at<Vec3b>(i,j)[2];
		}
	}

	namedWindow ("output",0);
	imshow("output",a);
	waitKey(0);
}
