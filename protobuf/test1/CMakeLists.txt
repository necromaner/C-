cmake_minimum_required(VERSION 3.14)
project(test1)

set(CMAKE_CXX_STANDARD 14)

#寻找Protobuf库文件
find_package(Protobuf REQUIRED)


include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#通过student.proto文件分别
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS game.proto)

add_executable(test1 main.cpp ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(test1 ${PROTOBUF_LIBRARIES})