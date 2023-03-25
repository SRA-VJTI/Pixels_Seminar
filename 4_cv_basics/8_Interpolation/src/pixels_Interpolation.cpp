#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include "pixels_Interpolation.hpp"

cv::Scalar_<uint8_t> Pixels::getPixel(cv::Mat imageData, int y, int x, int channels)
{
    /* Fetches the pixel corresponding to the coordinate x,y .
       OpenCV uses BGR Format and this leads to the following convention:

       Returns a cv Scalar_ object of type unisigned integer (0-256)

       Arguments :

       int x : Row number of the pixel indexed from 0
       int y : Column number of the pixel indexed from 0

*/ uint8_t *pixelPtr = (uint8_t *)imageData.data;
    cv::Scalar_<uint8_t> bgrPixel;
    bgrPixel.val[0] = pixelPtr[y * imageData.cols * channels + x * channels + 0];
    bgrPixel.val[1] = pixelPtr[y * imageData.cols * channels + x * channels + 1];
    bgrPixel.val[2] = pixelPtr[y * imageData.cols * channels + x * channels + 2];

    return bgrPixel;
}
void Pixels::setPixel(cv::Mat imageData, cv::Scalar_<uint8_t> v, int y, int x, int channels)
{
    /* Sets the pixel corresponding to the coordinate x,y a .
       OpenCV uses BGR Format and this leads to the following convention:


       Returns a cv Scalar_ object of type unisigned integer (0-256)

       Arguments :
       int v : Value of pixel to be set
       int x : Row number of the pixel indexed from 0
       int y : Column number of the pixel indexed from 0

*/

    uint8_t *pixelPtr = (uint8_t *)imageData.data;
    pixelPtr[y * imageData.cols * channels + x * channels + 0] = v.val[0];
    pixelPtr[y * imageData.cols * channels + x * channels + 1] = v.val[1];
    pixelPtr[y * imageData.cols * channels + x * channels + 2] = v.val[2];
}

cv::Mat Pixels::bilinear_interpolate(cv::Mat imageData, int width, int height, int channels)
{
    int x_l, y_l, x_h, y_h;
    float x_weight, y_weight;
    cv::Mat newImage = cv::Mat::zeros(cv::Size(width, height), CV_8UC3);
    double x_ratio = (double)(imageData.cols - 1) / (width - 1);
    double y_ratio = (double)(imageData.rows - 1) / (height - 1);

    cv::Scalar_<uint8_t> a, b, c, d, pixel;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            x_l = std::floor(x_ratio * j);
            y_l = std::floor(y_ratio * i);
            x_h = std::ceil(x_ratio * j);
            y_h = std::ceil(y_ratio * i);

            x_weight = (x_ratio * j - x_l);
            y_weight = (y_ratio * i - y_l);

            a = getPixel(imageData, y_l, x_l, channels);
            b = getPixel(imageData, y_l, x_h, channels);
            c = getPixel(imageData, y_h, x_l, channels);
            d = getPixel(imageData, y_h, x_h, channels);
            for (int k = 0; k < channels; k++)
            {

                pixel.val[k] = a.val[k] * (1 - x_weight) * (1 - y_weight) + b.val[k] * (x_weight) * (1 - y_weight) + c.val[k] * (1 - x_weight) * (y_weight) + d.val[k] * (x_weight) * (y_weight);
            }
            setPixel(newImage, pixel, i, j, channels);
        }
    }
    return newImage;
}

cv::Mat Pixels::nearest_neighbour_interpolate(cv::Mat imageData, int width, int height, int channels)
{

    cv ::Mat newImage = cv::Mat::zeros(cv::Size(width, height), CV_8UC3);
    double x_ratio = (double)(imageData.cols - 1) / (width - 1);
    double y_ratio = (double)(imageData.rows - 1) / (height - 1);

    cv::Scalar_<uint8_t> nearest_pixel, pixel;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            nearest_pixel = getPixel(imageData, std::round(i * y_ratio), std::round(j * x_ratio), channels);

            for (int k = 0; k < channels; k++)
            {

                pixel.val[k] = nearest_pixel.val[k];
            }
            setPixel(newImage, pixel, i, j, channels);
        }
    }
    return newImage;
}

void Pixels::show(cv::Mat imageData, std::string windowName)
{
    cv::namedWindow(windowName);
    cv::imshow(windowName, imageData);
    cv::waitKey(0);
    cv::destroyWindow(windowName);
}
