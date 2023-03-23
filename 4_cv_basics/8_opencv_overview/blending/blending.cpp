#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
     // Reading input images (A and B)
    Mat image1 = imread("PROJECT_SOURCE_DIR/assets/images/dummy1.jpg");
    Mat image2 = imread("PROJECT_SOURCE_DIR/assets/images/purple_night.jpg");

    resize(image1, image1, Size(), 0.75, 0.75);
    resize(image2, image2, Size(), 0.75, 0.75);
    imshow("Image1", image1);
    imshow("Image2", image2);

    Mat res;

    // Defining weights for the two images
    float alpha = 0.4, beta = (1 - alpha);

    // Blending image1 and image2
    // res = alpha * image1 + beta * image2 + gamma(0)
    addWeighted(image1, alpha, image2, beta, 0.0, res);

    namedWindow("Display Image");
    resize(res, res, Size(), 0.75, 0.75);
    imshow("Display Image", res);
    waitKey(0);

    return 0;
}