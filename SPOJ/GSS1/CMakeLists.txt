cmake_minimum_required(VERSION 3.5)
project(GSS1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(GSS1 ${SOURCE_FILES})