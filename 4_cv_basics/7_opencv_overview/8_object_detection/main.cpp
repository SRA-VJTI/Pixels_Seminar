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

using namespace std;
using namespace cv;

int main()
{
    // Read image
    Mat img = imread("./assets/images/DK.jpeg");
    imshow("Image", img);

    // Convert image to hsv
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);
    imshow("HSV", hsv);

    // hsv format -> (min hue, min saturation , min value) -> (max hue, max saturation , max value)
    // RED mask =>
    // Mat mask1 = inRange(hsv, Scalar(0, 100, 0), Scalar(10, 255, 255));

    // YELLOW mask =>

    Mat mask1;
    inRange(hsv, Scalar(15, 30, 150), Scalar(36, 255, 255), mask1);
    imshow("mask1", mask1);

    // BLUE mask =>
    Mat mask2;
    inRange(hsv, Scalar(33, 52, 80), Scalar(150, 200, 255), mask2);
    imshow("mask2", mask2);

    // Final mask and masked
    Mat mask;
    bitwise_or(mask1, mask2, mask);
    imshow("mask", mask);

    Mat target;
    bitwise_and(img, img, target, mask);
    imshow("target", target);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
