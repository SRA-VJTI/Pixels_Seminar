#include "pixels_Interpolation.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace Pixels;

int main(int argc, char **argv)
{
    cv::Mat image = cv::imread("../Assets/pixel1.jpg");
    cv::Mat upscale_image  = nearest_neighbour_interpolate(image,1000, 1000, 3);
    cv::Mat downscale_image  =nearest_neighbour_interpolate(image , 100, 100, 3);
    cv::imwrite("../Assets/pixeli3s.jpg",upscale_image);
    cv:: imwrite( "../Assets/pixeli3d.jpg",downscale_image);
    show(upscale_image , "Interpolation UpScaling!");
    show(downscale_image , "Interpolation DownScaling!");
}