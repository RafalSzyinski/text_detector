#include "opencv2/opencv.hpp"
#include "opencv2/objdetect.hpp"
#include "FaceDetectorDNN.h"

int main(int argc, char **argv)
{
    cv::VideoCapture video_capture;
    if (!video_capture.open(0))
        return 0;

    FaceDetectorDNN fDetector;
    cv::CascadeClassifier fd;
    if(!fd.load(FACE_DETECION_HAARCASCADE))
    {
        std::cout << "Dupa";
        return -1;
    }
    cv::Mat frame;
    while (true)
    {
        video_capture >> frame;

        std::vector<cv::Rect> faces;
        fd.detectMultiScale(frame, faces, 1.5, 3,  cv::CASCADE_SCALE_IMAGE);

        for (auto& i : faces)
            cv::rectangle(frame, i, cv::Scalar(255, 0, 0), 2, 8, 0);

        //fDetector.show(frame);

        cv::imshow("Face", frame);
        if (cv::waitKey(10) == 27)
            break;

        try { //cv::getWindowImageRect(fDetector.getLabel());
            cv::getWindowImageRect("Face");}
        catch (...) { break; }
    }

    cv::destroyAllWindows();
    video_capture.release();
    return 0;
}