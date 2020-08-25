#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/Downloads/star_wars_the-rise-of-skywalker-2019_facebook_cover.jpg",1);

	int m = img.rows;
	int n = img.cols;

	Mat a ( m+2 , n+2 , CV_8UC3 , Scalar(0,0,0));

	for ( int i = 0 ; i < m ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
		{
			for ( int k  = 0 ; k < 3 ; k++ )
			{
				a.at<Vec3b>(i+1,j+1)[k] = img.at<Vec3b>(i,j)[k];
			}
		}
	}

	namedWindow ("output",0);
	imshow("output",a);
	waitKey(0);
}


	