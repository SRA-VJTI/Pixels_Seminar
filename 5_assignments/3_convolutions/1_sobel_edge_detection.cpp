#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;

Mat SobelEdgeX(Mat original_image){
	Mat filtered_image;
	Sobel(original_image, filtered_image, CV_8UC1, 1, 0, 3, 1, 1);
	return filtered_image;
}

Mat SobelEdgeY(Mat original_image){
	Mat filtered_image;
	Sobel(original_image, filtered_image, CV_8UC1, 0, 1, 3, 1, 1);
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
    //imshow( "Filtered Image",  SobelEdgeX(original_image));
	//imshow( "Filtered Image",  SobelEdgeY(original_image));
	waitKey(0);
	return 0;
}