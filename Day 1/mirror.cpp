#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("/home/karan/Downloads/wp2660704.jpg", 1);

	for ( int i = 0 ; i < img.rows ; i++ )
		for ( int j = 0 ; j < img.cols/2 ; j++ )
		{
			for ( int k = 0 ; k < 3 ; k++ )
			{
				int temp = img.at<Vec3b>(i,j)[k];
				img.at<Vec3b>(i,j)[k] = img.at<Vec3b>(i,img.cols-j)[k];
				img.at<Vec3b>(i,img.cols-j)[k] = temp;
			}
		}	


	namedWindow ("output",0);
	imshow("output",img);
	waitKey(0);
}
