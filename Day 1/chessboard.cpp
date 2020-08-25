#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat a(64,64,CV_8UC1,Scalar(0));

	for ( int i = 0 ; i < 64 ; i++ )
	{
		for ( int j = 0 ; j < 64 ; j++ )
		{
			if ( (i+j)%2 == 0 )
				a.at<uchar>(i,j) = 255;
			else
				a.at<uchar>(i,j) = 0;
		}
	}

	namedWindow("output",0);
	imshow("output",a);
	waitKey(0);
}
