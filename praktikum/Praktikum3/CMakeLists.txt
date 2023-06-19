cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)


project(Praktikum3)
add_executable(Praktikum3 P03Main.cpp 
                Iterator.h 
                komponente.cpp komponente.h 
                bohrung.cpp bohrung.h 
                fraesung.cpp fraesung.h 
                deList.h deList_impl.h 
                IKomponente.cpp IKomponente.h 
                TElement.h 
                Werkstueck.cpp Werkstueck.h)
