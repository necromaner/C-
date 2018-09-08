cmake_minimum_required(VERSION 3.7)
project(6_14)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp exchange.cc Chapter6.h)
add_executable(6_14 ${SOURCE_FILES} exchange.cc Chapter6.h)