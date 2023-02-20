#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("PROJECT_SOURCE_DIR/assets/images/gray.png");
    if (!image.data)
    {
        cout << "Image not found" << endl;
        return -1;
    }

    Mat im2;

    Size new_size;

    new_size.height = 200;
    new_size.width = 700;

    resize(image, im2, new_size);

    namedWindow("Display Image");
    imshow("Display Image", im2);
    waitKey(0);

    return 0;
}