cmake_minimum_required(VERSION 3.9)
project(newServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(newServer main.cpp Md5.cpp Send.cpp Output.cpp)