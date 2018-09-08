cmake_minimum_required(VERSION 3.7)
project(6_10)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Chapter6.h exchange.cc)
add_executable(6_10 ${SOURCE_FILES} CHAPTER6.h)