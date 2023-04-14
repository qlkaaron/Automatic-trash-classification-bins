cmake_minimum_required(VERSION 3.5)
project(capture_image)

find_package(OpenCV REQUIRED)

add_executable(capture_image main.cpp)
target_link_libraries(capture_image ${OpenCV_LIBS})
