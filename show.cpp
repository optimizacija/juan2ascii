#include "show.h"

void show(const cv::Mat& image) {
    cv::Mat copy = image.clone();

    copy.convertTo(copy, 0);
    cv::imshow("debug", copy);
    cv::waitKey(0);
}
