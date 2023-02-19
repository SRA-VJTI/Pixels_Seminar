#include "2_build_systems.hpp"

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
    
    //display an image from the $PROJECT_SOURCE_DIR/assets/images/b&w.PNG
    Mat img = imread("PROJECT_SOURCE_DIR/assets/images/bcci.png", IMREAD_COLOR);
    imshow("b&w", img);

    // Wait for a keystroke in the window
    waitKey(0);
    return 0;
}