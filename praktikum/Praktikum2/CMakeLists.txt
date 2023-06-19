cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)


project(Praktikum2)
add_executable(Praktikum2 P02Main.cpp Iterator.cpp Iterator.h komponente.cpp komponente.h bohrung.cpp bohrung.h fraesung.cpp fraesung.h deList.cpp deList.h IKomponente.cpp IKomponente.h IKomponentenElement.h Werkstueck.cpp Werkstueck.h)


add_subdirectory(test)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(Praktikum2GoogleTest p02TestMain.cpp Iterator.cpp Iterator.h komponente.cpp komponente.h bohrung.cpp bohrung.h fraesung.cpp fraesung.h deList.cpp deList.h IKomponente.cpp IKomponente.h IKomponentenElement.h Werkstueck.cpp Werkstueck.h)
target_link_libraries(Praktikum2GoogleTest gtest gtest_main)
