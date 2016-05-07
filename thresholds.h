#ifndef THRESHOLDS_H
#define THRESHOLDS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

template <typename T>
T maxVal(const cv::Mat& hist) {
    const int size = hist.rows;
    T max = 0.;
    for (int i = 0; i < size; ++i) {
        if (hist.at<T>(i) > max)
            max = hist.at<T>(i);
    }

    return max;
}
template <typename T>
T minVal(const cv::Mat& hist) {
    const int size = hist.rows;
    if (size == 0)
        return 0;

    T min = hist.at<T>(0);
    for (int i = 1; i < size; ++i) {
        if (hist.at<T>(i) < min)
            min = hist.at<T>(i);
    }

    return min;
}

float kapurThresh(cv::Mat hist);

float Ak(const cv::Mat& hist, int k);
float Bk(const cv::Mat& hist, int k);

float optimalThresh(const cv::Mat& gray_image);

cv::Mat getHist(const cv::Mat& gray_image);

#endif  // THRESHOLDS_H
