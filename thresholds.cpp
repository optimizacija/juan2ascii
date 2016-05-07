#include "thresholds.h"

float kapurThresh(cv::Mat hist) {
    using namespace std;
    const float size = hist.rows;
    hist += 0.01;
    float sum = cv::sum(hist)[0];
    hist /= sum;

    cv::Mat log_hist;
    hist.copyTo(log_hist);
    for (int i = 0; i < size; ++i) {
        log_hist.at<float>(i) = log(hist.at<float>(i)) * hist.at<float>(i);
    }

    cv::Mat entropy;
    hist.copyTo(entropy);
    entropy.at<float>(0) = -cv::sum(log_hist)[0];
    entropy.at<float>(size - 1) = entropy.at<float>(0);

    float partial_sum = hist.at<float>(0);
    for (int i = 1; i < size - 1; ++i) {
        partial_sum += hist.at<float>(i);

        // background
        float inner_sum = 0.;
        for (int j = 0; j < i; ++j) {
            float curr = hist.at<float>(j);
            inner_sum += curr / partial_sum * log(curr / partial_sum);
        }
        entropy.at<float>(i) = -inner_sum;

        // object
        inner_sum = 0.;
        float temp_sum = 1. - partial_sum;
        for (int j = i; j < size; ++j) {
            float curr = hist.at<float>(j);
            inner_sum += curr / temp_sum * log(curr / temp_sum);
        }
        entropy.at<float>(i) += -inner_sum;
    }

    return maxVal<float>(entropy);
}

float Ak(const cv::Mat& hist, int k) {
    float sum = 0.f;
    for (int i = 0; i < k; ++i) {
        sum += hist.at<float>(i);
    }
    return sum;
}

float Bk(const cv::Mat& hist, int k) {
    float sum = 0.f;
    for (int i = 0; i < k; ++i) {
        sum += i * hist.at<float>(i);
    }
    return sum;
}

float optimalThresh(const cv::Mat& gray_image) {
    cv::Mat hist = getHist(gray_image);
    float Aq = Ak(hist, 255);
    float Bq = Bk(hist, 255);

    int T = round(kapurThresh(hist));
    float AT = Ak(hist, T);
    float BT = Bk(hist, T);
    float uT = BT / AT;
    float gT = (Bq - BT) / (Aq - AT);
    int nT = (uT + gT) / 2.f;

    do {
        if (nT == T)
            break;

        T = nT;

        AT = Ak(hist, T);
        BT = Bk(hist, T);
        uT = BT / AT;
        gT = (Bq - BT) / (Aq - AT);
        nT = (uT + gT) / 2.f;

    } while (true);

    return T;
}

cv::Mat getHist(const cv::Mat& gray_image) {
    int hist_size = 255;
    const float range[] = {0., 255.};
    const float* ranges[] = {range};
    cv::Mat hist(cv::Size(1, 255), CV_32F);
    cv::calcHist(&gray_image, 1, 0, cv::Mat(), hist, 1, &hist_size, ranges, true, false);

    return hist;
}
