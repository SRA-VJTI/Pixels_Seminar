#ifndef SEGMENTATION_HPP
#define SEGMENTATION_HPP

#include <opencv2/opencv.hpp>

class ImageSegmenter {
public:
    ImageSegmenter();
    
    // GrabCut segmentation
    void applyGrabCut(const cv::Mat& image, cv::Mat& output, const cv::Rect& roi = cv::Rect());
    
    // Utility methods
    cv::Rect selectROI(const cv::Mat& image);
    
private:
    // Mouse callback data
    struct MouseData {
        cv::Mat image;
        cv::Rect roi;
        bool isSelecting;
    };
    
    MouseData mouseData;
    
    // Mouse callback function
    static void onMouse(int event, int x, int y, int flags, void* userdata);
};

#endif // SEGMENTATION_HPP
