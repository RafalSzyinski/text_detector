//
// Created by rafal on 30.04.2021.
//

#include "FaceDetectorDNN.h"

FaceDetectorDNN::FaceDetectorDNN() : threshold(0.5), height(300), width(300), scale(1.0), mean_value(104., 177.0, 123.0)
{
    network = cv::dnn::readNetFromCaffe(FACE_DETECTION_CONFIGURATION, FACE_DETECTION_WEIGHTS);

    if (network.empty())
        throw std::invalid_argument("Cannot create network");
}

std::vector<cv::Rect> FaceDetectorDNN::detectFace(const cv::Mat& frame)
{
    cv::Mat blob = cv::dnn::blobFromImage(frame, scale, cv::Size(width, height), mean_value, false, false);
    network.setInput(blob, "data");
    cv::Mat detection = network.forward("detection_out");
    cv::Mat detection_matrix(detection.size[2],detection.size[3], CV_32F,detection.ptr<float>());
    std::vector<cv::Rect> faces;

    for (int i = 0; i < detection_matrix.rows; i++) {
        float confidence = detection_matrix.at<float>(i, 2);

        if (confidence < threshold) {
            continue;
        }
        int x_left_bottom = static_cast<int>(
                detection_matrix.at<float>(i, 3) * frame.cols);

        int y_left_bottom = static_cast<int>(
                detection_matrix.at<float>(i, 4) * frame.rows);

        int x_right_top = static_cast<int>(
                detection_matrix.at<float>(i, 5) * frame.cols);

        int y_right_top = static_cast<int>(
                detection_matrix.at<float>(i, 6) * frame.rows);

        faces.emplace_back(x_left_bottom,
                           y_left_bottom,
                           (x_right_top - x_left_bottom),
                           (y_right_top - y_left_bottom));
    }

    return faces;
}

