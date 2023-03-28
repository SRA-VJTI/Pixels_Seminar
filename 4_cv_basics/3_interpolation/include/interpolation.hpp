#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

cv::Scalar_<uint8_t> getPixel(cv::Mat img, int y, int x, int channels);                  // declaration of getPixel used to get pixel value
void setPixel(cv::Mat img, cv::Scalar_<uint8_t> v, int y, int x, int channels);          // declaration of setPixel used to set pixel value
cv::Mat bilinear_interpolate(cv::Mat img, int width, int height, int channels);          // declaration of bilinear_interpolate to resize image using bilinear interpolation
cv::Mat nearest_neighbour_interpolate(cv::Mat img, int width, int height, int channels); // declaration of nearest_neighbour_interpolate to resize image using nearest neighbour
void show(cv::Mat img, std::string windowName);                                          // declaration of show utility function to easily show an image Matrix
