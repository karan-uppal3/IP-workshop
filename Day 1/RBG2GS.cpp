#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ( "index.jpeg" , 1 );

	int m = img.rows;
	int n = img.cols;

	Mat a ( m , n , CV_8UC1 , Scalar(0) );

	for ( int i = 0 ; i < m ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
		{
			a.at<uchar>(i,j) = 0.21*img.at<Vec3b>(i,j)[2] + 0.72*img.at<Vec3b>(i,j)[1] + 0.07*img.at<Vec3b>(i,j)[0];
		}
	}

	namedWindow ("output",0);
	imshow("output",a);
	waitKey(0);
}
