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

	Mat a ( m*3 , n*3 , CV_8UC3 , Scalar(0,0,0) );

	for ( int i = 0 ; i < m ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
		{
			for ( int k = 0 ; k < 3 ; k++ )
			{
				for ( int t = 0 ; t < 3 ; t++ )
				{
					for ( int y = 0 ; y < 3 ; y++ )
					{
						a.at<Vec3b>(3*i+t,3*j+y)[k] = img.at<Vec3b>(i,j)[k];
					}
				}
			}
		}
	}

	m *= 3;
	n *= 3;
	
	Mat b ( m/2 , n/2 , CV_8UC3 , Scalar(0,0,0) );

	for ( int k = 0 ; k < 3 ; k++ )
	{
		for ( int i = 0 ; i < m/2 ; i++ )
		{
			for ( int j = 0 ; j < n/2 ; j++ )
			{
				int sum = 0;
				for ( int t = 0 ; t < 2 ; t++ )
				{
					for ( int y = 0 ; y < 2 ; y++ )
					{
						sum += a.at<Vec3b>(2*i+t,2*j+y)[k];
					}
				}
				b.at<Vec3b>(i,j)[k] = sum/4;
			}

		}
	}

	namedWindow ("output",0);
	imshow("output",b);
	waitKey(0);
}

