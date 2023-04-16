cmake_minimum_required(VERSION 3.5)

project(SmartTrashBin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


#set(ENV{PKG_CONFIG_PATH} /usr/local/lib/pkgconfig)
#FIND_PACKAGE(PkgConfig REQUIRED)
#PKG_SEARCH_MODULE(PKG_OPENCV REQUIRED opencv)
#INCLUDE_DIRECTORIES(${PKG_OPENCV_INCLUDE_DIRS})
find_package(OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})


set(NCNN_LIBS /home/pi/ncnn-master/build/install/lib/libncnn.a)
set(NCNN_INCLUDE_DIRS /home/pi/ncnn-master/build/install/include/ncnn)
include_directories(${NCNN_INCLUDE_DIRS})

find_package(OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories(./opencv/ ./yolov5/ ./motor/)

set(PROJECT_SOURCES
        main.cpp
        SmartTrashBin.cpp
        SmartTrashBin.h
        SmartTrashBin.ui

        opencv/capthread.cpp
        opencv/capthread.h

        yolov5/yolov5.cpp
        yolov5/yolov5.h

        motor/Constants.h
        motor/I2CPeripheral.cpp
        motor/I2CPeripheral.h
        motor/PCA9685.cpp
        motor/PCA9685.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartTrashBin
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SmartTrashBin APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SmartTrashBin SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SmartTrashBin
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SmartTrashBin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OpenCV_LIBS} ${NCNN_LIBS} -li2c)

set_target_properties(SmartTrashBin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS SmartTrashBin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartTrashBin)
endif()

# unit test
add_executable(unit_test
    unit_tests/unit_test.cpp

    yolov5/yolov5.cpp
    yolov5/yolov5.h

    motor/Constants.h
    motor/I2CPeripheral.cpp
    motor/I2CPeripheral.h
    motor/PCA9685.cpp
    motor/PCA9685.h
)
target_link_libraries(unit_test -lgtest ${OpenCV_LIBS} ${NCNN_LIBS} -li2c)

