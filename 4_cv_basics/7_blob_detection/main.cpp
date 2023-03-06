#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

double median(vector<double> vec)
{
    int size = vec.size();
    if (size == 0)
    {
        return 0; // Handle empty vector case
    }
    sort(vec.begin(), vec.end());
    if (size % 2 == 0)
    {
        // Even number of elements, take average of middle 2
        return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
    }
    else
    {
        // Odd number of elements, take middle element
        return vec[size / 2];
    }
}

tuple<double, double, double> getMedianPixelValues(Mat img)
{
    // Initialize vectors to store the pixel values of each color channel
    vector<double> blue_pixels;
    vector<double> green_pixels;
    vector<double> red_pixels;

    // Iterate over the rows and columns of the image
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            // Access the pixel value at (i, j)
            Vec3b pixel = img.at<Vec3b>(i, j);

            // Add the pixel values to the corresponding vectors
            blue_pixels.push_back(pixel[0]);
            green_pixels.push_back(pixel[1]);
            red_pixels.push_back(pixel[2]);
        }
    }

    // Calculate the median of each color channel
    double blue_median = median(blue_pixels);
    double green_median = median(green_pixels);
    double red_median = median(red_pixels);

    // Return the median values as a tuple
    return make_tuple(blue_median, green_median, red_median);
}

int main()
{
    VideoCapture video(0);
    int h = 0, s = 0, v = 0;
    while (video.isOpened())
    {
        Mat frame;
        video.read(frame);
        imshow("Image", frame);

        if (waitKey(10) == 'q')
        {
            Rect bbox = selectROI("Image", frame, false, false);
            Mat hsv;
            cvtColor(frame, hsv, COLOR_BGR2HSV);
            Mat obj_img = hsv(Rect(bbox.x, bbox.y, bbox.width, bbox.height));
            tuple<double, double, double> medians = getMedianPixelValues(obj_img);
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
