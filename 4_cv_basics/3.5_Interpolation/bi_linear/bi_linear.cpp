/*
Main .cpp file for Bi-Linear Interpolation
*/
#include "bi_linear_functions.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	// For Debugging. Prints error message on Terminal 
	if (argc != 2) 
	{
		printf("usage: Bi_Linear.out <Image_Path>\n");
		return -1;
	}

	// Load image and store it in Mat container with name `image`	
   	// Variable declarations and initialization
    // 		image: Mat container in which original image on which resizing operations are to be performed is loaded
	Mat image;
    image = imread(argv[1], IMREAD_COLOR);

	// For Debugging. Prints error message on Terminal 
	if (!image.data) 
	{
		printf("No image data \n");
		return -1;
	}

	// For Debugging Purposes - prints on terminal
   	// Variable declarations and initialization
	//		height: height of original image (y-direction)
	// 		width: width of original image (x-direction)
	int height = image.size().height, width = image.size().width;
	cout<<"Size of Original Image -"<<endl;
	cout<<"Image Height :"<<height<<endl;			// Can also use `image.columns`
	cout<<"Image Width :"<<width<<endl<<endl;		// Can also use `image.rows`

	// Variable declarations and initialization regarding by how much is image to be reduced/enlarged
	// 		pixels_reduce_x: reduce number of pixels in image in x-direction (width) by these many pixels
	// 		pixels_reduce_y: reduce number of pixels in image in y-direction (height) by these many pixels
	// 		pixels_increase_x: increase number of pixels in image in x-direction (width) by these many pixels
	// 		pixels_increase_y: increase number of pixels in image in x-direction (height) by these many pixels
	//		scale_x: scale image up/down in x-direction (width) by this ratio 
	//		scale_y: scale image up/down in y-direction (heigth) by this ratio
	int pixels_reduce_x = 100, pixels_reduce_y = 100;
	int pixels_increase_x = 100, pixels_increase_y = 100;
	double scale_x = 5, scale_y = 5;
	
	// Bi-Linear Interpolation function calls
	bi_linear_scale_down_image(image, pixels_reduce_x, pixels_reduce_y);
	bi_linear_scale_up_image(image, pixels_increase_x, pixels_increase_y);
	bi_linear_fscale_down_image(image, scale_x, scale_y);
	bi_linear_fscale_up_image(image, scale_x, scale_y);

	// For Original Image
	// Create a window.
	namedWindow("Original Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("Original Image", image ); 
	// Wait for a keystroke.   
	waitKey(0);  
	// Destroys all the windows created                         
	destroyAllWindows();

	return 0;
}
