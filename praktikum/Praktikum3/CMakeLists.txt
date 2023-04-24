cmake_minimum_required(VERSION 3.22)

project(Praktikum)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
#qt6_standard_project_setup()

add_executable(
        Praktikum
        P03Main.cpp
        Iterator.h
        komponente.cpp komponente.h
        bohrung.cpp bohrung.h
        fraesung.cpp fraesung.h
        deList.h
        IKomponente.cpp IKomponente.h
        TElement.h
        Werkstueck.cpp Werkstueck.h
        Serializer.cpp Serializer.h
)

target_link_libraries(Praktikum PRIVATE Qt6::Core)

add_subdirectory(googletest)
set(gtest_SOURCE_DIR, /home/yannic/code/uni/vpp/praktikum/googletest/googletest)
set(gmock_SOURCE_DIR, /home/yannic/code/uni/vpp/praktikum/googletest/googlemock)
set(gtest_lib, /home/yannic/code/uni/vpp/praktikum/googletest/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(PraktikumGoogleTest p02TestMain.cpp komponente.cpp komponente.h bohrung.cpp bohrung.h fraesung.cpp fraesung.h deList.cpp deList.h)
target_link_libraries(PraktikumGoogleTest ${gtest_lib}/gtest ${gtest_lib}/gtest_main Qt6::Core)
