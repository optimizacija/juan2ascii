#ifndef EDGE_DETECTION_H
#define EDGE_DETECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "show.h"

cv::Mat atan(const cv::Mat& sobely, const cv::Mat& sobelx);

void calcEdges(const cv::Mat& src, cv::Mat& edge_angle, cv::Mat& edge_strength);

#endif  // EDGE_DETECTION_H
