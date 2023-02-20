#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("PROJECT_SOURCE_DIR/assets/images/purple_night.jpg");
    if (!image.data)
    {
        cout << "Image not found" << endl;
        return -1;
    }

    auto x = image.size;

    // x[0] - height of the image (number of rows)
    // x[1] - width of the image (number of columns)
    cout << x[0] << ',' << x[1] << endl;
    cout << image.channels() << endl;
    cout << typeid(image).name() << endl;
    namedWindow("Display Image");
    imshow("Display Image", image);
    waitKey(0);

    return 0;
}
