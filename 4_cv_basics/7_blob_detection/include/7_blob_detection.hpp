#ifndef BLOB_DETECTION_HPP
#define BLOB_DETECTION_HPP

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

double median(vector<double> vec);

tuple<double, double, double> getMedianPixelValues(Mat img);

#endif