#include "capthread.h"
#include <iostream>
using namespace std;

capThread::capThread()
{
    stopped = false;
}

void capThread::run()
{
    cap = new VideoCapture;
    cap->open(0);
    if (!cap->isOpened()) {
        cout << "Failed to open camera." << endl;
        return ;
    }

    while(!stopped){
        *cap >> frame;
        if (frame.empty()) {
            cout << "Failed to capture image." << endl;
            continue ;
        }
        //cout << "success to capture image" << endl;
        //emit senImage(frame);
        m_callbackFUnc(frame);
    }

}

void capThread::setCallbackFunc(void (*func)(const cv::Mat&))
{
    m_callbackFUnc = func;
}

void capThread::stop()
{
    stopped = true;
}
