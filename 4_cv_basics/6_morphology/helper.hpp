#ifndef HELPER_HPP
#define HELPER_HPP

#include <opencv2/core.hpp>

using namespace cv;

/*
/ @brief finds sum of elements in 3x3 kernel about given co-ordinate(y, x)
/ @param Mat image
/ @param row (y)
/ @param col (x)
/ @return sum
*/
int kernel_sum(Mat image, int row, int col,int Kernel_size)
{
	int sum = 0;
	int kernel = ((Kernel_size-1)/2);
	for (int i = row - kernel; i <= row + kernel; i++)
	{
		for (int j = col - kernel; j <= col + kernel; j++)
		{
			if (i >= 0 && j >= 0 && i < image.rows && j < image.cols)
			{
				sum = sum + (int)image.at<u_char>(i,j);
			}
			else
			{
				sum = sum;
			}	
		}
	}
	return sum;
}

/*
/ @brief performs erosion on source image and stores it in output image
/ @param Mat source_image
/ @param Mat output_image
/ @return output_image after erosion
*/
Mat erosion(Mat source_image, Mat output_image,int Kernel_size)
{
	for (int i = 0; i < source_image.rows; i++)
	{
		for (int j = 0; j < source_image.cols; j++)
		{
			if (kernel_sum(source_image, i, j,Kernel_size) != 255*9)
			{
				output_image.at<u_char>(i,j) = saturate_cast<char>(0);
			}
			else
			{
				output_image.at<u_char>(i,j) = saturate_cast<char>(255);
			}
		}
	}

	return output_image;
}


/*
/ @brief performs dilation on source image and stores it in output image
/ @param Mat source_image
/ @param Mat output_image
/ @return output_image after erosion
*/
Mat dilation(Mat source_image, Mat output_image,int kernel_size)
{
	for (int i = 0; i < source_image.rows; i++)
	{
		for (int j = 0; j < source_image.cols; j++)
		{
			if (kernel_sum(source_image, i, j,kernel_size) > 0)
			{
				output_image.at<u_char>(i,j) = saturate_cast<char>(255);
			}
			else
			{
				output_image.at<u_char>(i,j) = saturate_cast<char>(0);
			}
		}
	}

	return output_image;
}



/*
/ @brief Gives difference between two given arrays
/ @param img_1 input image
/ @param img_2 input image
/ @param output container to store output image
/ @return output image
*/
Mat difference(Mat img_1, Mat img_2, Mat output)
{	
	if (img_1.size() != img_2.size())
	{
		std::cout<<"Images are of different sizes."<<std::endl;
	
	}
	for (int i = 0; i < img_1.rows; i++)
	{
		for (int j = 0; j < img_1.cols; j++)
		{
			output.at<u_char>(i, j) = saturate_cast<char>((abs)((int)img_1.at<u_char>(i, j) - (int)img_2.at<u_char>(i, j)));
		}	
	}
	return output;
}

/*
/ @brief Gives padded image to prevent pixel loss
/ @param image input image
/ @param output output image
/ @param pad padding
/ @return output image
*/
Mat padding(Mat image,int pad, Mat output)
{
	copyMakeBorder(image, output, pad, pad, pad, pad, BORDER_CONSTANT, Scalar(0));
	return output;
}


#endif // !HELPER_HPP
