#include "yolov5.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [imagepath]\n", argv[0]);
        return -1;
    }

    const char* imagepath = argv[1];

    struct timespec begin, end;
    long time;
    clock_gettime(CLOCK_MONOTONIC, &begin);

    cv::Mat m = cv::imread(imagepath, 1);
    if (m.empty())
    {
        fprintf(stderr, "cv::imread %s failed\n", imagepath);
        return -1;
    }

    std::vector<Object> objects;
    detect_yolov5(m, objects);

    clock_gettime(CLOCK_MONOTONIC, &end);
    time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
    printf(">> Time : %lf ms\n", (double)time/1000000);

    draw_objects(m, objects);

    cv::Mat img(1920, 1080, CV_8UC3);
    cv::resize(m, img, img.size()); 
    cv::imshow("image", m);
    cv::waitKey(0);

    return 0;
}
