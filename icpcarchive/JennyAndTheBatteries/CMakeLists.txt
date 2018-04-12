cmake_minimum_required(VERSION 3.5)
project(JennyAndTheBatteries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(JennyAndTheBatteries ${SOURCE_FILES})