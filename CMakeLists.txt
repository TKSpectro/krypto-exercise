cmake_minimum_required(VERSION 3.19)
project(krypto_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(krypto_exercise main.cpp src/series1.cpp src/series1.h src/series2.cpp src/series2.h src/series3.cpp src/series3.h src/series4/des.cpp src/series4/des.h src/series4/des_data.h)