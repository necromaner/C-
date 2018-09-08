cmake_minimum_required(VERSION 3.7)
project(6_9)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES factMain.cc Chapter6.h fact.cc)
add_executable(6_9 ${SOURCE_FILES} Chapter6.h)