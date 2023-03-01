#include <iostream>
#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "../helper.hpp"

using namespace cv;
using namespace std;

int main()
{
	// Reading the Image
	Mat source_image = imread("../Assets/closing.png", IMREAD_GRAYSCALE);
	// Check if the image is created
	// successfully or not
	if (!source_image.data)
	{
		cout << "Could not open or find the image\n";
		return 0;
	}
	// creating container for output image according to size and type of source image
	Mat output_image{source_image.size(), source_image.type()};
	// Applying erosion on source image
	int kernel_size = 3;
	output_image = erosion(source_image, output_image, kernel_size);

	// Displaying both source and output image
	namedWindow("source", WINDOW_NORMAL);
	imshow("source", source_image);

	namedWindow("output", WINDOW_NORMAL);
	imshow("output", output_image);

	waitKey();

	return 0;
}
