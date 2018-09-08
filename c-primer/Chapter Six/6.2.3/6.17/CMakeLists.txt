cmake_minimum_required(VERSION 3.7)
project(6_17)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Chapter6.h change.cc inspect.cc)
add_executable(6_17 ${SOURCE_FILES} Chapter6.h change.cc inspect.cc)