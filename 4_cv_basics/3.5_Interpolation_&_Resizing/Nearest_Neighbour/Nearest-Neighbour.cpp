#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <cmath>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	if (argc != 2) 
	{
		printf("usage: Nearest-Neighbour.out <Image_Path>\n");
		return -1;
	}
	
	Mat image;

    image = imread(argv[1], IMREAD_COLOR);

	if (!image.data) 
	{
		printf("No image data \n");
		return -1;
	}

	int height = image.size().height;
	int width = image.size().width;

	cout<<"Size of Original Image -"<<endl;
	cout<<"Image Height :"<<height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<width<<endl<<endl;		// Can also use `image.rows`



	// Reduce Size of Image
	int down_height = height - 100;
	int down_width = width - 100;

	double scale_down_x = (float)width / (float)down_width;
	double scale_down_y = (float)height / (float)down_height;

	Mat scaled_down_image;
	scaled_down_image = Mat::zeros( Size(down_width, down_height), CV_8UC3 );

	// For Debugging
	cout<<"Size of Reduced Image -"<<endl;
	cout<<"Image Height :"<<scaled_down_image.size().height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<scaled_down_image.size().width<<endl;	// Can also use `image.rows`
	cout<<"Interpolation Scaling Values for Reduced Image -"<<endl;
	cout<<scale_down_x<<endl;
	cout<<scale_down_y<<endl<<endl;

	for (int i = 0; i < down_width; i++)
	{
		int new_down_x = floor(i*scale_down_x);

		for (int j = 0; j < down_height; j++)
		{
			int new_down_y = floor(j*scale_down_y);

			scaled_down_image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(new_down_y, new_down_x)[0];
			scaled_down_image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(new_down_y, new_down_x)[1];
			scaled_down_image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(new_down_y, new_down_x)[2];
		}
	}

	// F Scale Down Image
	double scaledown_x = 0.5;
	double scaledown_y = 0.5;

	double fscale_down_x = 1 / (double)scaledown_x;
	double fscale_down_y = 1 / (double)scaledown_y;

	Mat f_scale_down;
	f_scale_down = Mat::zeros( Size(floor(scaledown_x*width), floor(scaledown_y*height)), CV_8UC3 );

	// For Debugging
	cout<<"Size of Scale Down Image -"<<endl;
	cout<<"Image Height :"<<f_scale_down.size().height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<f_scale_down.size().width<<endl;	// Can also use `image.rows`
	cout<<"Interpolation Scaling Values for fScale Down -"<<endl;
	cout<<fscale_down_x<<endl;
	cout<<fscale_down_y<<endl<<endl;

	for (int m = 0; m < floor(scaledown_x*width); m++)
	{
		int new_down_x = floor(m*fscale_down_x);

		for (int n = 0; n < floor(scaledown_y*height); n++)
		{
			int new_down_y = floor(n*fscale_down_y);

			f_scale_down.at<Vec3b>(n, m)[0] = image.at<Vec3b>(new_down_y, new_down_x)[0];
			f_scale_down.at<Vec3b>(n, m)[1] = image.at<Vec3b>(new_down_y, new_down_x)[1];
			f_scale_down.at<Vec3b>(n, m)[2] = image.at<Vec3b>(new_down_y, new_down_x)[2];
		}
	}



	// Enlarge Size of Image
	int up_height = height + 100;
	int up_width = width + 100;

	double scale_up_x = (float)width / (float)up_width;
	double scale_up_y = (float)height / (float)up_height;

	Mat scaled_up_image;
	scaled_up_image = Mat::zeros( Size(up_width, up_height), CV_8UC3 );

	// For Debugging
	cout<<"Size of Enlarged Image -"<<endl;
	cout<<"Image Height :"<<scaled_up_image.size().height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<scaled_up_image.size().width<<endl;	// Can also use `image.rows`
	cout<<"Interpolation Scaling Values for Enlarged Image -"<<endl;
	cout<<scale_up_x<<endl;
	cout<<scale_up_y<<endl<<endl;

	for (int k = 0; k < up_width; k++)
	{
		int new_up_x = floor(k*scale_up_x);

		for (int l = 0; l < up_height; l++)
		{
			int new_up_y = floor(l*scale_up_y);

			scaled_up_image.at<Vec3b>(l, k)[0] = image.at<Vec3b>(new_up_y, new_up_x)[0];
			scaled_up_image.at<Vec3b>(l, k)[1] = image.at<Vec3b>(new_up_y, new_up_x)[1];
			scaled_up_image.at<Vec3b>(l, k)[2] = image.at<Vec3b>(new_up_y, new_up_x)[2];
		}
	}

	// F Scale Up Image
	int scaleup_x = 2;
	int scaleup_y = 2;

	double fscale_up_x = 1 / (double)scaleup_x;
	double fscale_up_y = 1 / (double)scaleup_y;

	Mat f_scale_up;
	f_scale_up = Mat::zeros( Size(floor(scaleup_x*width), floor(scaleup_y*height)), CV_8UC3 );

	// For Debugging
	cout<<"Size of Scale Up Image -"<<endl;
	cout<<"Image Height :"<<f_scale_up.size().height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<f_scale_up.size().width<<endl;	// Can also use `image.rows`
	cout<<"Interpolation Scaling Values for fScale Up Image -"<<endl;
	cout<<fscale_up_x<<endl;
	cout<<fscale_up_y<<endl<<endl;

	for (int o = 0; o < floor(scaleup_x*width); o++)
	{
		int new_up_x = floor(o*fscale_up_x);

		for (int p = 0; p < floor(scaleup_y*height); p++)
		{
			int new_up_y = floor(p*fscale_up_y);

			f_scale_up.at<Vec3b>(p, o)[0] = image.at<Vec3b>(new_up_y, new_up_x)[0];
			f_scale_up.at<Vec3b>(p, o)[1] = image.at<Vec3b>(new_up_y, new_up_x)[1];
			f_scale_up.at<Vec3b>(p, o)[2] = image.at<Vec3b>(new_up_y, new_up_x)[2];
		}
	}



	// Save Resized Images
	imwrite("Scaled_Down_Image.jpg", scaled_down_image ); 
	imwrite("Scaled_Up_Image.jpg", scaled_up_image ); 
	imwrite("fScaled_down_Image.jpg", f_scale_down ); 
	imwrite("fScaled_up_Image.jpg", f_scale_up ); 

	// Create a window.
	namedWindow("Color Image", WINDOW_AUTOSIZE );
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );
	namedWindow("Scaled Up Image", WINDOW_AUTOSIZE );
	namedWindow("fScaled Down Image", WINDOW_AUTOSIZE );
	namedWindow("fScaled Up Image", WINDOW_AUTOSIZE );

	// Show the image inside it.
	imshow("Color Image", image ); 
	imshow("Scaled Down Image", scaled_down_image ); 
	imshow("Scaled Up Image", scaled_up_image ); 
	imshow("fScaled Down Image", f_scale_down ); 
	imshow("fScaled Up Image", f_scale_up ); 

	// Wait for a keystroke.   
	waitKey(0);  
	
	// Destroys all the windows created                         
	destroyAllWindows();

	return 0;
}
