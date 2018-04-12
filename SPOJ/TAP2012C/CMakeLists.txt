cmake_minimum_required(VERSION 3.5)
project(TAP2012C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(TAP2012C ${SOURCE_FILES})