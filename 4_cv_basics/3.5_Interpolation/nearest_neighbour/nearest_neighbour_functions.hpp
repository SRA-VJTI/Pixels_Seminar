/*
Contains the Function definitions for Nearest-Neighbour Interpolation
Functions for Scale Up/Down with specific number of reduction/increase of pixels or scaling by ratio are defined here
They can be called from the main nearest_neighbour.cpp file
*/
#include "nearest_neighbour.hpp"

using namespace std;
using namespace cv;

Mat scale_image(Mat image, Mat scaled_image)
{
	/*
    Bi-Linear Interpolation main calculation loop
    This function is called when image has to be reduced or enlarged with arguements
        Mat Original Image
        Mat New Image
        original image height
        original image width
        new image height
        new image width
    And the function returns the resized image (Mat scaled_image)
    */
    int new_width = scaled_image.size().width, new_height = scaled_image.size().height;
    double scale_x = (float)image.size().width / (float)new_width;
	double scale_y = (float)image.size().height / (float)new_height;

	// For Debugging
	cout<<"Image Height :"<<scaled_image.size().height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<scaled_image.size().width<<endl;	// Can also use `image.rows`
	cout<<"Interpolation Scaling Values for New Image -"<<endl;
	cout<<scale_x<<endl;
	cout<<scale_y<<endl<<endl;

	for (int i = 0; i < new_width; i++)
	{
		double new_x = i*scale_x;
        int V1 = floor(new_x), V2 = ceil(new_x);
        double d1 = new_x - (double)V1;
        double d2 = (double)V2 - new_x;

		for (int j = 0; j < new_height; j++)
		{
			double new_y = j*scale_y;
            int V3 = floor(new_y), V4 = ceil(new_y);

            double d3 = new_y - (double)V3;
            double d4 = (double)V4 - new_y;
            if(d1 != 0 && d2 != 0 && d3 != 0 && d4 != 0)
			{
                scaled_image.at<Vec3b>(j, i)[0] = (((image.at<Vec3b>(V3, V1)[0])*d2*d4) + ((image.at<Vec3b>(V3, V2)[0])*d1*d4) + ((image.at<Vec3b>(V4, V1)[0])*d2*d3) + ((image.at<Vec3b>(V4, V2)[0])*d1*d3));
                scaled_image.at<Vec3b>(j, i)[1] = (((image.at<Vec3b>(V3, V1)[1])*d2*d4) + ((image.at<Vec3b>(V3, V2)[1])*d1*d4) + ((image.at<Vec3b>(V4, V1)[1])*d2*d3) + ((image.at<Vec3b>(V4, V2)[1])*d1*d3));
                scaled_image.at<Vec3b>(j, i)[2] = (((image.at<Vec3b>(V3, V1)[2])*d2*d4) + ((image.at<Vec3b>(V3, V2)[2])*d1*d4) + ((image.at<Vec3b>(V4, V1)[2])*d2*d3) + ((image.at<Vec3b>(V4, V2)[2])*d1*d3));
            }
            else if(d1 == 0 && d2 == 0 && d3 != 0 && d4 != 0)
			{
                scaled_image.at<Vec3b>(j, i)[0] = (((image.at<Vec3b>(V3, V1)[0])*d4) + ((image.at<Vec3b>(V4, V1)[0])*d3));
                scaled_image.at<Vec3b>(j, i)[1] = (((image.at<Vec3b>(V3, V1)[1])*d4) + ((image.at<Vec3b>(V4, V1)[1])*d3));
                scaled_image.at<Vec3b>(j, i)[2] = (((image.at<Vec3b>(V3, V1)[2])*d4) + ((image.at<Vec3b>(V4, V1)[2])*d3));
            }
            else if(d1 != 0 && d2 != 0 && d3 == 0 && d4 == 0)
			{
                scaled_image.at<Vec3b>(j, i)[0] = (((image.at<Vec3b>(V3, V1)[0])*d2) + ((image.at<Vec3b>(V3, V2)[0])*d1));
                scaled_image.at<Vec3b>(j, i)[1] = (((image.at<Vec3b>(V3, V1)[1])*d2) + ((image.at<Vec3b>(V3, V2)[1])*d1));
                scaled_image.at<Vec3b>(j, i)[2] = (((image.at<Vec3b>(V3, V1)[2])*d2) + ((image.at<Vec3b>(V3, V2)[2])*d1));
            }
            else if (d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0)
            {
                scaled_image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(new_y, new_x)[0];
                scaled_image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(new_y, new_x)[1];
                scaled_image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(new_y, new_x)[2];
            }
		}
	}

    return(scaled_image);
}

void scale_down_image(Mat image, int pixels_reduce_x, int pixels_reduce_y)
{
	// Reduce Size of Image
	int new_height = image.size().height - pixels_reduce_y;
	int new_width = image.size().width - pixels_reduce_x;

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

    cout<<"Reduce Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

    Mat scaled_down_image;
	scaled_down_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    scaled_down_image = scale_image(image, scaled_down_image);

    // Save Resized Images
	imwrite("Scaled_Down_Image.jpg", scaled_down_image ); 
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );
	imshow("Scaled Down Image", scaled_down_image ); 
}

void fscale_down_image(Mat image, double scale_x, double scale_y)
{
	// Reduce Size of Image
	double new_height = ((double)image.size().height * (1 / scale_y));
	double new_width = ((double)image.size().width * (1 / scale_x));

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
    
    cout<<"FScale Down Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

    Mat fscaled_down_image;
	fscaled_down_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    fscaled_down_image = scale_image(image, fscaled_down_image);

    // Save Resized Images
	imwrite("FScaled_Down_Image.jpg", fscaled_down_image ); 
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );
	imshow("FScaled Down Image", fscaled_down_image ); 
}

void scale_up_image(Mat image, int pixels_increase_x, int pixels_increase_y)
{
	// Reduce Size of Image
	int new_height = image.size().height + pixels_increase_y;
	int new_width = image.size().width + pixels_increase_x;
    cout<<"Enlarge Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

    Mat scaled_up_image;
	scaled_up_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    scaled_up_image = scale_image(image, scaled_up_image);

    // Save Resized Images
	imwrite("Scaled_Up_Image.jpg", scaled_up_image ); 
	namedWindow("Scaled Up Image", WINDOW_AUTOSIZE );
	imshow("Scaled Up Image", scaled_up_image ); 
}

void fscale_up_image(Mat image, double scale_x, double scale_y)
{
	// Reduce Size of Image
	double new_height = ((double)image.size().height * scale_y);
	double new_width = ((double)image.size().width * scale_x);
    cout<<"FScale Up Image :"<<endl;
	cout<<new_height<<" "<<new_width<<endl;

    Mat fscaled_up_image;
	fscaled_up_image = Mat::zeros( Size((int)new_width, (int)new_height), CV_8UC3 );

    fscaled_up_image = scale_image(image, fscaled_up_image);

    // Save Resized Images
	imwrite("FScaled_Up_Image.jpg", fscaled_up_image ); 
	namedWindow("Scaled Up Image", WINDOW_AUTOSIZE );
	imshow("FScaled Up Image", fscaled_up_image ); 
}
