#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Read image
    Mat img = imread("PROJECT_SOURCE_DIR/assets/images/DK.jpeg");
    imshow("Image", img);

    // Convert image to hsv
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);
    imshow("HSV", hsv);

    // hsv format -> (min hue, min saturation , min value) -> (max hue, max saturation , max value)
    // RED mask =>
    // Mat mask1 = inRange(hsv, Scalar(0, 100, 0), Scalar(10, 255, 255));

    // YELLOW mask =>

    Mat mask1;
    inRange(hsv, Scalar(15, 30, 150), Scalar(36, 255, 255), mask1);
    imshow("mask1", mask1);

    // BLUE mask =>
    Mat mask2;
    inRange(hsv, Scalar(33, 52, 80), Scalar(150, 200, 255), mask2);
    imshow("mask2", mask2);

    // Final mask and masked
    Mat mask;
    bitwise_or(mask1, mask2, mask);
    imshow("mask", mask);

    Mat target;
    bitwise_and(img, img, target, mask);
    imshow("target", target);

    waitKey(0);
    destroyAllWindows();

    return 0;
}