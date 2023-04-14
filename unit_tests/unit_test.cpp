#include <gtest/gtest.h>
#include "opencv2/opencv.hpp"
#include "yolov5.h"
#include "PCA9685.h"

#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class motorTest : public ::testing::Test
{

protected:
    virtual void SetUp() {
        std::cout<<"check the motor";

    }

    virtual void TearDown() {

    }
    PiPCA9685::PCA9685 pca;
};

TEST_F(motorTest, SetPWM)
{
    pca.set_pwm_ms(0, 1.5);
    pca.set_pwm_ms(1, 1.5);
    pca.set_pwm_ms(2, 1.5);
    pca.set_pwm_ms(3, 1.5);
    EXPECT_EQ(pca.check_pwm_ms(0, 1.5), 0)<<"motor 0 set pwm 1.5ms failed";
    EXPECT_EQ(pca.check_pwm_ms(1, 1.5), 0)<<"motor 1 set pwm 1.5ms failed";
    EXPECT_EQ(pca.check_pwm_ms(2, 1.5), 0)<<"motor 2 set pwm 1.5ms failed";
    EXPECT_EQ(pca.check_pwm_ms(3, 1.5), 0)<<"motor 3 set pwm 1.5ms failed";
}

class detectionTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        std::cout<<"check the detecting";
    }
    virtual void TearDown(){

    }

    std::vector<Object> objects;
};

TEST_F(detectionTest,waste)
{
    cv::Mat m = cv::imread("/home/pi/Desktop/SmartTrashBin/SmartTrashBin/unit_tests/image.jpg", 1);

    detect_yolov5(m, objects);
    EXPECT_EQ(objects[0].label, 3)<<"other waste detect failed";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
