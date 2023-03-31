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

int main()
{
    // Load two images
    Mat img1 = imread("./assets/images/DK.jpeg");
    Mat img2 = imread("./assets/images/bcci.png");
    imshow("Image1", img1);

    // Getting the height, width and number of channels of the image
    // Creating ROI to put the logo on top - left corner
    int rows = img2.rows, cols = img2.cols, channels = img2.channels();

    // Cropping the img1
    Mat roi = img1(Rect(0, 0, rows, cols)).clone();

    // Converting the image to grayscale
    // Creating a mask of logo and create its inverse mask also
    Mat img2gray;
    cvtColor(img2, img2gray, COLOR_BGR2GRAY);

    // each pixel having value more than 180(threshold)will be set to white i.e max_value(255) for a mask / HIGH
    // pixel values lower than threshold are set
    Mat mask;
    threshold(img2gray, mask, 180, 255, THRESH_BINARY);

    // inverting colors
    Mat mask_inv;
    bitwise_not(mask, mask_inv);

    // Resizing mask
    resize(mask, mask, roi.size());

    // Blacking-out the area of logo in ROI
    Mat img1_bg;
    bitwise_and(roi, roi, img1_bg, mask);

    // Take only region of logo from logo image.
    Mat img2_fg;
    bitwise_and(img2, img2, img2_fg, mask_inv);

    Mat img2_fg_resized;
    resize(img2_fg, img2_fg_resized, roi.size());

    // Put logo in ROI and modify the main image
    Mat dst;
    add(img1_bg, img2_fg_resized, dst);

    dst.copyTo(img1(Rect(0, 0, rows, cols)));

    imshow("Image2", img2);
    imshow("ROI", roi);
    imshow("Gray", img2gray);
    imshow("mask", mask);
    imshow("mask_inv", mask_inv);
    imshow("BG", img1_bg);
    imshow("FG", img2_fg);
    imshow("dst", img1);
    waitKey(0);
}
