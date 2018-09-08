cmake_minimum_required(VERSION 3.6)
project(4_19)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(4_19 ${SOURCE_FILES})