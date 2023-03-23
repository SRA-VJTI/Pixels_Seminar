#include <iostream>
#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "../include/helper.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./output <Image_Path>\n";
		return -1;
	}

	// Reading the Image
	Mat source_image = imread(argv[1], IMREAD_GRAYSCALE);

	// Check if the image is created successfully or not
	if (!source_image.data)
	{
		std::cout << "Could not open or find the image\n";
		return 0;
	}

	// creating container for output image according to size and type of source image
	Mat erod{source_image.size(), source_image.type()};
	Mat dill{source_image.size(), source_image.type()};
    Mat gradient{source_image.size(), source_image.type()};

	// Applying erosion on source image
	int kernel_size_erosion = 3;
	erod = erosion(source_image, erod, kernel_size_erosion);

	// Applying dilation on source image
	int kernel_size_dilation = 3;
	dill = dilation(source_image, dill, kernel_size_dilation);

	// Taking difference of erroded and dilated image to get gradient
	gradient = difference(dill, erod, gradient);

	//Displaying both source and output image
	namedWindow("source", WINDOW_NORMAL);
	imshow("source", source_image);
	
	namedWindow("gradient", WINDOW_NORMAL);
	imshow("gradient", gradient);

	waitKey();

	return 0;
}
