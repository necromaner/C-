cmake_minimum_required(VERSION 3.6)
project(3_34)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(3_34 ${SOURCE_FILES})