#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/Downloads/erosion3.png",0);

	int i,j,k,l;

	int m = img.rows;
	int n = img.cols;

	Mat a ( m+2 , n+2 , CV_8UC1 , Scalar(0));
	Mat b ( m , n , CV_8UC1 , Scalar(0) );

	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			b.at<uchar>(i,j) = img.at<uchar>(i,j);
			a.at<uchar>(i+1,j+1) = img.at<uchar>(i,j);
		}
	}

	for ( i = 1 ; i < m+1 ; i++ )
	{
		for ( j = 1 ; j < n+1  ; j++ )
		{
			int ctr  = 0;

			for ( k = i-1 ; k < i+2 ; k++ )
			{
				for ( l = j-1 ; l < j+2 ; l++ )
				{
					if ( a.at<uchar>(k,l) == 0 )
					{
							ctr++;
					}
				}
			}

			if ( ctr > 0 )
				b.at<uchar>(i-1,j-1) = 0;
		}
	}

	namedWindow ("output",0);
	imshow("output",b);
	waitKey(0);
}