cmake_minimum_required(VERSION 3.9)
project(newClient)

set(CMAKE_CXX_STANDARD 11)

add_executable(newClient main.cpp Md5.cpp Receive.cpp Output.cpp Md5.h SHA1.cpp SHA1.h)