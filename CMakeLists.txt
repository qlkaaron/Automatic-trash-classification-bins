cmake_minimum_required(VERSION 3.1)
project(pca9685)

set(CMAKE_CXX_STANDARD 14)

add_executable(pca9685 main.cpp PCA9685.cpp I2CPeripheral.cpp i2c)
