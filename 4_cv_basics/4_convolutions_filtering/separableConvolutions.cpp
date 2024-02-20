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
#include <opencv2/opencv.hpp>
#include <iostream>
#include "convolution.hpp"     // Our naive implementation of the convolution operation

int main()
{

    // Read input image
    std::string input_path = "./assets/Dog_img.jpeg";
    cv::Mat input = cv::imread(input_path, cv::IMREAD_COLOR);        // Read colored image
    // cv::Mat input = cv::imread(input_path, cv::IMREAD_GRAYSCALE); // Read grayscale image

    // Resize the input image to a more manageable size for demonstration purposes
    cv::resize(input, input, cv::Size(input.cols*0.5, input.rows*0.5));

    // Declare the output image matrix
    cv::Mat output;
    std::cout << "Demonstrating separable convolutions...\n";

    // Define standard 3x3 Gaussian kernel
    cv::Mat gaussian = (cv::Mat_<double>(3, 3) <<
        1. / 16, 2. / 16, 1. / 16,
        2. / 16, 4. / 16, 2. / 16,
        1. / 16, 2. / 16, 1. / 16
    );

    filter2D(input, output, -1, gaussian);              // Convolve with original 'full' kernel

    // Making All Windows resizable
    cv::namedWindow("Output", cv::WINDOW_NORMAL);
    cv::imshow("Output", output);
    cv::waitKey(0); // Wait for key press before moving to the next image

    // Define decomposed standard 3x3 Gaussian kernel
    cv::Mat gaussian_v = (cv::Mat_<double>(3, 1) << 1. / 4, 1. / 2, 1. / 4);
    cv::Mat gaussian_h = (cv::Mat_<double>(1, 3) << 1. / 4, 1. / 2, 1. / 4);

    // Declare matrix to store intermediate image
    cv::Mat intermediate;

    // Now to actually convolve
    intermediate = convolve(input, gaussian_v);         // Convolve Vertically
    output = convolve(intermediate, gaussian_h);        // Convolve Horizontally

    cv::namedWindow("Output by Naive Seperable Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output by Naive Seperable Convolution", output);
    cv::waitKey(0); // Wait for key press before moving to the next image

    cv::namedWindow("Output of Vertical Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Vertical Convolution", intermediate);
    cv::waitKey(0); // Wait for key press before moving to the next image

    cv::namedWindow("Output of Horizontal Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Horizontal Convolution", output);
    cv::waitKey(0); // Wait for key press before exiting

    return 0;
}
