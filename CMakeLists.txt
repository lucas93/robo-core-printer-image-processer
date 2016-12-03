cmake_minimum_required(VERSION 3.6)
project(RoboCorePrinterImageConverter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")



set(SOURCE_FILES main.cpp Converter.h EasyBMP/EasyBMP.cpp EasyBMP/EasyBMP.h EasyBMP/EasyBMP_DataStructures.h EasyBMP/EasyBMP_VariousBMPutilities.h
BitmapBoolImage.h Row.h Line.h ConvertedImage.h)


add_executable(RoboCorePrinterImageConverter ${SOURCE_FILES})
