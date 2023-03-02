/*
Contains the Function definitions for Nearest-Neighbour Interpolation
Functions for Scale Up/Down with specific number of reduction/increase of pixels or scaling by ratio are defined here
They can be called from the main nearest_neighbour.cpp file
*/
#include "nearest_neighbour.hpp"

using namespace std;
using namespace cv;

Mat nearest_neighbour_scale_image(Mat image, Mat scaled_image)
{
	/*
    Nearest-Neighbour Interpolation main calculation loop
    This function is called when image has to be reduced or enlarged with arguements
        Mat Original Image
        Mat New Image
    And the function returns the resized image (Mat scaled_image)
    */
    // Variable declarations and initialization
    // These variables are used in calculations the function of the same are as follows
    //      new_width: width of new image
    //      new_height: height of new image
    //      scale_x: By how much is new image to be scaled in x-direction (width) to be mapped to original image
    //      scale_y: By how much is new image to be scaled in y-direction (height) to be mapped to original image
    int new_width = scaled_image.size().width, new_height = scaled_image.size().height;
    double scale_x = (float)image.size().width / (float)new_width;
	double scale_y = (float)image.size().height / (float)new_height;

	// For Debugging - prints on terminal
	cout<<"Image Height :"<<scaled_image.size().height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<scaled_image.size().width<<endl;	// Can also use `image.rows`
	cout<<"Interpolation Scaling Values for New Image -"<<endl;
	cout<<scale_x<<endl;
	cout<<scale_y<<endl<<endl;

    /*
    This is the main loop wherein for each pixel value of the new image, it is mapped to the corresponding pixel value of
    the original image using the scaling factor. After finding the corresponding pixel location in the original image,
    Nearest-Neighbour Interpolation is used to find the value of pixel at that specific location
    We find the pixel in original image which is nearest to the mapped pixel location in original image
    And the value in this pixel found, is now assigned to the pixel in new image
    */
	for (int i = 0; i < new_width; i++)
	{
		// Variable declarations and initialization
        // These variables are mapping pixel values of new image to original image in x-direction (width)
        //      new_x: Mapped pixel value in x-direction (width) on original image
        int new_x = round(i*scale_x);

		for (int j = 0; j < new_height; j++)
		{
			// Variable declarations and initialization
            // These variables are mapping pixel values of new image to original image in y-direction (height)
            //      new_y: Mapped pixel value in y-direction (height) on original image
            int new_y = round(j*scale_y);

            // Assignment of Pixel Value in new image from value of pixel found by using Nearest-Neighbour Interpolation
			scaled_image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(new_y, new_x)[0];
			scaled_image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(new_y, new_x)[1];
			scaled_image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(new_y, new_x)[2];
        }
    }

    return(scaled_image);
}

void nearest_neighbour_scale_down_image(Mat image, int pixels_reduce_x, int pixels_reduce_y)
{
	/*
    Function to Reduce Size of Image by specific number of pixels, with arguements
        Mat Original Image
        int pixels_reduce_x
        int pixels_reduce_y
    Function creates (mat container), displays, as well as stores resized image
	*/
   	// Variable declarations and initialization - 
    // Here we subtract number of pixels in dimensions of image in x-direction (width) and y-direction (width) as per requirement
	//		new_height: height of resized image (y-direction)
	// 		new_width: width of resized image (x-direction)
    int new_height = image.size().height - pixels_reduce_y;
	int new_width = image.size().width - pixels_reduce_x;

    // Since we cannot have an image with `-ve ` or `0` number of pixels
    // A loop is used in which if either one of height or width or both have number of pixels less than 10, 
    //  then that specific variable is assigned value = 10
    if (new_height < 10 && new_width > 10)
    {
        new_height = 10;
    }
    else if(new_height > 10 && new_width < 10)
    {
        new_width = 10;
    }
    else if(new_height < 10 && new_width < 10)
    {
        new_width = 10, new_height = 10;
    }

	// For Debugging Purposes - prints on terminal
    cout<<"Reduce Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

	// Create an image using Mat container with name `scaled_down_image`	
   	// Variable declarations and initialization
    // 		scaled_down_image: Mat container created for new image according to it's dimensions
    //                          It's intialized with all pixel values as `0`
    Mat scaled_down_image;
	scaled_down_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    // Call Main Nearest-Neighbour Interpolation Function - which returns resized image
    scaled_down_image = nearest_neighbour_scale_image(image, scaled_down_image);

	// For Scaled Down Image :
    // Save Resized Image
	imwrite("Scaled_Down_Image.jpg", scaled_down_image ); 
	// Create a window.
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("Scaled Down Image", scaled_down_image ); 
}

void nearest_neighbour_fscale_down_image(Mat image, double scale_x, double scale_y)
{
	/*
    Function to Reduce Size of Image by a specific scaling factor, with arguements
        Mat Original Image
        double scale_x
        double scale_y
    Function creates (mat container), displays, as well as stores resized image
	*/
   	// Variable declarations and initialization - 
    // Here we scale number of pixels in x-direction (width) and y-direction (width) as per requirement
	//		new_height: height of resized image (y-direction)
	// 		new_width: width of resized image (x-direction)
	double new_height = ((double)image.size().height * (1 / scale_y));
	double new_width = ((double)image.size().width * (1 / scale_x));

    // Since we cannot have an image with `-ve ` or `0` number of pixels
    // A loop is used in which if either one of height or width or both have number of pixels less than 10, 
    //  then that specific variable is assigned value = 10
    if (new_height < 10 && new_width > 10)
    {
        new_height = (double)10;
    }
    else if(new_height > 10 && new_width < 10)
    {
        new_width = (double)10;
    }
    else if(new_height < 10 && new_width < 10)
    {
        new_width = (double)10, new_height = (double)10;
    }

	// For Debugging Purposes - prints on terminal
    cout<<"FScale Down Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

	// Create an image using Mat container with name `fscaled_down_image`	
   	// Variable declarations and initialization
    // 		fscaled_down_image: Mat container created for new image according to it's dimensions
    //                          It's intialized with all pixel values as `0`
    Mat fscaled_down_image;
	fscaled_down_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    // Call Main Nearest-Neighbour Interpolation Function - which returns resized image
    fscaled_down_image = nearest_neighbour_scale_image(image, fscaled_down_image);

	// For FScaled Down Image :
    // Save Resized Image
	imwrite("FScaled_Down_Image.jpg", fscaled_down_image ); 
	// Create a window.
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("FScaled Down Image", fscaled_down_image ); 
}

void nearest_neighbour_scale_up_image(Mat image, int pixels_increase_x, int pixels_increase_y)
{
	/*
    Function to Increase Size of Image by specific number of pixels, with arguements
        Mat Original Image
        int pixels_increase_x
        int pixels_increase_y
    Function creates (mat container), displays, as well as stores resized image
	*/
   	// Variable declarations and initialization - 
    // Here we add number of pixels in dimensions of image in x-direction (width) and y-direction (width) as per requirement
	//		new_height: height of resized image (y-direction)
	// 		new_width: width of resized image (x-direction)
	int new_height = image.size().height + pixels_increase_y;
	int new_width = image.size().width + pixels_increase_x;

	// For Debugging Purposes - prints on terminal
    cout<<"Enlarge Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

	// Create an image using Mat container with name `scaled_up_image`	
   	// Variable declarations and initialization
    // 		scaled_up_image: Mat container created for new image according to it's dimensions
    //                          It's intialized with all pixel values as `0`
    Mat scaled_up_image;
	scaled_up_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    // Call Main Nearest-Neighbour Interpolation Function - which returns resized image
    scaled_up_image = nearest_neighbour_scale_image(image, scaled_up_image);

	// For Scaled Up Image :
    // Save Resized Image
	imwrite("Scaled_Up_Image.jpg", scaled_up_image ); 
	// Create a window.
	namedWindow("Scaled Up Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("Scaled Up Image", scaled_up_image ); 
}

void nearest_neighbour_fscale_up_image(Mat image, double scale_x, double scale_y)
{
	/*
    Function to Increase Size of Image by a specific scaling factor, with arguements
        Mat Original Image
        double scale_x
        double scale_y
    Function creates (mat container), displays, as well as stores resized image
	*/
   	// Variable declarations and initialization - 
    // Here we scale number of pixels in x-direction (width) and y-direction (width) as per requirement
	//		new_height: height of resized image (y-direction)
	// 		new_width: width of resized image (x-direction)
	double new_height = ((double)image.size().height * scale_y);
	double new_width = ((double)image.size().width * scale_x);

	// For Debugging Purposes - prints on terminal
    cout<<"FScale Up Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

	// Create an image using Mat container with name `fscaled_up_image`	
   	// Variable declarations and initialization
    // 		fscaled_up_image: Mat container created for new image according to it's dimensions
    //                          It's intialized with all pixel values as `0`
    Mat fscaled_up_image;
	fscaled_up_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    // Call Main Nearest-Neighbour Interpolation Function - which returns resized image
    fscaled_up_image = nearest_neighbour_scale_image(image, fscaled_up_image);

	// For FScaled Up Image :
    // Save Resized Image
	imwrite("FScaled_Up_Image.jpg", fscaled_up_image );
	// Create a window. 
	namedWindow("Scaled Up Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("FScaled Up Image", fscaled_up_image ); 
}