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
    image = imread("PROJECT_SOURCE_DIR/assets/images/morph.png", IMREAD_GRAYSCALE);

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