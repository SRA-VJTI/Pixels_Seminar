#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

namespace Pixels
{

    cv::Scalar_<uint8_t> getPixel(cv::Mat img, int y, int x, int channels);
    void setPixel(cv::Mat img, cv::Scalar_<uint8_t> v, int y, int x, int channels);
    cv::Mat bilinear_interpolate(cv::Mat img, int width, int height, int channels);
    cv::Mat nearest_neighbour_interpolate(cv::Mat img, int width, int height, int channels);
    void show(cv::Mat img, std::string windowName);

}