cmake_minimum_required(VERSION 3.7)
project(6_12)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Chapter6.h exchange.cc)
add_executable(6_12 ${SOURCE_FILES} exchange.cc)