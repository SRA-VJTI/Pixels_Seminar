#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

// rotate function returning mat object with parametres imagefile and angle
Mat rotate(Mat src, double angle)
{
    // Mat object for output image file
    Mat dst;
    // defining point with respect to which to rotate
    Point2f pt(src.cols/2., src.rows/2.);
    // Mat object for storing after rotation
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    // apply an affine transforation to image.
    warpAffine(src, dst, r, Size(src.cols, src.rows));
    //returning Mat object for output image file
    return dst;
}

int main(){
    // converting the image into Mat format
    Mat img = imread("../assets/dog.jpeg");
    Mat img2;
    // obtaining the image dimensions
    int height=img.size().height;
    int width=img.size().width;

    img2 = rotate(img, 90);
    // displaying these images
    imshow("rotated image", img2);
    waitKey(0);
    
    return 0;
}