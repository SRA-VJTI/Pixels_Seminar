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
		double new_down_x = i*scale_down_x;
        int V1 = ceil(new_down_x);
        int V2 = floor(new_down_x);
        double d1 = new_down_x - (double)V1;
        double d2 = (double)V2 - new_down_x;

        if(d1 == 0 || d2 == 0)
        {
            cout << i << " " << new_down_x <<endl;
        }

		for (int j = 0; j < down_height; j++)
		{
			double new_down_y = j*scale_down_y;
            int V3 = ceil(new_down_y);
            int V4 = floor(new_down_y);

            double d3 = new_down_y - (double)V3;
            double d4 = (double)V4 - new_down_y;

            if(d1 != 0 && d2 != 0 && d3 != 0 && d4 != 0)
			{
                scaled_down_image.at<Vec3b>(j, i)[0] = (((image.at<Vec3b>(V3, V1)[0])*d2*d4) + ((image.at<Vec3b>(V3, V2)[0])*d1*d4) + ((image.at<Vec3b>(V4, V1)[0])*d2*d3) + ((image.at<Vec3b>(V4, V2)[0])*d1*d3));
                scaled_down_image.at<Vec3b>(j, i)[1] = (((image.at<Vec3b>(V3, V1)[1])*d2*d4) + ((image.at<Vec3b>(V3, V2)[1])*d1*d4) + ((image.at<Vec3b>(V4, V1)[1])*d2*d3) + ((image.at<Vec3b>(V4, V2)[1])*d1*d3));
                scaled_down_image.at<Vec3b>(j, i)[2] = (((image.at<Vec3b>(V3, V1)[2])*d2*d4) + ((image.at<Vec3b>(V3, V2)[2])*d1*d4) + ((image.at<Vec3b>(V4, V1)[2])*d2*d3) + ((image.at<Vec3b>(V4, V2)[2])*d1*d3));
            }
            else
            {
                scaled_down_image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(new_down_y, new_down_x)[0];
                scaled_down_image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(new_down_y, new_down_x)[1];
                scaled_down_image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(new_down_y, new_down_x)[2];
            }

		}
	}

	// Save Resized Images
	imwrite("Scaled_Down_Image.jpg", scaled_down_image ); 

	// Create a window.
	namedWindow("Color Image", WINDOW_AUTOSIZE );
	namedWindow("Scaled Down Image", WINDOW_AUTOSIZE );

	// Show the image inside it.
	imshow("Color Image", image ); 
	imshow("Scaled Down Image", scaled_down_image ); 

	// Wait for a keystroke.   
	waitKey(0);  
	
	// Destroys all the windows created                         
	destroyAllWindows();

	return 0;
}
