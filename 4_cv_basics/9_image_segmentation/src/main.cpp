#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "segmentation.hpp"

int main() {
    try {
        cv::Mat image = cv::imread("assets/cat1.jpeg");
        if (image.empty()) {
            throw std::runtime_error("Error: Could not load image!");
        }

        ImageSegmenter segmenter;
        cv::Mat segmented;
        segmenter.applyGrabCut(image, segmented);

        cv::imshow("Original Image", image);
        cv::imshow("Segmented Image", segmented);
        cv::waitKey(0);
        cv::destroyAllWindows();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
