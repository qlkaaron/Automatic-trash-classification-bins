#include "SmartTrashBin.h"
#include "./ui_SmartTrashBin.h"
#include <QDebug>
#include "yolov5.h"
#include <QTime>

QLabel* SmartTrashBin::displayLabel;
QLabel* SmartTrashBin::resultLabel;
cv::Mat SmartTrashBin::showImg;
cv::Mat SmartTrashBin::resultImg;

SmartTrashBin::SmartTrashBin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmartTrashBin)
{
    ui->setupUi(this);
    //不是QT的类型要注册信号
    qRegisterMetaType<cv::Mat>("cv::Mat");

    detectBtn = new QPushButton("detect", this);
    displayLabel = new QLabel(this);
    resultLabel = new QLabel(this);

    this->resize(QSize(1340, 580));
    detectBtn->setGeometry(300, 530, 89, 25);
    displayLabel->setGeometry(20, 20, 640, 480);
    resultLabel->setGeometry(670, 20, 640, 480);

    connect(detectBtn, SIGNAL(clicked()), this, SLOT(pushButton_clicked()));
    openCamera();
}

SmartTrashBin::~SmartTrashBin()
{
    delete ui;
    closeCamera();
}

void SmartTrashBin::openCamera()
{
    thread = new capThread();
    //connect(thread, SIGNAL(senImage(const cv::Mat&)), this, SLOT(getImage(cv::Mat)));
    thread->setCallbackFunc(getImage);
    thread->start();
}

void SmartTrashBin::closeCamera()
{
    if (thread->isRunning()) {
        thread->stop();
        thread->destroyed();
    }
    displayLabel->close();
    resultLabel->close();
}

void SmartTrashBin::getImage(const cv::Mat& image)
{
    //std::cout << "success get image" << endl;
    //showImg = image.clone();
    showImg = image;
    // cvMat2qImage
    QImage qImg(showImg.data, showImg.cols, showImg.rows, static_cast<int>(showImg.step), QImage::Format_RGB888);
    qImg = qImg.rgbSwapped();
    QPixmap imgPixmap = QPixmap::fromImage(qImg);
    // 图片缩放
    imgPixmap = imgPixmap.scaled(displayLabel->width(), displayLabel->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    displayLabel->setPixmap(imgPixmap);
}

void SmartTrashBin::pushButton_clicked()
{
    bool success = imwrite("./save_image.jpg", showImg); // 将图像保存到桌面上
    if (!success) {
        qDebug("Failed to save image.");
        return ;
    }
    qDebug("Image saved to desktop.");

    //cv::Mat m = cv::imread("/home/enterprise/workspace/qt_trash/yolov5/image.jpg");
    //cv::Mat m = showImg.clone();
    cv::Mat m = showImg;
    std::vector<Object> objects;
    detect_yolov5(m, objects);
    draw_objects(m, objects);
    resultImg = m.clone();
    showResult();
    for(auto objs : objects) {
        if(objs.label == 0) {
            pca.set_pwm_ms(0, 1.5);
            sleep(4000);
            pca.set_pwm_ms(0, 0.5);
        } else if(objs.label == 1) {
            pca.set_pwm_ms(1, 1.5);
            sleep(4000);
            pca.set_pwm_ms(1, 0.5);
        } else if(objs.label == 2) {
            pca.set_pwm_ms(2, 1.5);
            sleep(4000);
            pca.set_pwm_ms(2, 0.5);
        } else if(objs.label == 3) {
            pca.set_pwm_ms(3, 1.5);
            sleep(4000);
            pca.set_pwm_ms(3, 0.5);
        }
    }


    return ;
}

void SmartTrashBin::showResult()
{
    //QImage img = cvMat2QImage(resultImg);
    // cvMat2qImage
    QImage qImg(resultImg.data, resultImg.cols, resultImg.rows, static_cast<int>(resultImg.step), QImage::Format_RGB888);
    qImg = qImg.rgbSwapped();
    QPixmap imgPixmap = QPixmap::fromImage(qImg);
    // 图片缩放
    imgPixmap = imgPixmap.scaled(resultLabel->width(), resultLabel->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    resultLabel->setPixmap(imgPixmap);
}

void SmartTrashBin::sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
