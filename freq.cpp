#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/Downloads/wp2660704.jpg",0);

	int m = img.rows;
	int n = img.cols;

	long long int freq[256];
	int i,j;

	for ( i = 0 ; i < 256 ; i++ )
		freq[i] == 0;

	for ( i = 0 ; i < m ; i++ )
	{
		for ( j =  0 ; j < n ; j++ )
		{
			freq[img.at<uchar>(i,j)]++;
		}
	}

	for ( i = 0 ; i < 256 ; i++ )
		freq[i] = freq[i]/10;

	Mat a ( m*n/100 , 512 , CV_8UC1 , Scalar(0));

	for ( j = 0 ; j < 512 ; j+=2 )
	{
		for ( i = 0 ; i < m*n/100 - freq[j/2] ; i++ )
		{
			a.at<uchar>(i,j) = 255;
			a.at<uchar>(i,j+1) = 255;
		}

	}

	namedWindow ("output",0);
	imshow("output",a);
	waitKey(0);

	return 0;
}