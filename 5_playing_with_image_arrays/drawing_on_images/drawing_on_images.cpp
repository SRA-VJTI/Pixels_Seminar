//including the necessary header files
#include <iostream>
//the following header files are from the OpenCV library for C++
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//declaration of functions 
void line(Mat img, int x1, int y1, int x2, int y2, int width, int B, int G, int R);
void rectangle(Mat img, int breadth, int length, int h, int k, int width, int B, int G, int R);
void circle (Mat img, int h, int k, int r, int width, int B, int G, int R);

int main(){
    //creating a blank Mat image
    Mat img(480, 720, CV_8UC3, Scalar(0, 0, 0));
    // img(height, width, cv 8-bit 3 channels, BGR)
    
    //drawing on image 
    rectangle(img,70,50,360,240,3, 20,250,140);
    line(img,25,25,120,150,4,70,80,150);
    circle(img,240,360,70,3,200,49,169);
    
    //displayng image 
    imshow("Drawing", img);
    waitKey(0);

    return 0;
}

// Function to draw line 
void line(Mat img, int x1, int y1, int x2, int y2, int width, int B, int G, int R){
    //slope of the line 
    int m = (y2-y1)/(x2-x1);
    //width i.e. thickness of line 
    //dividing by 2 to get the line at centre from expected line 
    width /= 2;
    //traversing the loop in vertical direction from y1 to y2, y2>y1
    for(int i = y1;i < y2;i++){
        //traversing the loop in horizontal direction from x1 to x2, x2>x1
        for(int j = x1;j < x2;j++){
            //condition for width of line 
            if(i >= m*j - width && i <= m*j + width){
                img.at<Vec3b>(i,j)[0] = B;
                img.at<Vec3b>(i,j)[1] = G;
                img.at<Vec3b>(i,j)[2] = R;
            }
            else continue;
        }
    }
}

//Function for drawing rectangle and square (length = breadth)
void rectangle(Mat img, int breadth, int length, int h, int k, int width, int B, int G, int R){
    //dividing length and breadth by 2 as we are drawing with recpect to centre of quadrilateral 
    length /= 2;
    breadth /= 2;
    //traversing loop in vertical direction from centre - breadth by 2 to centre + breadth by 2 
    for(int i = k - breadth;i <= k + breadth;i++){
        //traversing loop in horizontal direction from centre - length by 2 to centre + length by 2 
        for(int j = h - length;j <= h + length;j++){
            //condition for width of rectangle if width is greater than half of length then solid quadrilateral is obtaied 
            if((i <= (k - breadth + width) || j <= (h - length + width)) || (i >= (k + breadth - width) || j >= (h + length - width))){
                img.at<Vec3b>(i,j)[0] = B;
                img.at<Vec3b>(i,j)[1] = G;
                img.at<Vec3b>(i,j)[2] = R;
            }
            else continue;
        }
    }
}

//Function for drawing a circle 
void circle (Mat img, int h, int k, int r, int width, int B, int G, int R){
    int i = 0, j = 0, c = 0;
    //traversing loop in vertical direction from centre - radius to centre + radius 
    for(i = h - r;i <= (h + r);i++){
        //traversing loop in horizontal direction from centre - radius to centre + radius
        for(j = k - r;j <= (k + r);j++){
            //calculating the LHS of equation of circle (x-h)^2 + (y-k)^2 = r^2
            c = ((i-h)*(i-h) + (j-k)*(j-k));
            //condition for width , if width is greater than radius -1 then solid circle is obtained 
            if(c <= r*r && c >= (r*(r-1-width))){
                img.at<Vec3b>(i,j)[0]=B;
                img.at<Vec3b>(i,j)[1]=G;
                img.at<Vec3b>(i,j)[2]=R;
            }
            else continue;
        }
    }
    //centre of the circle 
    img.at<Vec3b>(h,k)[1]=255;
}
