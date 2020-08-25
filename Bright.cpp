#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("/home/karan/IP-Workshop/index.jpeg",0);

	int i,j,k,l,th;

	int m = img.rows;
	int n = img.cols;

	namedWindow ("output",0);
	createTrackbar ("Bright","output",&th,100);	

	while(1)
	{
		Mat a ( m , n , CV_8UC1 , Scalar(0) );

		for ( i = 0 ; i < m ; i++ )
		{
			for ( j = 0 ; j < n ; j++ )
			{
				int k = img.at<uchar>(i,j) + th;

				if ( k > 255 )
					k = 255;

				a.at<uchar>(i,j) = k;
			}
		}

		imshow("output",a);
		waitKey(1);
	}

	waitKey(0);
}