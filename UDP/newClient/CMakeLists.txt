cmake_minimum_required(VERSION 3.12)
project(newClient)

set(CMAKE_CXX_STANDARD 14)

add_executable(newClient main.cpp receive/Receive.cpp output/Output.cpp)