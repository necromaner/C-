cmake_minimum_required(VERSION 3.7)
project(6_11)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Chapter6.h reset.cc)
add_executable(6_11 ${SOURCE_FILES} Chapter6.h reset.cc)