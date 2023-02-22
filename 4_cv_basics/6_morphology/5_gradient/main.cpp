#include <iostream>
#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "helper.hpp"

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{

    if (argc != 2)
    {
        std::cout <<"usage: gradient.out <Image_Path>\n";
        return -1;
    }
    
	// Reading the Image
	Mat source_image = imread(argv[1],IMREAD_GRAYSCALE);

	// Check if the image is created
	// successfully or not
	if (!source_image.data) {
		std::cout << "Could not open or find the image\n";
		return 0;
	}

	Mat erod{source_image.size(), source_image.type()};
	Mat dill{source_image.size(), source_image.type()};
	Mat gradient{source_image.size(), source_image.type()};

	// For Erosion
	erod = erosion(source_image, erod);

	// For Dilation
	dill = dilation(source_image, dill);

    // For gradient
    gradient = difference(dill, erod, gradient);
    

	// Display the image
	imshow("source", source_image);
	// imshow("erosion", erod);
	// imshow("dilate", dill);
    imshow("gradient", gradient);
	waitKey();


	return 0;
}
