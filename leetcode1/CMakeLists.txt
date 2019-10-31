cmake_minimum_required(VERSION 3.14)
project(leetcode1)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/gtest-1.7.0/include/)

add_subdirectory(./gtest-1.7.0)

set(3RD_LIBS gtest pthread)

add_executable(${PROJECT_NAME}  main.cpp
        test/Test.cpp
        test/Test_1_50.cpp
        test/Test_51_100.cpp
        test/Test_101_150.cpp
        test/Test_151_200.cpp
        test/Test_201_250.cpp
        test/Test_251_300.cpp
        test/Test_301_350.cpp
        test/Test_351_400.cpp
        test/Test_401_450.cpp
        test/Test_451_500.cpp
        leetcode/Leetcode.cpp
        leetcode/Leetcode_1_50.cpp
#        leetcode/Leetcode_51_100.cpp
#        leetcode/Leetcode_101_150.cpp
#        leetcode/Leetcode_151_200.cpp
#        leetcode/Leetcode_201_250.cpp
#        leetcode/Leetcode_251_300.cpp
#        leetcode/Leetcode_301_350.cpp
#        leetcode/Leetcode_351_400.cpp
#        leetcode/Leetcode_401_450.cpp
#        leetcode/Leetcode_451_500.cpp
        )

target_link_libraries(${PROJECT_NAME} ${3RD_LIBS})


