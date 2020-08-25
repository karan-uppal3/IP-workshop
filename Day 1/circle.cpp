#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat a ( 501 , 501 , CV_8UC3 , Scalar (255,0,0));

	for ( int i = 0 ; i < 501 ; i++ )
	{
		for ( int j = 0 ; j < 501 ; j++ )
		{
			if ( (i-250)*(i-250) + (j-250)*(j-250) <= 20000 )	
			{	
				a.at<Vec3b>(i,j)[1] = 255;
				a.at<Vec3b>(i,j)[0] = 0;
			}
		}
	}

	namedWindow ("output",0);
	imshow("output",a);
	waitKey(0);
} 
