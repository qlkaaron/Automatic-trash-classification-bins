#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Failed to open camera." << endl;
        return -1;
    }

    Mat frame;
    cap >> frame;
    if (frame.empty()) {
        cout << "Failed to capture image." << endl;
        return -1;
    }

    bool success = imwrite("./save.jpg", frame); // 将图像保存到桌面上
    if (!success) {
        cout << "Failed to save image." << endl;
        return -1;
    }

    cout << "Image saved to desktop." << endl;
    return 0;
}
