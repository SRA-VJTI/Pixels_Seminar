#include <opencv2/opencv.hpp>
// selectROI is part of tracking API
// #include <opencv2/tracking.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace cv;

int main(int argc, char **arv)
{
    cv::VideoCapture camera(0);
    if (!camera.isOpened())
    {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return 1;
    }

    cv::namedWindow("Webcam", 100);

    cv::Mat im;

    camera >> im;

    while (1)
    {
        cv::imshow("Webcam", im);
        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) >= 0)
            break;
    }

    // Read image (When not using webcam)
    // Mat im = imread("image.jpg");

    Mat orig_img = im;

    // Select ROI
    Rect2d r = selectROI(im);

    // Crop image
    Mat imCrop = im(r);

    // Display Cropped Image
    imshow("Image", imCrop);
    waitKey(0);
    destroyAllWindows();

    // To get the ROI co-ordinates in the original image///////////
    Point offset;
    Size wholesize;
    imCrop.locateROI(wholesize, offset);
    cout << "imgRoi Offset: " << offset.x << "," << offset.y << endl;

    int x1, x2, y1, y2;
    x1 = offset.x;
    x2 = x1 + imCrop.cols;
    y1 = offset.y;
    y2 = y1 + y1 + imCrop.rows;

    // median hsv ////////////////////////////////////////////////////
    set<double> h_values, s_values, v_values;
    int counter = 0;
    Mat cropHsv;
    cv::cvtColor(imCrop, cropHsv, cv::COLOR_BGR2HSV);
    for (int i = y1; i < y2; i++)
    {
        for (int j = x1; j < x2; j++)
        {
            h_values.insert(cropHsv.at<Vec3b>(i, j)[0]);
            s_values.insert(cropHsv.at<Vec3b>(i, j)[1]);
            v_values.insert(cropHsv.at<Vec3b>(i, j)[2]);
            counter++;
        }
    }
    auto it_h = h_values.begin();
    auto it_s = s_values.begin();
    auto it_v = v_values.begin();

    for (auto x : h_values)
        cout << x << " ";
    for (int k = 0; k < h_values.size() / 2; k++)
    {
        it_h++;
        it_s++;
        it_v++;
    }
    double h, s, v;
    h = *it_h; // median of hue
    s = *it_s; // median of saturation
    v = *it_v; // median of value
    // cout << "Medians: " << h << " " << s << " " << v << endl;
    vector<double> lower, upper;
    lower.push_back(h - 5);
    lower.push_back(min(double(0), s - 50));
    lower.push_back(min(double(0), v - 50));

    upper.push_back(h + 5);
    upper.push_back(max(s + 50, double(255)));
    upper.push_back(max(v + 50, double(255)));

    ///// Creating hsv of the frame /////////////////////////
    Mat hsv;
    cv::cvtColor(orig_img, hsv, cv::COLOR_RGB2HSV);
    imshow("hsv_full", hsv);
    waitKey(0);
    destroyAllWindows();

    // Masking /////////////////////////////////////////////
    Mat masked;
    inRange(hsv, Scalar(0.0, lower[1], lower[2]), Scalar(5.0, upper[1], upper[2]), masked);
    imshow("masked_full", masked);
    waitKey(0);
    destroyAllWindows();
    ///////////////// Median Blur //////////
    Mat blur;
    medianBlur(masked, blur, 5);
    imshow("blur", blur);
    waitKey(0);
    destroyAllWindows();
    //////////////////////////
    Mat output;
    bitwise_and(im, im,output, blur);
    imshow("output", output);
    waitKey(0);
    destroyAllWindows();
    //////////////////////////

    vector<vector<cv::Point>> contours;
    vector<Vec4i> hierarchy;
    cv::Mat contourOutput = blur.clone();
    cv::findContours(contourOutput, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    imshow("contours", contourOutput);
    waitKey(0);
    destroyAllWindows();
    int area=0;
    int count=0;int largest=0;
    for (size_t i = 0; i < contours.size(); i++)
    {
        if(contourArea(contours[i])>area)
        {
        largest=i;
        area=contourArea(contours[i]);
        }
        count++;
    }
    drawContours(im, contours, largest, Scalar(0, 255, 0), 2, LINE_8, hierarchy, 0);
    imshow("contours", im);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
