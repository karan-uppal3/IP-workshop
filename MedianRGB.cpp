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
				int arr[9],ctr=0;

				for ( k = i-1 ; k < i+2 ; k++ )
				{
					for ( l = j-1 ; l < j+2 ; l++ )
					{
						arr[ctr++]=a.at<Vec3b>(k,l)[o];
					}
				}

				nth_element ( arr , arr+4 , arr + 9 );
				b.at<Vec3b>(i-1,j-1)[o] = arr[4];
			}
		}
	}

	namedWindow ("output",0);
	imshow("output",b);
	waitKey(0);
}