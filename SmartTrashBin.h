#ifndef SMARTTRASHBIN_H
#define SMARTTRASHBIN_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <opencv2/opencv.hpp>
#include "capthread.h"
#include "PCA9685.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SmartTrashBin; }
QT_END_NAMESPACE

class SmartTrashBin : public QMainWindow
{
    Q_OBJECT

public:
    SmartTrashBin(QWidget *parent = nullptr);
    ~SmartTrashBin();
    void openCamera();
    void closeCamera();

private:
    Ui::SmartTrashBin *ui;
    static QLabel *displayLabel;
    static QLabel *resultLabel;
    QPushButton *detectBtn;

    capThread *thread;
    static cv::Mat showImg;
    static cv::Mat resultImg;
    PiPCA9685::PCA9685 pca;
    static void showResult();
    static void getImage(const cv::Mat& image);    //显示图像的槽函数
    void sleep(int msec);

private slots:
    void pushButton_clicked();
};
#endif // SMARTTRASHBIN_H
