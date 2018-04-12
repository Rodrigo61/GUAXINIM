cmake_minimum_required(VERSION 3.5)
project(10420)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(10420 ${SOURCE_FILES})