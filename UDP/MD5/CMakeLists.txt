cmake_minimum_required(VERSION 3.12)
project(MD5)

set(CMAKE_CXX_STANDARD 11)

add_executable(MD5 main.cpp Md5.cpp Md5.h SHA1.cpp SHA1.h)