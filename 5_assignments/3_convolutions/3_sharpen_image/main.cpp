#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;

Mat Sharpen(Mat original_image){
	Mat sharp_img;
	Mat kernel3 = (Mat_<double>(3,3) << 0, -1,  0, 
                                   	     -1, 5, -1, 
                                    	     0, -1, 0);
	filter2D(original_image, sharp_img, -1 , kernel3, Point(-1, -1), 0, BORDER_DEFAULT);
	return sharp_img;
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
	imshow( "Filtered Image",  Sharpen(original_image));
	waitKey(0);
	return 0;
}