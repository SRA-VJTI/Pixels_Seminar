#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include "include/blob_detection.hpp"
using namespace std;
using namespace cv;

int main()
{
    VideoCapture video(0); // Read input video
    int h = 0, s = 0, v = 0;
    while (video.isOpened())
    {
        Mat frame;
        video.read(frame); // Read one frame from the video
        imshow("Image", frame);

        if (waitKey(10) == 'q') //Wait for "q" key to be pressed
        {
            Rect bbox = selectROI("Image", frame, false, false); // Select a region of interest on the image
            Mat hsv;
            cvtColor(frame, hsv, COLOR_BGR2HSV); // Convert BGR color model to HSV
            Mat obj_img = hsv(Rect(bbox.x, bbox.y, bbox.width, bbox.height));
            tuple<double, double, double> medians = getMedianPixelValues(obj_img); // Find the median of HSV in the selected region.
            h = get<0>(medians);
            s = get<1>(medians);
            v = get<2>(medians);
            break;
        }
    }

    while (video.isOpened())
    {
        Mat frame;
        video.read(frame);

        // Converting to hsv
        Mat hsv;
        cvtColor(frame, hsv, COLOR_BGR2HSV);


        // Getting lower and upper bounds for h,s,v values
        Scalar lower(h - 5, max(0, s - 50), max(0, v - 50));
        Scalar upper(h + 5, min(s + 50, 255), min(v + 50, 255));

        // Masking
        Mat masked;
        inRange(hsv, lower, upper, masked);

        // Median Blur
        Mat blur;
        medianBlur(masked, blur, 5);

        // Performing bitwise_and using the 'blur' mask
        Mat blob_mask;
        bitwise_and(frame, frame, blob_mask, blur);

        imshow("blob_mask", blob_mask);

        // Find contours
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(blur, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);


        // Find largest contour
        int idx = 0;
        double current_max = 0;
        int counter = 0;

        for (const auto &n : contours)
        {
            double area = contourArea(n);
            if (area > current_max)
            {
                current_max = area;
                idx = counter;
            }
            counter++;
        }

        // Draw the largest contour detected
        drawContours(frame, contours, idx, Scalar(0, 255, 255), 2);
        imshow("Output", frame);

        if (waitKey(10) == 'x')
        {
            destroyAllWindows();
            video.release();
            break;
        }
    }

    return 0;
}
