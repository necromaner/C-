cmake_minimum_required(VERSION 3.12)
project(client)

set(CMAKE_CXX_STANDARD 14)

add_executable(client main.cpp Receive.cpp Output.cpp Output.h md5.cpp md5.h)