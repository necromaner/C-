cmake_minimum_required(VERSION 3.9)
project(newServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(newServer main.cpp Send.cpp Output.cpp SHA1.cpp SHA1.h)