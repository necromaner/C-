cmake_minimum_required(VERSION 3.13)
project(module)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/gtest-1.7.0/include/)

add_subdirectory(./gtest-1.7.0)

set(3RD_LIBS gtest pthread)

add_executable(${PROJECT_NAME} main.cpp  Test/Test.cpp M1/M1.cpp)

target_link_libraries(${PROJECT_NAME} ${3RD_LIBS})
