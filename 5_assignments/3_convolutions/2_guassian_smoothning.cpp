#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;

Mat GausianSmoothening(Mat original_image, Size kernel_size){
	Mat filtered_image;
	GaussianBlur(original_image, filtered_image, kernel_size, 0);
	return filtered_image;
}



int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("usage: DisplayImage.out <Image_Path>\n");
		return -1;
	}
	Mat original_image, filtered_image;
	original_image = imread(argv[1], 1);
	if (!original_image.data) {
		printf("No image data \n");
		return -1;
	}
	namedWindow("Original Image", WINDOW_AUTOSIZE );
	imshow( "Original Image",  original_image);
	namedWindow("Filtered Image", WINDOW_AUTOSIZE );
	//imshow( "Filtered Image",  GausianSmoothening(original_image, Size(7, 7)));
	waitKey(0);
	return 0;
}