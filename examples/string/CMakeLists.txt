cmake_minimum_required(VERSION 3.22.1)
project(vpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp strarray.cpp strarray.h)
add_library(strarray SHARED strarray.cpp strarray.h)
