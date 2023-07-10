cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

project(Praktikum3)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        Iterator.h 
        komponente.cpp komponente.h 
        bohrung.cpp bohrung.h 
        fraesung.cpp fraesung.h 
        deList.h deList_impl.h 
        IKomponente.cpp IKomponente.h 
        TElement.h 
        Werkstueck.cpp Werkstueck.h
        Serializer.h Serializer.cpp
)

add_executable(prak P03Main.cpp ${PROJECT_SOURCES})
target_link_libraries(prak PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

add_subdirectory(test)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(v3test v3test_main.cpp v3test.h ${PROJECT_SOURCES})
add_test(NAME v3test COMMAND v3test)

target_link_libraries(v3test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(v3test PRIVATE gtest gtest_main)