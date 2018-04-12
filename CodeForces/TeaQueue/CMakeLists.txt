cmake_minimum_required(VERSION 3.5)
project(TeaQueue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(TeaQueue ${SOURCE_FILES})