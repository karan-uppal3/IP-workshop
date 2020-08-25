#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/IP-Workshop/index.jpeg",1);

	int i,j,k,l;

	int m = img.rows;
	int n = img.cols;

	Mat a ( m+2 , n+2 , CV_8UC3 , Scalar(0,0,0));

	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			for ( k = 0 ; k < 3 ; k++ )
			{
				a.at<Vec3b>(i+1,j+1)[k] = img.at<Vec3b>(i,j)[k];
			}
		}
	}

	Mat b ( m , n , CV_8UC3 , Scalar(0,0,0) );

	for ( int o = 0 ; o < 3 ; o++ )
	{
		for ( i = 1 ; i < m+1 ; i++ )
		{
			for ( j = 1 ; j < n+1  ; j++ )
			{
				float sum = float(a.at<Vec3b>(i-1,j-1)[o])/16 + float(a.at<Vec3b>(i-1,j)[o])/8 + float(a.at<Vec3b>(i-1,j+1)[o])/16 + float(a.at<Vec3b>(i,j-1)[o])/8 + float(a.at<Vec3b>(i,j)[o])/4 + float(a.at<Vec3b>(i,j+1)[o])/8 + float(a.at<Vec3b>(i+1,j-1)[o])/16 + float(a.at<Vec3b>(i+1,j)[o])/8 + float(a.at<Vec3b>(i+1,j+1)[o])/16;
				b.at<Vec3b>(i-1,j-1)[o] = sum;
			}
		}
	}

	namedWindow ("output",0);
	imshow("output",b);
	waitKey(0);
}