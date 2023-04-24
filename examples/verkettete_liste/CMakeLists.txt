cmake_minimum_required(VERSION 3.22.1)
project(vpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp textliste.cpp textliste.h)
add_library(textliste SHARED textliste.cpp textliste.h)
