// Fill in the functions definitions for the following tasks:

// 1. Draw a solid circle on the image
// 2. Draw a solid rectangle or square on the image
// 3. Draw a hollow circle on the image
// 4. Draw a hollow rectangle or square on the image
// 5. Rotate image by any angle

// Helper functions are provided for:
// 1. save/write image
// 2. set pixel value in an image
// 3. display image

#include "2_playing_with_images.hpp"

using namespace cv;
using namespace std;

//HELPER FUNCTIONS
// Set pixel channel value at x,y coordinates in image
void setPixel(Mat *img, int x, int y, int channel, int value)
{
    Vec3b &color = img->at<Vec3b>(y, x);
    color[0] = 0;
}

// Save / write image
void saveImg(Mat img, string filename, string path)
{
    imwrite(path + filename, img);
}

// Display Image and wait till key is pressed
void displayImg(Mat img, string str)
{
    namedWindow(str, WINDOW_NORMAL);
    imshow(str, img);
    waitKey(0);
}



// FUNCTIONS TO BE WRITTEN:
// Draw a solid circle on the image
Mat solidCircle(Mat img, int x, int y, int r)
{
    // Make copy of image
    Mat img_cpy = img.clone();

    // Add code here

    return img_cpy;
}

// Draw a solid rectangle or square on the image
Mat solidRec(Mat img, int x, int y, int h, int w)
{
    // Make copy of image
    Mat img_cpy = img.clone();

    // Add code here

    return img_cpy;
}

// Draw a hollow circle on the image
Mat hollowCircle(Mat img, int x, int y, int r, int t)
{
    // Make copy of image
    Mat img_cpy = img.clone();

    // Add code here

    return img_cpy;
}

// Draw a hollow rectangle or square on the image
Mat hollowRec(Mat img, int x, int y, int h, int w, int t)
{
    // Make copy of image
    Mat img_cpy = img.clone();

    // Add code here

    return img_cpy;
}

// Rotate image by any angle
Mat rotateImg(Mat img, int angle)
{
    // Make copy of image
    Mat img_cpy = img.clone();

    // Add code here

    return img_cpy;
}

int main()
{
    // Read image using OpenCV
    Mat image = imread("assets/images/add.PNG", IMREAD_COLOR);

    // call functions here

    return 0;
}