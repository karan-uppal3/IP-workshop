#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/Downloads/lisa.png",0);

	int i,j,k,l;

	int m = img.rows;
	int n = img.cols;

	Mat a ( m+2 , n+2 , CV_8UC1 , Scalar(0));

	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			a.at<uchar>(i+1,j+1) = img.at<uchar>(i,j);
		}
	}

	Mat b ( m , n , CV_8UC1 , Scalar(0) );

	for ( i = 1 ; i < m+1 ; i++ )
	{
		for ( j = 1 ; j < n+1  ; j++ )
		{
			int arr[9],ctr=0;

			for ( k = i-1 ; k < i+2 ; k++ )
			{
				for ( l = j-1 ; l < j+2 ; l++ )
				{
					arr[ctr++]=a.at<uchar>(k,l);
				}
			}

			nth_element ( arr , arr+4 , arr + 9 );
			b.at<uchar>(i-1,j-1) = arr[4];
		}
	}

	namedWindow ("output",0);
	imshow("output",b);
	waitKey(0);
}