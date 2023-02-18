#ifndef HELPER_HPP
#define HELPER_HPP

#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;

/*
/ @brief finds sum of elements in a kernel about given co-ordinate(y, x)
/ @param Mat image
/ @param row (y)
/ @param col (x)
/ @param Kernel size
/ @return sum
*/
int kernel_sum(Mat image, int row, int col, int Kernel_size);

/*
/ @brief performs erosion on source image and stores it in output image
/ @param Mat source_image
/ @param Mat output_image
/ @param int Kernel size
/ @return output_image after erosion
*/
Mat erosion(Mat source_image, Mat output_image, int Kernel_size);

/*
/ @brief performs dilation on source image and stores it in output image
/ @param Mat source_image
/ @param Mat output_image
/ @param kernel size
/ @return output_image after erosion
*/
Mat dilation(Mat source_image, Mat output_image, int kernel_size);

/*
/ @brief Gives difference between two given arrays
/ @param img_1 input image
/ @param img_2 input image
/ @param output container to store output image
/ @return output image
*/
Mat difference(Mat img_1, Mat img_2, Mat output);

#endif // !HELPER_HPP