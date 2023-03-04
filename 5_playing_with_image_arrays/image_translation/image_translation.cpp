#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    // reading image and storing it in Mat format
    Mat image = imread("dog.jpeg");

    // storing the dimensions of the image
    int height = image.cols;
    int width = image.rows;

    // get the x and y axis values for translation so that the image can be moved in both directions
    float tx = float(width) / 4;
    float ty = float(height) / 4;
    
    // create the translation matrix using tx and ty
    float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
    Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);

    // save the resulting image in translated_image matrix
    Mat translated_image;
    // apply affine transformation to the original image using the translation matrix
    warpAffine(image, translated_image, translation_matrix, image.size());

    //display the original and the Translated images
    imshow("Translated image", translated_image);
    imshow("Original image", image);
    waitKey(0);

    return 0;
}