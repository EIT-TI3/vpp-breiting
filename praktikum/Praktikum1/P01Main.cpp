#include <iostream>
#include "fraesung.h"
#include "komponentenList.h"
#include <cmath>

int main() {
    Bohrung b1{1, 2, 8};
    Bohrung b2{2, 6, 4};
    Bohrung b3{10, 8, 7};
    Bohrung b4{7, 2, 5};

    Fraesung f1{2, 3, 5, M_SQRT2 * 2, 0.25 * M_PI};
    Fraesung f2{6, 7, 6, 3, 0};
    Fraesung f3{17, 6, 4, M_SQRT2 * 4, 1.25 * M_PI};

    KomponentenList komponentenList{};
    komponentenList.push_back(&b1);
    komponentenList.push_back(&f1);
    komponentenList.push_back(&b3);
    komponentenList.push_back(&f2);
    komponentenList.push_back(&b4);
    komponentenList.push_back(&f3);
    komponentenList.push_back(&b2);

    std::cout << "Ausgabe der Liste" << std::endl;

    for(int i = 0; i < komponentenList.size(); i++) {
        std::cout << *komponentenList.at(i) << std::endl;
    }
    return 0;
}
