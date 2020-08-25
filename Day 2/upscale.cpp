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

	Mat a ( m*4 , n*4 , CV_8UC3 , Scalar(0,0,0) );

	for ( int i = 0 ; i < m ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
		{
			for ( int k = 0 ; k < 3 ; k++ )
			{
				for ( int t = 0 ; t < 4 ; t++ )
				{
					for ( int y = 0 ; y < 4 ; y++ )
					{
						a.at<Vec3b>(4*i+t,4*j+y)[k] = img.at<Vec3b>(i,j)[k];
					}
				}
			}
		}
	}
	
	namedWindow ("output",0);
	imshow("output",a);
	waitKey(0);
}

