#include "edge_detection.h"

void calcEdges(const cv::Mat& src, cv::Mat& edge_angle, cv::Mat& edge_strength) {
    // use the sobel operators, to find horizontal and vertical edges

    float m_sobelx[3][3] = {{-1.f, -2.f, -1.f}, {0.f, 0.f, 0.f}, {1.f, 2.f, 1.f}};
    const cv::Mat struct_ele_x(3, 3, CV_32F, m_sobelx);

    float m_sobely[3][3] = {{-1.f, 0.f, 1.f}, {-2.f, 0.f, 2.f}, {-1.f, 0.f, 1.f}};
    const cv::Mat struct_ele_y(3, 3, CV_32F, m_sobely);

    cv::Mat sobelx;
    cv::filter2D(src, sobelx, -1, struct_ele_x);
    cv::Mat sobely;
    cv::filter2D(src, sobely, -1, struct_ele_y);

    // calculate the edges' slope consider the opposite slopes to be the same
    edge_angle = atan(sobely, sobelx);
    // calculate the edges' "presence"/strength
    cv::sqrt(sobelx.mul(sobelx) + sobely.mul(sobely), edge_strength);
}

cv::Mat atan(const cv::Mat& sobely, const cv::Mat& sobelx) {
    const int rows = sobely.rows;
    const int cols = sobely.cols;

    cv::Mat angles(rows, cols, CV_32F);

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            float ty = sobely.at<float>(y, x);
            float tx = sobelx.at<float>(y, x);
            if (tx == 0.)
                tx = 0.00001f;
            angles.at<float>(y, x) = atan(ty / tx);
        }
    }

    return angles;
}
