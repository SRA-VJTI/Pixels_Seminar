#include "interpolation.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
    cv::Mat image = cv::imread("../assets/pixel3.jpg");                          // Reading image
    cv::Mat downscale_image = nearest_neighbour_interpolate(image, 100, 100, 3); // Performing nearest neighbour interpolation on image
    cv::Mat upscale_image = bilinear_interpolate(image, 1000, 1000, 3);          // Performing bilinear interpolation on image
    cv::imwrite("../assets/pixeli3s.jpg", upscale_image);                        // Saving image
    cv::imwrite("../assets/pixeli3d.jpg", downscale_image);                      // Saving image
    show(upscale_image, "Interpolation UpScaling!");                             // show image using show function defined in interpolation.cpp
    show(downscale_image, "Interpolation DownScaling!");                         // show image using show function defined in interpolation.cpp
}