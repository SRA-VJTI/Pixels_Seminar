//including the necessary header files
#include <iostream>
//the following header files are from the OpenCV library for C++
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat rotate(Mat src, double angle)   //rotate function returning mat object with parametres imagefile and angle    
{
    Mat dst;      //Mat object for output image file
    Point2f pt(src.cols/2., src.rows/2.);          //point from where to rotate    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);      //Mat object for storing after rotation
    warpAffine(src, dst, r, Size(src.cols, src.rows));  ///applie an affine transforation to image.
    return dst;         //returning Mat object for output image file
}

int main(){
    //converting the image into Mat format
    Mat img = imread("dog.jpeg");
    Mat img2;
    //obtaining the image dimensions
    int height=img.size().height;
    int width=img.size().width;

    img2 = rotate(img, 90);
    //displaying these images
    imshow("rotated image", img2);
    waitKey(0);
    
    return 0;
}