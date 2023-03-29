#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat image;

    // Reading image
    image = imread("PROJECT_SOURCE_DIR/assets/images/purple_night.jpg");
    if (!image.data)
    {
        cout << "Image not found" << endl;
        return -1;
    }

    Mat im2;

    // Converts colorspace from BGR to Grayscale (BGR2GRAY)
    cvtColor(image, im2, COLOR_BGR2GRAY);

    auto x = im2.size;

    // x[0] - height of the image (number of rows)
    // x[1] - width of the image (number of columns)
    cout << x[0] << ',' << x[1] << endl;
    cout << im2.channels() << endl;

    // Display resultant image
    namedWindow("Display Image");
    imshow("Display Image", im2);
    waitKey(0);

    return 0;
}
