cmake_minimum_required(VERSION 3.5)
project(yolov5)

find_package(OpenCV REQUIRED)

# 分别设置ncnn的链接库和头文件
set(NCNN_LIBS /home/enterprise/github/ncnn/build/install/lib/libncnn.a)
set(NCNN_INCLUDE_DIRS /home/enterprise/github/ncnn/build/install/include/ncnn)
include_directories(${NCNN_INCLUDE_DIRS})

# 配置OpenMP
find_package(OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(yolov5 main.cpp yolov5.cpp)
target_link_libraries(yolov5 ${OpenCV_LIBS} ${NCNN_LIBS})
