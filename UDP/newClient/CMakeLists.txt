cmake_minimum_required(VERSION 3.9)
project(newClient)

set(CMAKE_CXX_STANDARD 11)

add_executable(newClient main.cpp receive/Receive.cpp output/Output.cpp md5/md5.cpp md5/md5.h output/Output.h)