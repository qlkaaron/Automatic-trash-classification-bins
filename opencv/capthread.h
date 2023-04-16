#ifndef CAPTHREAD_H
#define CAPTHREAD_H

#include <QThread>
#include <opencv2/opencv.hpp>
using namespace cv;

class capThread : public QThread
{
    Q_OBJECT
public:
    capThread();
    void stop();
    void setCallbackFunc(void(*func) (const cv::Mat&));

protected:
    void run();

private:
    VideoCapture *cap;     
    Mat frame;
    volatile bool stopped;
    void (*m_callbackFUnc)(const cv::Mat&);

//signals:
//    void senImage(const cv::Mat&);
};

#endif // CAPTHREAD_H
