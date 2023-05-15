project(LeetCodeAnswers)

cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(Q00011 src/Q0001/examples.cpp src/Q0001/solution1.cpp)
add_executable(Q00012 src/Q0001/examples.cpp src/Q0001/solution2.cpp)
