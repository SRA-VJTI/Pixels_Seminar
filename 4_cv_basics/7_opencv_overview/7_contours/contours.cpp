#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img;
    img = imread("PROJECT_SOURCE_DIR/assets/images/DK.jpeg");

    // 1. Convert to Grayscale
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    imshow("Gray", gray);

    // 2. Apply Canny Edge detection
    Mat edges;
    Canny(gray, edges, 170, 250);
    imshow("edges", edges);

    // 3. Find contours
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(edges, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    imshow("Canny edges after contouring", edges);

    // 4. Draw contours on image
    Mat contourImg = Mat::zeros(img.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); i++)
    {
        drawContours(img, contours, i, Scalar(0, 255, 0), 2);
    }

    imshow("Contours", img);
    waitKey(0);
    destroyAllWindows();
}
