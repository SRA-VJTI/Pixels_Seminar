# Blob Detection
BLOB stands for Binary Large Object

Informally a blob is a region of an image in which some properties like intensity or color are approximately constant.

## Capturing image from the webcam
---

```
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return 1;
    }
```
The code above open the first webcam plugged in the computer.

---
Create a window to display the images from the webcam
```
    cv::namedWindow("Webcam", 100);
```

Capture the next frame from the webcam
```
    cv::Mat im;
        
    camera >> im;
```

Display the frame until you press a key<br>
Show the image on the window named Webcam

```
    while (1) {
        cv::imshow("Webcam", im);
        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) >= 0)
            break;
    }
```

---
## Selecting region of interest and cropping

```
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
```
## Converting to HSV and finding bounding values for mask
1. Why converting to HSV?<br>
Since we are using the web cam the intensity and illumination of consecutive frame does not remain same.
Hence to find the color in range instead of particular color. HSV format is useful as H value denotes specific color and S, V can be used for illumination and intensity.



1. Calculating the median H,S,V values from roi

1. Initializing the lower and upper bound for mask

```
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
```

--- 
## Detecting the blob
### Constructing mask for detection of blob
1. Convert to HSV

1. Make a mask using `inRange()` by passing lower and upper bounds calculated earlier

* What is a mask?<br>
A mask is a binary image consisting of zero and non-zero values. If a mask is applied to another image of the same size, all pixels which are zero in the mask are set to zero in the output image. All others remain unchanged.

3. Blur the mask to remove the noise using `medianBlur()`
 
1. Placing mask over frame to finded colored mask using `bitwise_and()`

```
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
```
## Drawing the blob
1. Find the contour from the generated mask using `findContours()`

	* What is a contour?<br>
	Contours can be explained simply as a curve joining all the continuous points (along the boundary), having same color or intensity. The contours are a useful tool for shape analysis and object detection and recognition
1. Find the contour having the maximum area using `contourArea()`
1. Draw the contour on the frame using `drawContours()`

```
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
```