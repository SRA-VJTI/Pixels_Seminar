#include "segmentation.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <stdexcept>

ImageSegmenter::ImageSegmenter() : mouseData{ cv::Mat(), cv::Rect(), false } {}

void ImageSegmenter::onMouse(int event, int x, int y, int flags, void* userdata) {
    MouseData* data = static_cast<MouseData*>(userdata);
    
    if (event == cv::EVENT_LBUTTONDOWN) {
        data->isSelecting = true;
        data->roi.x = x;
        data->roi.y = y;
    }
    else if (event == cv::EVENT_MOUSEMOVE && data->isSelecting) {
        data->roi.width = x - data->roi.x;
        data->roi.height = y - data->roi.y;
        
        cv::Mat temp = data->image.clone();
        cv::rectangle(temp, data->roi, cv::Scalar(0, 255, 0), 2);
        cv::imshow("Select ROI", temp);
    }
    else if (event == cv::EVENT_LBUTTONUP) {
        data->isSelecting = false;
        data->roi.width = x - data->roi.x;
        data->roi.height = y - data->roi.y;
    }
}

cv::Rect ImageSegmenter::selectROI(const cv::Mat& image) {
    mouseData.image = image.clone();
    mouseData.isSelecting = false;
    
    cv::namedWindow("Select ROI", cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("Select ROI", onMouse, &mouseData);
    
    cv::imshow("Select ROI", image);
    cv::waitKey(0);
    cv::destroyWindow("Select ROI");
    
    return mouseData.roi;
}

void ImageSegmenter::applyGrabCut(const cv::Mat& image, cv::Mat& output, const cv::Rect& roi) {
    if (image.empty()) {
        throw std::runtime_error("Error: Image is empty!");
    }

    cv::Rect finalRoi = roi;
    if (roi.empty()) {
        finalRoi = selectROI(image);
    }

    if (finalRoi.width <= 0 || finalRoi.height <= 0) {
        throw std::runtime_error("Error: Invalid ROI selected!");
    }

    cv::Mat mask, bgModel, fgModel;
    try {
        cv::grabCut(image, mask, finalRoi, bgModel, fgModel, 5, cv::GC_INIT_WITH_RECT);
        cv::compare(mask, cv::GC_PR_FGD, mask, cv::CMP_EQ);

        output = cv::Mat(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
        image.copyTo(output, mask);
    } catch (const cv::Exception& e) {
        throw std::runtime_error("GrabCut error: " + std::string(e.what()));
    }
}
