//
// Created by asekulsk on 01.12.16.
//

#include "HarrisCorner.h"


HarrisCorner::HarrisCorner() {

}

HarrisCorner::~HarrisCorner() {

}

void HarrisCorner::doNothing(cv::Mat image) {

    int thresh = 220;

    cv::Mat dst, dst_norm, dst_norm_scaled;
    dst = cv::Mat::zeros(image.size(), CV_32FC1);

    /// Detector parameters
    int blockSize = 6;
    int apertureSize = 3;
    double k = 0.04;

    /// Detecting corners
    cornerHarris(image, dst, blockSize, apertureSize, k);

    /// Normalizing
    normalize(dst, dst_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
    convertScaleAbs(dst_norm, dst_norm_scaled);

    /// Drawing a circle around corners

    for (int j = 0; j < dst_norm.rows; j++) {
        for (int i = 0; i < dst_norm.cols; i++) {
            if ((int) dst_norm.at<float>(j, i) > thresh) {
                circle(dst_norm_scaled, cv::Point(i, j), 5, cv::Scalar(224, 245, 255), 2, 8, 0);
            }
        }
    }

    /// Showing the result
    imshow("Corners detected", dst_norm_scaled);
}

void HarrisCorner::doConturs(cv::Mat image) {
    int largest_area = 0;
    int largest_contour_index = 0;
    cv::Rect bounding_rect;

    cv::Mat src = image;

    cv::Mat thr(src.rows, src.cols, CV_8UC1);
    cv::Mat dst(src.rows, src.cols, CV_8UC1, cv::Scalar::all(0));

    cv::threshold(thr, thr, 25, 255, cv::THRESH_BINARY); //Threshold the gray

    std::vector<std::vector<cv::Point>> contours; // Vector for storing contour
    std::vector<cv::Vec4i> hierarchy;

    findContours(thr, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE); // Find the contours in the image

    for (int i = 0; i < contours.size(); i++) // iterate through each contour.
    {
        double a = contourArea(contours[i], false);  //  Find the area of contour
        if (a > largest_area) {
            largest_area = a;
            largest_contour_index = i;                //Store the index of largest contour
            bounding_rect = boundingRect(contours[i]); // Find the bounding rectangle for biggest contour
        }
    }

    cv::Scalar color(255, 255, 255);
    drawContours(dst, contours, largest_contour_index, color, CV_FILLED, 8,
                 hierarchy); // Draw the largest contour using previously stored index.
    rectangle(src, bounding_rect, cv::Scalar(0, 255, 0), 1, 8, 0);
    imshow("src", src);
    imshow("largest Contour", dst);
}