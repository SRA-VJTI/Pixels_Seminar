#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include "convolution.hpp"

int main()
{
    /* To demonstrate convolutions using separable kernels,
     * we will first convolve an image using a regular gaussian
     * kernel, then we will convolve the same original image
     * with the decomposed kernel and compare the results.
     */
    
    std::cout << "Demonstrating separable convolutions...\n";

    // Read input image
    std::string input_path = "./assets/test.png";
    cv::Mat input = cv::imread(input_path);

    // Define standard 3x3 Gaussian kernel
    cv::Mat gaussian = (cv::Mat_<double>(3, 3) <<
        1. / 16, 2. / 16, 1. / 16,
        2. / 16, 4. / 16, 2. / 16,
        1. / 16, 2. / 16, 1. / 16
    );

    auto start = std::chrono::high_resolution_clock::now();  // Start clock to time execution
    cv::Mat output = convolve(gaussian, input);              // Convolve
    auto stop = std::chrono::high_resolution_clock::now();   // Stop clock

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Regular convolution took " << duration.count() << " microseconds.\n";

    cv::imshow("Output", output);
    cv::waitKey(0);

    // Define decomposed standard 3x3 Gaussian kernel
    cv::Mat gaussian_v = (cv::Mat_<double>(3, 1) << 1. / 4, 1. / 2, 1. / 4);
    cv::Mat gaussian_h = (cv::Mat_<double>(1, 3) << 1. / 4, 1. / 2, 1. / 4);

    start = std::chrono::high_resolution_clock::now();   // Start clock to time execution
    cv::Mat output_v = convolve(gaussian_v, input);      // Convolve with vertical 'half' kernel
    cv::Mat output_vh = convolve(gaussian_h, output_v);  // Convolve with horizontal 'half' kernel
    stop = std::chrono::high_resolution_clock::now();    // Stop clock

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Separated convolution took " << duration.count() << " microseconds.\n";

    cv::imshow("Output of first 'half'", output_v);
    cv::waitKey(0);

    cv::imshow("Output of first 'half'", output_vh);
    cv::waitKey(0);

    return 0;
}