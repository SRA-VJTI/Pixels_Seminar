#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Create a black image
    Mat image = Mat::zeros( 400, 400, CV_8UC3 );

    // Write some Text
    putText(image, "Hello World :)", Point(15, 200),
        FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 0), 3);

    imshow("Hello World", image);

    // Wait for a keystroke in the window
    waitKey(0);
    return 0;
}