#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	if (argc != 2) 
	{
		printf("usage: ResizeDown.out <Image_Path>\n");
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

	cout<<"Image Height :"<<image.size().height<<endl;	// Can also use `image.columns`
	cout<<"Image Width :"<<image.size().width<<endl;	// Can also use `image.rows`

	
	int down_width = width - 100;
	int down_height = height - 100;

    double scale_down_x = 0.5;
    double scale_down_y = 0.5;


	Mat resized_down_INTER_LINEAR;
	resize(image, resized_down_INTER_LINEAR, Size(down_width, down_height), INTER_LINEAR);

	Mat resized_down_INTER_AREA;
	resize(image, resized_down_INTER_AREA, Size(down_width, down_height), INTER_AREA);

	Mat resized_down_INTER_CUBIC;
	resize(image, resized_down_INTER_CUBIC, Size(down_width, down_height), INTER_CUBIC);

	Mat resized_down_INTER_NEAREST;
	resize(image, resized_down_INTER_NEAREST, Size(down_width, down_height), INTER_NEAREST);

	Mat scaled_f_down;
	resize(image, scaled_f_down, Size(), scale_down_x, scale_down_y, INTER_LINEAR);


	imwrite("INTER_LINEAR.jpg", resized_down_INTER_LINEAR);
	imwrite("INTER_AREA.jpg", resized_down_INTER_AREA);
	imwrite("INTER_CUBIC.jpg", resized_down_INTER_CUBIC);
	imwrite("INTER_NEAREST.jpg", resized_down_INTER_NEAREST);
	imwrite("scaled_f_down.jpg", scaled_f_down);


	// Create a window.
	namedWindow("Color Image", WINDOW_AUTOSIZE );

    namedWindow("INTER_LINEAR", WINDOW_AUTOSIZE );
    namedWindow("INTER_AREA", WINDOW_AUTOSIZE );
    namedWindow("INTER_CUBIC", WINDOW_AUTOSIZE );
    namedWindow("INTER_NEAREST", WINDOW_AUTOSIZE );
    namedWindow("scaled_f_up", WINDOW_AUTOSIZE );
	

	// Show the image inside it.
	imshow("Color Image", image ); 

	imshow("INTER_LINEAR", resized_down_INTER_LINEAR);
	imshow("INTER_AREA", resized_down_INTER_AREA);
	imshow("INTER_CUBIC", resized_down_INTER_CUBIC);
	imshow("INTER_NEAREST", resized_down_INTER_NEAREST);
	imshow("scaled_f_down", scaled_f_down);


	// Wait for a keystroke.   
	waitKey(0);  
	
	// Destroys all the windows created                         
	destroyAllWindows();

	return 0;
}
