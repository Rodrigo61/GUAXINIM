cmake_minimum_required(VERSION 3.5)
project(4810)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(4810 ${SOURCE_FILES})