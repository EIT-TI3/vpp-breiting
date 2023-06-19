#include <iostream>
#include <cmath>

#include "fraesung.h"
#include "komponentenList.h"


int main() {
    Bohrung b1(1, 2, 8);
    Bohrung b2(2, 6, 4);
    Bohrung b3(10, 8, 7);
    Bohrung b4(7, 2, 5);

    Fraesung f1(2, 3, 5, M_SQRT2 * 2, 0.25 * M_PI);
    Fraesung f2(6, 7, 6, 3, 0);
    Fraesung f3(17, 6, 4, M_SQRT2 * 4, 1.25 * M_PI);

    // std::cout << f3.getX() << std::endl;
    // std::cout << f3.getY() << std::endl;

    KomponentenList kl{};
    kl.push_back(&b1);
    kl.push_back(&f1);
    kl.push_back(&b3);
    kl.push_back(&f2);
    kl.push_back(&b4);
    kl.push_back(&f3);
    kl.push_back(&b2);

    std::cout << "Ausgabe der Liste" << std::endl;

    for(int i = 0; i < kl.size(); i++) {
        std::cout << *kl.at(i) << std::endl;
    }
    return 0;
}
