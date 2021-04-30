#include "opencv2/opencv.hpp"
#include "FaceDetectorDNN.h"

int main(int argc, char **argv) {

    cv::VideoCapture video_capture;
    if (!video_capture.open(0)) {
        return 0;
    }

    FaceDetectorDNN face_detector;

    cv::Mat frame;
    while (true) {
        video_capture >> frame;

        auto rectangles = face_detector.detectFace(frame);
        cv::Scalar color(255, 0, 0);
        int frame_thickness = 4;
        for(const auto & r : rectangles){
            cv::rectangle(frame, r, color, frame_thickness);
        }
        imshow("Image", frame);
        const int esc_key = 27;
        if (cv::waitKey(10) == esc_key) {
            break;
        }
    }

    cv::destroyAllWindows();
    video_capture.release();

    return 0;
}