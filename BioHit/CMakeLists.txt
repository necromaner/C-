cmake_minimum_required(VERSION 3.12)
project(BioHit)

set(CMAKE_CXX_STANDARD 14)

add_executable(BioHit main.cpp commentMove/position.cpp add/add.cpp add/add.h)