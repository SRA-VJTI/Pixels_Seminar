/*
Contains the Function definitions for Bi-Linear Interpolation
Functions for Scale Up/Down with specific number of reduction/increase of pixels or scaling by ratio are defined here
They can be called from the main bi_linear.cpp file
*/
#include "bi_linear.hpp"

using namespace std;
using namespace cv;

Mat bi_linear_scale_image(Mat image, Mat scaled_image)
{
	/*
    Bi-Linear Interpolation main calculation loop
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
    the original image using the scaling factor. After finding the corresponding pixel location on the original image,
    Bi-Linear Interpolation is used to find the value of pixel at that specific location

    Bi-Linear Interpolation:

                      d1     W1                 d2
    A: (V1, V3) ⬤-----------⬤-----------------------------------⬤ B: (V2, V3)
                |            |                                    |
                |            |                                    |
                |            |                                    |
                |            | d3                                 | 
                |            |                                    |
                |            |                                    |
             H1 ⬤-----------⬤ P: (x, y)-------------------------⬤ H2
                |            |                                    |
                |            |                                    |
                |            |                                    |
                |            |                                    |
                |            |                                    | 
                |            | d4                                 |
                |            |                                    |
                |            |                                    |
                |            |                                    |
                |            |                                    |
                |            |                                    |
    C: (V1, V4) ⬤-----------⬤-----------------------------------⬤ D: (V2, V4)
                             W2

    where,  P = mapped pixel value in original Image
            A = Upper Left Corner
            B = Upper Right Corner
            C = Lower Left Corner
            D = Lower Right Corner
            W1 = Pixel after Interpolation along Upper Row i.e. in x-direction (width)
            W2 = Pixel after Interpolation along Lower Row i.e. in x-direction (width)
            H1 = Pixel after Interpolation along Left Column i.e. in y-direction (height)
            H2 = Pixel after Interpolation along Right Column i.e. in y-direction (height)
    */
	for (int i = 0; i < new_width; i++)
	{
		// Variable declarations and initialization
        // These variables are mapping pixel values of new image to original image in x-direction (width)
        //      new_x: Mapped pixel value in x-direction (width) on original image
        //      V1: Column to the left of Mapped pixel in original image
        //      V2: Column to the right of Mapped pixel in original image
        //      d1: distance between Mapped pixel in original image and Column to the left of Mapped pixel in original image
        //      d2: distance between Mapped pixel in original image and Column to the right of Mapped pixel in original image
        double new_x = i*scale_x;
        int V1 = floor(new_x), V2 = ceil(new_x);
        double d1 = new_x - (double)V1;
        double d2 = (double)V2 - new_x;

		for (int j = 0; j < new_height; j++)
		{
			// Variable declarations and initialization
            // These variables are mapping pixel values of new image to original image in y-direction (height)
            //      new_y: Mapped pixel value in y-direction (height) on original image
            //      V3: Row which is above the Mapped pixel in original image
            //      V4: Row which is below the Mapped pixel in original image
            //      d3: distance between Mapped pixel in original image and Row which is above the Mapped pixel in original image
            //      d4: distance between Mapped pixel in original image and Row which is below the Mapped pixel in original image
            double new_y = j*scale_y;
            int V3 = floor(new_y), V4 = ceil(new_y);
            double d3 = new_y - (double)V3;
            double d4 = (double)V4 - new_y;

            if(d1 != 0 && d2 != 0 && d3 != 0 && d4 != 0)
			{
                // Calculation of Mapped Pixel Value on Original Image according to Formula of Bi-Linear Interpolation which is
                //      Pixel Value = A*d2*d4 + B*d1*d4 + C*d2*d3 + D*d1*d3 
                scaled_image.at<Vec3b>(j, i)[0] = (((image.at<Vec3b>(V3, V1)[0])*d2*d4) + ((image.at<Vec3b>(V3, V2)[0])*d1*d4) + ((image.at<Vec3b>(V4, V1)[0])*d2*d3) + ((image.at<Vec3b>(V4, V2)[0])*d1*d3));
                scaled_image.at<Vec3b>(j, i)[1] = (((image.at<Vec3b>(V3, V1)[1])*d2*d4) + ((image.at<Vec3b>(V3, V2)[1])*d1*d4) + ((image.at<Vec3b>(V4, V1)[1])*d2*d3) + ((image.at<Vec3b>(V4, V2)[1])*d1*d3));
                scaled_image.at<Vec3b>(j, i)[2] = (((image.at<Vec3b>(V3, V1)[2])*d2*d4) + ((image.at<Vec3b>(V3, V2)[2])*d1*d4) + ((image.at<Vec3b>(V4, V1)[2])*d2*d3) + ((image.at<Vec3b>(V4, V2)[2])*d1*d3));
            }
            else if(d1 == 0 && d2 == 0 && d3 != 0 && d4 != 0)
			{
                // If Mapped Pixel Value on Original Image in x-direction (width) is an integer, then d1 and d2 will be `0`
                //      i.e. V1 == V2 --> d1 == d1 == 0
                // Then we need not interpolate in x-direction (width), we will just interpolate in y-direction (height)
                //      i.e. Pixel Value = W1*d4 + W2*d3
                scaled_image.at<Vec3b>(j, i)[0] = (((image.at<Vec3b>(V3, V1)[0])*d4) + ((image.at<Vec3b>(V4, V1)[0])*d3));
                scaled_image.at<Vec3b>(j, i)[1] = (((image.at<Vec3b>(V3, V1)[1])*d4) + ((image.at<Vec3b>(V4, V1)[1])*d3));
                scaled_image.at<Vec3b>(j, i)[2] = (((image.at<Vec3b>(V3, V1)[2])*d4) + ((image.at<Vec3b>(V4, V1)[2])*d3));
            }
            else if(d1 != 0 && d2 != 0 && d3 == 0 && d4 == 0)
			{
                // If Mapped Pixel Value on Original Image in y-direction (height) is an integer, then d3 and d4 will be `0`
                //      i.e. V3 == V4 --> d3 == d4 == 0
                // Then we need not interpolate in y-direction (height), we will just interpolate in x-direction (width)
                //      i.e. Pixel Value = H1*d2 + H2*d1
                scaled_image.at<Vec3b>(j, i)[0] = (((image.at<Vec3b>(V3, V1)[0])*d2) + ((image.at<Vec3b>(V3, V2)[0])*d1));
                scaled_image.at<Vec3b>(j, i)[1] = (((image.at<Vec3b>(V3, V1)[1])*d2) + ((image.at<Vec3b>(V3, V2)[1])*d1));
                scaled_image.at<Vec3b>(j, i)[2] = (((image.at<Vec3b>(V3, V1)[2])*d2) + ((image.at<Vec3b>(V3, V2)[2])*d1));
            }
            else if (d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0)
            {
                // If Mapped Pixel Value on Original Image in x-direction (height) as well as in y-direction (height) is an integer, then d1, d3, d3 and d4 will be `0`
                //      i.e. V1 == V2 and V3 == V4 --> d1 == d2 == d3 == d4 == 0
                // Then we need not interpolate in y-direction (height), we will just interpolate in x-direction (width)
                //      i.e. Pixel Value = P
                scaled_image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(new_y, new_x)[0];
                scaled_image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(new_y, new_x)[1];
                scaled_image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(new_y, new_x)[2];
            }
		}
	}

    return(scaled_image);
}

void bi_linear_scale_down_image(Mat image, int pixels_reduce_x, int pixels_reduce_y)
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

    // Call Main Bi-Linear Interpolation Function - which returns resized image
    scaled_down_image = bi_linear_scale_image(image, scaled_down_image);

	// For Scaled Down Image :
    // Save Resized Image
	imwrite("Scaled_Down_Image.jpg", scaled_down_image ); 
	// Create a window.
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("Scaled Down Image", scaled_down_image ); 
}

void bi_linear_fscale_down_image(Mat image, double scale_x, double scale_y)
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

    // Call Main Bi-Linear Interpolation Function - which returns resized image
    fscaled_down_image = bi_linear_scale_image(image, fscaled_down_image);

	// For FScaled Down Image :
    // Save Resized Image
	imwrite("FScaled_Down_Image.jpg", fscaled_down_image ); 
	// Create a window.
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("FScaled Down Image", fscaled_down_image ); 
}

void bi_linear_scale_up_image(Mat image, int pixels_increase_x, int pixels_increase_y)
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

    // Call Main Bi-Linear Interpolation Function - which returns resized image
    scaled_up_image = bi_linear_scale_image(image, scaled_up_image);

	// For Scaled Up Image :
    // Save Resized Image
	imwrite("Scaled_Up_Image.jpg", scaled_up_image ); 
	// Create a window.
	namedWindow("Scaled Up Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("Scaled Up Image", scaled_up_image ); 
}

void bi_linear_fscale_up_image(Mat image, double scale_x, double scale_y)
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

    // Call Main Bi-Linear Interpolation Function - which returns resized image
    fscaled_up_image = bi_linear_scale_image(image, fscaled_up_image);

	// For FScaled Up Image :
    // Save Resized Image
	imwrite("FScaled_Up_Image.jpg", fscaled_up_image );
	// Create a window. 
	namedWindow("Scaled Up Image", WINDOW_AUTOSIZE );
	// Show the image inside it.
	imshow("FScaled Up Image", fscaled_up_image ); 
}