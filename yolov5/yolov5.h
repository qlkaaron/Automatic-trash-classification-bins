#ifndef YOLOV5_H
#define YOLOV5_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

struct Object
{
    cv::Rect_<float> rect;
    int label;
    float prob;
};

int detect_yolov5(const cv::Mat& bgr, std::vector<Object>& objects);
void draw_objects(cv::Mat& image, const std::vector<Object>& objects);

#endif // YOLOV5_H
