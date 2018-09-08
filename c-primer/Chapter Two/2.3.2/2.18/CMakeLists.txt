cmake_minimum_required(VERSION 3.6)
project(2_18)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(2_18 ${SOURCE_FILES})