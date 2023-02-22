#include "opencv2/opencv.hpp"
#include "iostream"
using namespace cv;
using namespace std;
int main(int, char**) {
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return 1;
    }


    cv::namedWindow("Webcam", 100);


    cv::Mat frame;
        
    camera >> frame;
    
    while (1) {
        cv::imshow("Webcam", frame);
        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) >= 0)
            break;
    }

// Blob detection 
	SimpleBlobDetector::Params params;

	// Change thresholds
	params.minThreshold = 10;
	params.maxThreshold = 200;

	// Filter by Area.
	params.filterByArea = true;
	params.minArea = 500;

	// Filter by Circularity
	params.filterByCircularity = true;
	params.minCircularity = 0.1;

	// Filter by Convexity
	params.filterByConvexity = true;
	params.minConvexity = 0.87;

	// Filter by Inertia
	params.filterByInertia = true;
	params.minInertiaRatio = 0.01;


	// Storage for blobs
	vector<KeyPoint> keypoints;


#if CV_MAJOR_VERSION < 3   // If you are using OpenCV 2

	// Set up detector with params
	SimpleBlobDetector detector(params);

	// Detect blobs
	detector.detect( frame, keypoints);
#else 

	// Set up detector with params
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);   

	// Detect blobs
	detector->detect( frame, keypoints);
#endif 

	// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures
	// the size of the circle corresponds to the size of blob

	Mat im_with_keypoints;
	drawKeypoints( frame, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );

	// Show blobs
	imshow("blobs detected", im_with_keypoints );
	waitKey(0);

    return 0;
}
