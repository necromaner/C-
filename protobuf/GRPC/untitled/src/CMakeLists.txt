cmake_minimum_required(VERSION 3.14)

ADD_EXECUTABLE(main main.cpp)

INCLUDE_DIRECTORIES(/usr/local/include/hello)

TARGET_LINK_LIBRARIES(main hello)

