cmake_minimum_required(VERSION 3.22.1)
project("flam_assignment1")

add_library(flam_assignment1 SHARED
        native-lib.cpp)

# OpenCV integration (expects OpenCV_DIR passed from Gradle; .so is in jniLibs)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(flam_assignment1
        ${OpenCV_LIBS}
        android
        log)
