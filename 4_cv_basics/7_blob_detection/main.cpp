#include <opencv2/opencv.hpp>

#include <bits/stdc++.h>
using namespace std;
using namespace cv;

double median(vector<double> vec)
{
    int size = vec.size();
    if (size == 0)
    {
        return 0; // Handle empty vector case
    }
    std::sort(vec.begin(), vec.end());
    if (size % 2 == 0)
    {
        // Even number of elements, take average of middle two
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
vector<double> lower, upper;
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

    while (1)
    {
        camera >> im; // 1 - To get a continuous feed
        cv::imshow("Webcam", im);

        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) == 'q')
        {
            Mat orig_img = im;

            // Select ROI
            Rect2d r = selectROI(im);

            // Crop image
            Mat imCrop = im(r);

            // Display Cropped Image
            imshow("Image", imCrop);

            // To get the ROI co-ordinates in the original image
            Point offset;
            Size wholesize;
            imCrop.locateROI(wholesize, offset);
            cout << "imgRoi Offset: " << offset.x << "," << offset.y << endl;

            int x1, x2, y1, y2;
            x1 = offset.x;
            x2 = x1 + imCrop.cols;
            y1 = offset.y;
            y2 = y1 + y1 + imCrop.rows;

            // Getiing medians of h,s,v to set lower and upper bounds
            Mat cropHsv;
            cv::cvtColor(imCrop, cropHsv, cv::COLOR_BGR2HSV);
            tuple<double, double, double> medians = getMedianPixelValues(cropHsv);
            double h, s, v;
            h = get<0>(medians);
            s = get<1>(medians);
            v = get<2>(medians);
            // Max <--> Min
            lower.push_back(h - 5);
            lower.push_back(max(double(0), s - 50));
            lower.push_back(max(double(0), v - 50));

            upper.push_back(h + 5);
            upper.push_back(min(s + 50, double(255)));
            upper.push_back(min(v + 50, double(255)));

            break;
        }
    }

    while (1)
    {
        // Converting to hsv
        Mat frame;
        camera >> frame;
        Mat hsv;
        cv::cvtColor(frame, hsv, cv::COLOR_RGB2HSV);
        imshow("hsv_full", hsv);

        // Masking
        cv::Mat masked;
        cv::inRange(hsv, cv::Scalar(lower[0], lower[1], lower[2]), cv::Scalar(upper[0], upper[1], upper[2]), masked);
        imshow("masked_full", masked);

        // Median Blur
        Mat blur;
        medianBlur(masked, blur, 5);
        imshow("blur", blur);

        // Performing bitwise_and using the 'blur' mask
        Mat output;
        bitwise_and(frame, frame, output, blur);
        imshow("output", output);

        // Find contours
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(blur, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

        // Find largest contour
        int largestIdx = -1;
        int largestArea = 0;
        for (int i = 0; i < contours.size(); i++)
        {
            int area = contourArea(contours[i]);
            if (area > largestArea)
            {
                largestArea = area;
                largestIdx = i;
            }
        }

        // Draw largest contour on frame
        if (largestIdx >= 0)
        {
            drawContours(frame, contours, largestIdx, Scalar(0, 255, 0), 2);
        }

        // Show frame
        imshow("Blob detected", frame);
        waitKey(10);
        if (cv::waitKey(10) == 'x')
        {
            destroyAllWindows();
            camera.release();
        }
    }

    return 0;
}
