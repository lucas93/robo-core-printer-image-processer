cmake_minimum_required(VERSION 3.6)
project(RoboCorePrinterImageConverter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp ImageProcesser.h bitmap_image.hpp)
add_executable(RoboCorePrinterImageConverter ${SOURCE_FILES})