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
#include <chrono>              // To time execution - Benchmarking
#include "convolution.hpp"     // Our naive implementation of the convolution operation

int main()
{
    /* 
     * To demonstrate an example of a naive, suboptimal
     * implementation of the convolution operation, we will
     * compare its results with the in-built OpenCV
     * convolution function, `filter2D`. You can make changes
     * (improvements, preferably :P) to the naive implementation
     * to see how close you can get.
     */

    std::cout << "Demonstrating naive convolution...\n";

    // Read input image
    std::string input_path = "./assets/Dog_img.jpeg";
    cv::Mat input = cv::imread(input_path, cv::IMREAD_COLOR);        // Read colored image
    // cv::Mat input = cv::imread(input_path, cv::IMREAD_GRAYSCALE); // Read grayscale image

    // Resize the input image to a more managable size for demonstration purposes
    cv::resize(input, input, cv::Size(input.cols*0.5, input.rows*0.5));

    // Create a 3x3 Sobel kernel
    cv::Mat sobel = (cv::Mat_<double>(3, 3) <<
        -1., 0., 1.,
        -2., 0., 2.,
        -1., 0., 1.
    );

    // Declare the output image matrix
    cv::Mat output;

    // This is just one way to create a cv::Mat, some other ways are:
    // cv::Mat kernel;                        // Declaration
    // kernel.create(3, 3, CV_8UC(2));        // Creates an empty 3x3 matrix
    // kernel = cv::Mat::ones(4, 4, CV_64F);  // Creates a 4x4 unit matrix
    // kernel = cv::Mat::eye(3, 3, CV_64F);   // Creates a 3x3 indentity matrix

    /*
     * Some notes about how these functions work:
     * As you may have noticed, the first two arguments here
     * specify the dimensions of the matrix, while the third
     * seems a little more cryptic. It is a type specification; with
     * format CV_[Bits][(S)igned/(U)nsigned/(F)loat][C[Channel No.]]
     */

    // Making All Windows resizable
    cv::namedWindow("Naive output", cv::WINDOW_NORMAL);
    cv::namedWindow("filter 2D output", cv::WINDOW_NORMAL);

    // Now to actually convolve
    auto start = std::chrono::high_resolution_clock::now();  // Start clock to time execution
    output = convolve(input, sobel);                         // Convolve
    auto stop = std::chrono::high_resolution_clock::now();   // Stop clock

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Naive convolution took " << duration.count() << " microseconds.\n";

    cv::imshow("Naive output", output);

    // And using the built-in function
    start = std::chrono::high_resolution_clock::now();
    cv::filter2D(input, output, -1, sobel, cv::Point(-1, -1), 5.0, cv::BorderTypes::BORDER_REPLICATE);
    stop = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Convolution using filter2D took " << duration.count() << " microseconds.\n";

    cv::imshow("filter 2D output", output);
    cv::waitKey(0);

    std::cout << '\n';

    /* To demonstrate convolutions using separable kernels,
     * we will first convolve an image using a regular gaussian
     * kernel, then we will convolve the same original image
     * with the decomposed kernel and compare the results.
     */
    
    std::cout << "Demonstrating separable convolutions...\n";

    // Define standard 3x3 Gaussian kernel
    cv::Mat gaussian = (cv::Mat_<double>(3, 3) <<
        1. / 16, 2. / 16, 1. / 16,
        2. / 16, 4. / 16, 2. / 16,
        1. / 16, 2. / 16, 1. / 16
    );

    start = std::chrono::high_resolution_clock::now();
    filter2D(input, output, -1, gaussian);              // Convolve with original 'full' kernel
    stop = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Regular convolution took " << duration.count() << " microseconds.\n";

    // Making All Windows resizable
    cv::namedWindow("Output", cv::WINDOW_NORMAL);

    cv::imshow("Output", output);

    // Define decomposed standard 3x3 Gaussian kernel
    cv::Mat gaussian_v = (cv::Mat_<double>(3, 1) << 1. / 4, 1. / 2, 1. / 4);
    cv::Mat gaussian_h = (cv::Mat_<double>(1, 3) << 1. / 4, 1. / 2, 1. / 4);

    // Declare matrix to store intermediate image
    cv::Mat intermediate;

    // Making All Windows resizable
    cv::namedWindow(" Output by Naive Seperable Convolution ", cv::WINDOW_NORMAL);

    // Now to actually convolve
    start = std::chrono::high_resolution_clock::now();  // Start clock to time execution
    intermediate = convolve(input, gaussian_v);         // Convolve Vertically
    output = convolve(intermediate, gaussian_h);        // Convolve Horizontally
    stop = std::chrono::high_resolution_clock::now();   // Stop clock

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Naive Seperated Convolution " << duration.count() << " microseconds.\n";

    cv::imshow(" Output by Naive Seperable Convolution ", output);
    cv::waitKey(0);

    cv::namedWindow("Output of Vertical Convolution", cv::WINDOW_NORMAL);
    cv::namedWindow("Output of Horizontal Convolution", cv::WINDOW_NORMAL);

    start = std::chrono::high_resolution_clock::now();
    cv::filter2D(input, intermediate, -1, gaussian_v);   // Convolve with vertical 'half' kernel
    cv::filter2D(intermediate, output, -1, gaussian_h);  // Convolve with horizontal 'half' kernel
    stop = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Separated convolution took " << duration.count() << " microseconds.\n";

    cv::imshow("Output of Vertical Convolution", intermediate);

    cv::imshow("Output of Horizontal Convolution", output);
    cv::waitKey(0);
    
    return 0;

}

