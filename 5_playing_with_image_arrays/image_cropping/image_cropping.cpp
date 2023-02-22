//including the necessary header files
#include <iostream>
//the following header files are from the OpenCV library for C++
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    //reading an image and converting to cv::Mat format
    Mat img = imread("dog.jpeg");
    Mat img2, img4;

    //obtaining the dimensions of the image
    int width = img.size().width;
    int height = img.size().height;
    cout << "Width of the image: " << width << endl;
    cout << "Height of the image: " << height << endl;

    //image compression
    //resizing an image-this essentially removes every alternate pixel rows
    resize(img, img4, Size(width/2, height/2));

    //cropping an image
    img(Rect(0, 0, 150, 150)).copyTo(img2);

    //displaying the images
    imshow("window", img);
    imshow("resized image", img4);
    imshow("cropped image", img2);
    waitKey(0);

    return 0;
}

// int main(int argc, char** argv)
// {
//     // Read the image file as
//     // imread("default.jpg");
//     Mat image = imread("lion.jpeg", IMREAD_GRAYSCALE);
  
//     // Error Handling
//     if (image.empty()) {
//         cout << "Image File Not Found" << endl;
  
//         // wait for any key press
//         cin.get();
//         return -1;
//     }
  
//     // Show Image inside a window with the name provided
//     imshow("Window Name", image);
  
//     // Wait for any keystroke
//     waitKey(0);
//     return 0;
// }