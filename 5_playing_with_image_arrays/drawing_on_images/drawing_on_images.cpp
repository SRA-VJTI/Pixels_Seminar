#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    //creating a blank black Mat image
    Mat img = Mat::zeros(Size(400,400), CV_8UC1);
    Mat img2 = imread("../assets/dog.jpeg");

    //drawing a line on the image
    line(img, Point(0, 0), Point(100,100), Scalar(255,0), 3, 8, 0);
    line(img2, Point(50, 0), Point(100, 50), Scalar(255,0), 3, 8, 0);

    //drawing a circle
    circle(img, Point(200,150), 14, Scalar(255), 1, 8, 0);
    circle(img2, Point(200,150), 14, Scalar(255), 1, 8, 0);

    //drawing a rectangle
    rectangle(img, Point(50, 100), Point(100, 183), Scalar(255), 1);
    rectangle(img2, Point(50, 100), Point(100, 183), Scalar(255), 1);

    //displaying the image on the screen
    imshow("Drawing", img);
    imshow("Drawing on images", img2);
    waitKey(0);

    return 0;
}