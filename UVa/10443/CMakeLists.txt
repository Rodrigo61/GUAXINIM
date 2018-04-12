cmake_minimum_required(VERSION 3.5)
project(10443)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(10443 ${SOURCE_FILES})