cmake_minimum_required(VERSION 3.13)
project(MD5_ADD)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/gtest-1.7.0/include/)

add_subdirectory(./gtest-1.7.0)

set(3RD_LIBS gtest pthread)

add_executable(${PROJECT_NAME} main.cpp  Test/Test.cpp MD5_add/MD5_add.cpp md5/md5.cpp)

target_link_libraries(${PROJECT_NAME} ${3RD_LIBS})
