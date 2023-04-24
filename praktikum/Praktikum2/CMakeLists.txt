cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)


project(Praktikum)
add_executable(Praktikum P02Main.cpp Iterator.cpp Iterator.h komponente.cpp komponente.h bohrung.cpp bohrung.h fraesung.cpp fraesung.h deList.cpp deList.h IKomponente.cpp IKomponente.h IKomponentenElement.h Werkstueck.cpp Werkstueck.h)


add_subdirectory(googletest)
set(gtest_SOURCE_DIR, /home/yannic/code/uni/vpp/praktikum/googletest/googletest)
set(gmock_SOURCE_DIR, /home/yannic/code/uni/vpp/praktikum/googletest/googlemock)
set(gtest_lib, /home/yannic/code/uni/vpp/praktikum/googletest/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(PraktikumGoogleTest p02TestMain.cpp komponente.cpp komponente.h bohrung.cpp bohrung.h fraesung.cpp fraesung.h deList.cpp deList.h)
target_link_libraries(PraktikumGoogleTest ${gtest_lib}/gtest ${gtest_lib}/gtest_main)
