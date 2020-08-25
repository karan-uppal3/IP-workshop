#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread ("fruits.png",1);

	int m = img.rows;
	int n = img.cols;

	int thrmax,thrmin,thbmax,thbmin,thgmax,thgmin;
	thrmax = thrmin = thbmax = thbmin = thgmax = thgmin = 0;
	namedWindow ("output",0);

	createTrackbar ("TrackerRMAX","output",&thrmax,255);
	createTrackbar ("TrackerBMAX","output",&thbmax,255);
	createTrackbar ("TrackerGMAX","output",&thgmax,255);
	createTrackbar ("TrackerRMIN","output",&thrmin,255);
	createTrackbar ("TrackerBMIN","output",&thbmin,255);
	createTrackbar ("TrackerGMIN","output",&thgmin,255);

	while(1)
	{
		Mat a ( m , n , CV_8UC3 , Scalar(0,0,0) );		

		for ( int i = 0 ; i < m ; i++ )
		{
			for ( int j = 0 ; j < n ; j++ )
			{
				if ( img.at<Vec3b>(i,j)[2] < thrmax && img.at<Vec3b>(i,j)[1] < thbmax && img.at<Vec3b>(i,j)[0] < thgmax && img.at<Vec3b>(i,j)[2] > thrmin && img.at<Vec3b>(i,j)[1] > thbmin && img.at<Vec3b>(i,j)[0] > thgmin   )
				{
					for ( int k = 0 ; k < 3 ; k++ )
					{
						a.at<Vec3b>(i,j)[k] = img.at<Vec3b>(i,j)[k] ;
					}
				}
			}
		}
		
		imshow("output",a);	
		
		waitKey(1); 

	}
	
	waitKey(0);
}
