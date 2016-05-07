#include <iostream>
#include <cstdio>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "edge_detection.h"
#include "thresholds.h"
#include "show.h"
#include "asciiconverter.h"
#include "stopwatch.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "USAGE: program [path_to_image] (width)  (height)" << std::endl;
        std::cout << "                               optional optional" << std::endl;
        return 0;
    }

    cv::Mat img = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    if (!img.data)
        return 0;

    int rows = 0;
    int cols = 0;

    if (argc > 2) {
        rows = std::stoi(argv[2]);
        if (argc > 3) {
            cols = std::stoi(argv[3]);
        } else {
            cols = rows;
        }
    } else {
        rows = cols = 50;
    }

    /// jam::StopWatch sw;
    /// sw.start();

    // let's get to it
    img.convertTo(img, CV_32F);
    cv::resize(img, img, cv::Size(rows, cols), 0, 0, CV_INTER_AREA);

    // get image's edges
    cv::Mat edge_angles, edge_strength;
    calcEdges(img, edge_angles, edge_strength);

    // remove noisy edges
    // find a mask of non-noisy edges
    const float thresh = optimalThresh(edge_strength) * 2;
    cv::Mat bin_img(rows, cols, CV_8U);
    cv::threshold(edge_strength, bin_img, thresh, 1, CV_THRESH_BINARY);
    bin_img.convertTo(bin_img, CV_8U);

    // set the non-noisy edges, and mark the noisy ones
    cv::Mat result_angles(rows, cols, CV_32F);
    result_angles = NO_EDGE;
    edge_angles.copyTo(result_angles, bin_img);

    // generate a string out of edges
    std::string result = img2ascii(result_angles);

    // print the string
    puts(result.c_str());
    /// sw.measure();
    /// std::cout << sw.asMilliseconds() << std::endl;

    /*
    cv::namedWindow("debug", CV_WINDOW_NORMAL);
    show(img);
    show(edge_strength);
    show((result_angles + M_PI / 2) * (255 / M_PI));
    */

    return 0;
}
