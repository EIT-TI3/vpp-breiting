cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)


project(Praktikum1)
add_executable(Praktikum1 P01Main.cpp komponente.cpp komponente.h bohrung.cpp bohrung.h fraesung.cpp fraesung.h komponentenList.cpp komponentenList.h)


add_subdirectory(test)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(Praktikum1GoogleTest p01TestMain.cpp komponente.cpp komponente.h bohrung.cpp bohrung.h fraesung.cpp fraesung.h komponentenList.cpp komponentenList.h)
target_link_libraries(Praktikum1GoogleTest gtest gtest_main)
