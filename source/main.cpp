#include "opencv2/opencv.hpp"
#include "FaceDetectorDNN.h"


int main(int argc, char **argv)
{
    cv::VideoCapture video_capture;
    if (!video_capture.open(0))
        return 0;

    FaceDetectorDNN face_detector;
    cv::namedWindow("FaceDetectorDNN", cv::WINDOW_AUTOSIZE);
    cv::Mat frame;
    while (true)
    {
        video_capture >> frame;

        auto rectangles = face_detector.detectFace(frame);
        cv::Scalar color(0x54, 0xA2, 0xD2);
        int frame_thickness = 4;
        for (const auto& r : rectangles)
        {
            cv::rectangle(frame, r, color, frame_thickness);
            std::string sizeText = std::to_string(r.size().width) + "x" + std::to_string(r.size().height);
            cv::putText(frame, sizeText, r.br(), cv::FONT_HERSHEY_SIMPLEX, 0.5, color);

            std::string label = "DNN Face Detector";
            cv::Point labelPosition = r.tl();
            labelPosition.y -= 3;
            cv::putText(frame, label, labelPosition, cv::FONT_HERSHEY_SIMPLEX, 0.5, color);
        }
        imshow("FaceDetectorDNN", frame);

        if (cv::waitKey(10) == 27)
            break;

        try { cv::getWindowImageRect("FaceDetectorDNN"); }
        catch (...) { break; }
    }

    cv::destroyAllWindows();
    video_capture.release();

    return 0;
}