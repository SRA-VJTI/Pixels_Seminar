#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;



Mat masking(Mat image)
{
   Vec3b grey = Vec3b(230,230,230); //defining masks for the colours which you do not need in the image
   Vec3b white = Vec3b(255,255,255);
   
   int height = image.rows;
   int width = image.cols;

   Mat transparentImg = Mat::zeros(height,width, CV_8UC4); //dreates a new transparent empty image

   for(int i = 0; i<height; i++)
    {
	for(int j = 0; j<width; j++)
	{
		Vec3b x = image.at<Vec3b>(i, j);//getting the pixel rgb values
		Vec4b y  = Vec4b(x[0],x[1],x[2],255);
		if(grey==x || white==x) //Add the range for the colours which you want to ignore
		{
			//do not write to the transparent image if it has RGB values which we don't wish for it to have
			; 
		}
		else
		{
			transparentImg.at<Vec4b>(i,j)=y; //write to the new image all other colours except the one's to be ignored (4th channel here in Vec4b being alpha)
		}
	}
	
   }
   return transparentImg;
}



int main() 
{
   Mat image;//taking an image matrix
   image = imread("nike.png");//loading an image//
   
   Mat new_img = masking(image);
   imwrite("bg_free.png", new_img);
   imshow("center",new_img);
   waitKey(0);
   destroyAllWindows();
	   
   return 0;
}
