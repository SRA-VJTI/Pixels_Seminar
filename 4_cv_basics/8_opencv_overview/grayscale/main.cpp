#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("../../assets/purple_night.jpg");
    if (!image.data)
    {
        cout << "Image not found" << endl;
        return -1;
    }

    Mat im2;

    cvtColor(image, im2, COLOR_BGR2GRAY);

    auto x = im2.size;

    cout << x[0] << ',' << x[1] << endl;
    cout << im2.channels() << endl;

    namedWindow("Display Image");
    imshow("Display Image", im2);
    waitKey(0);

    return 0;
}