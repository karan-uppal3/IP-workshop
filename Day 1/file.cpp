#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("index.jpeg", 1);
	namedWindow ("output",0);
	imshow("output",img);
	waitKey(0);
}
