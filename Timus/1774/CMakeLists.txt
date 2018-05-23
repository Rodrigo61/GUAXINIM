cmake_minimum_required(VERSION 3.5)
project(1774)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(1774 ${SOURCE_FILES})