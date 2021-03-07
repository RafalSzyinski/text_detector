#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Detektor kol Hougha\nSposob uzycia: " << argv[0] << " <imagename>\n" << std::endl;
        return EXIT_FAILURE;
    }

    cv::Mat src;
    cv::Mat image;

    src = cv::imread(argv[1], 1);
    if (src.empty())
    {
        std::cerr << "Nie udalo sie wczytac " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    cv::cvtColor(src, image, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(image, image, cv::Size(5, 5), 0, 0);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(image, circles, cv::HOUGH_GRADIENT, 4, image.cols / 5);

    for (size_t i = 0; i < circles.size(); ++i)
    {
        cv::circle(src, cv::Point(cvRound(circles[i][0]), cvRound(circles[i][1])), cvRound(circles[i][2]), cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
    }

    cv::imshow("Circles", src);
    cv::waitKey();

    return 0;
}