/*
MIT License

Copyright (c) 2023 Society of Robotics and Automation

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// Function for erosion
Mat erosion(Mat input, int kernel_size)
{
    Mat erode_output;
    erode(input, erode_output, getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size)));
    return erode_output;
}

// Function for dilation
Mat dilation(Mat input, int kernel_size)
{
    Mat dilate_output;
    dilate(input, dilate_output, getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size)));
    return dilate_output;
}

// Function for opening
Mat open(Mat input, int kernel_size)
{
    Mat open_output;
    morphologyEx(input, open_output, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size)));
    return open_output;
}

// Function for closing
Mat close(Mat input, int kernel_size)
{
    Mat close_output;
    morphologyEx(input, close_output, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size)));
    return close_output;
}

// Function for gradient
Mat gradient(Mat input, int kernel_size)
{
    Mat gradient_output;
    morphologyEx(input, gradient_output, MORPH_GRADIENT, getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size)));
    return gradient_output;
}

int main()
{
    Mat image;
    // Reading image, in grayscale colorspace
    image = imread("./assets/images/morph.png", IMREAD_GRAYSCALE);

    // Resultant morphological transformation (change function name & kernel size)
    Mat res = erosion(image, 5);

    // Displaying source image
    namedWindow("Source");
    imshow("Source", image);

    // Displaying transformed image
    namedWindow("Morphology");
    imshow("Morphology", res);
    waitKey(0);
    return 0;
}
