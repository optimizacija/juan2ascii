#include "asciiconverter.h"

#include <iostream>

std::string img2ascii(const cv::Mat& edge_angles) {
    constexpr char edges_c[] = {'|', '\\', '-', '/', '|'};
    constexpr char empty = ' ';
    constexpr int size = sizeof(edges_c) / sizeof(edges_c[0]);

    const int rows = edge_angles.rows;
    const int cols = edge_angles.cols;

    std::string solution;
    solution.reserve(rows * (cols + 1));

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            const float angle = edge_angles.at<float>(y, x);

            if (angle == NO_EDGE) {
                solution += empty;
            } else {
                // check in what range does the angle fall in
                // and put the appropriate character for that edge
                for (int i = 0; i < size; ++i) {
                    if (angle <= (-M_PI / 2 + M_PI / ((size - 1) * 2) + i * M_PI / (size - 1))) {
                        solution += edges_c[i];
                        break;
                    }
                }
            }
        }
        solution += '\n';
    }
    return solution;
}
