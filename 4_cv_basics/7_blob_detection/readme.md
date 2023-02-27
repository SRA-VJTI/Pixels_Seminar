# Blob Detection

BLOB stands for Binary Large Object

Informally a blob is a region of an image in which some properties like intensity or color are approximately constant.

## Capturing image from the webcam

---

The code below opens the first webcam plugged in the computer.

```cpp
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

```

---

Create a window to display what is captured by the webcam. Press q to capture a particular frame

```cpp
 while (1)
    {
        camera >> im; // 1 - To get a continuous feed
        cv::imshow("Webcam", im);

        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) == 'q')
        {
            Mat orig_img = im;
```

---

## Selecting region of interest and cropping

```cpp
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
```

## Converting to HSV and finding bounding values for mask

1. Why converting to HSV?<br>
   Since we are using the web cam the intensity and illumination of consecutive frame does not remain same.
   Hence to find the color in range instead of particular color. HSV format is useful as H value denotes specific color and S, V can be used for illumination and intensity.

1. Calculating the median H,S,V values from roi

1. Initializing the lower and upper bound for mask

```cpp
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
```

---

## Detecting the blob

### Constructing mask for detection of blob

1. Convert to HSV

1. Make a mask using `inRange()` by passing lower and upper bounds calculated earlier

- What is a mask?<br>
  A mask is a binary image consisting of zero and non-zero values. If a mask is applied to another image of the same size, all pixels which are zero in the mask are set to zero in the output image. All others remain unchanged.

3. Blur the mask to remove the noise using `medianBlur()`

1. Placing mask over frame to finded colored mask using `bitwise_and()`

```cpp
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
```

## Drawing the blob

1. Find the contour from the generated mask using `findContours()`

   - What is a contour?<br>
     Contours can be explained simply as a curve joining all the continuous points (along the boundary), having same color or intensity. The contours are a useful tool for shape analysis and object detection and recognition

1. Find the contour having the maximum area using `contourArea()`
1. Draw the contour on the frame using `drawContours()`

```cpp
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
```
