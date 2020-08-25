#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;


int main()
{
	Mat img = imread("/home/karan/Pictures/Webcam/2019-12-07-124858.jpg", 0);
	Mat a ( img.rows , img.cols , CV_8UC1 , Scalar(255) );
	
	int th = 0;
	namedWindow ("output",0);

	createTrackbar ("Tracker","output",&th,255);

	while(1)
	{
		for ( int i = 0 ; i < img.rows ; i++ )
		{
			for ( int j = 0 ; j < img.cols ; j++ )
			{
				if ( img.at<uchar>(i,j) > th )
					a.at<uchar>(i,j) = 255;
				else
					a.at<uchar>(i,j) = 0;
			}
		}
		

		imshow("output",a);	
		
		waitKey(1);                                                   //to refresh the window
	}		
	waitKey(0);                                                           //used as a good coding practice 
}	

