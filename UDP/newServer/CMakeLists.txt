cmake_minimum_required(VERSION 3.9)
project(newServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(newServer main.cpp send/Send.cpp output/Output.cpp md5/md5.cpp)