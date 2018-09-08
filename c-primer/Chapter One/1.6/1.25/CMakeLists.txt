cmake_minimum_required(VERSION 3.6)
project(1_25)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Sales_item.h)
add_executable(1_25 ${SOURCE_FILES} Sales_item.h)