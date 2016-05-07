#ifndef ASCIICONVERTER_H
#define ASCIICONVERTER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>
#include <string>

constexpr float NO_EDGE = 1337;

std::string img2ascii(const cv::Mat &edge_angles);

#endif // ASCIICONVERTER_H
