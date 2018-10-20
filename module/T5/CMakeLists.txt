cmake_minimum_required(VERSION 3.12)
project(unit_test)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/gtest-1.7.0/include/)

add_subdirectory(./gtest-1.7.0)

set(3RD_LIBS gtest pthread)

add_executable(${PROJECT_NAME} main.cpp OutPut/Output.cpp operator/operator.cpp classDemo/classDemo.cpp inheritance/inheritance.cpp)

target_link_libraries(${PROJECT_NAME} ${3RD_LIBS})