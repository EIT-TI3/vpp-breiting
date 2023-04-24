//
// Created by deb on 04.05.22.
//

#include "komponente.h"
#include <cmath>

Komponente::Komponente(double xPos, double yPos) : x{xPos}, y{yPos}, parent{nullptr} {}

void Komponente::output(std::ostream &os) const {
    os << "(" << getX() << ", " << getY() << ")";
}

IKomponente const *Komponente::getParent() const {
    return parent;
}

void Komponente::setParent(const IKomponente *p) {
    parent = p;
}

double Komponente::calcTotalPath() const {
    return 0;
}

double Komponente::getXAbsolute() const {
    double XAbsolute = getX();

    if(parent != nullptr) {
        XAbsolute += parent->getXAbsolute();
    }
    return XAbsolute;
}

double Komponente::getYAbsolute() const {
    double YAbsolute = getY();

    if(parent != nullptr) {
        YAbsolute += parent->getYAbsolute();
    }
    return YAbsolute;
}

double Komponente::distance(const IKomponente *k) const {
    return sqrt(
            pow(getXAbsolute() - k->getXAbsolute(), 2)
            +
            pow(getYAbsolute() - k->getYAbsolute(), 2)
    );
}
