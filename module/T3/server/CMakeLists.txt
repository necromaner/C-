cmake_minimum_required(VERSION 3.12)
project(server)

set(CMAKE_CXX_STANDARD 14)

add_executable(server main.cpp send/Send.cpp output/Output.cpp md5/md5.cpp udp/Udp.cpp)