//
// Created by deb on 04.05.22.
//

#include "bohrung.h"

Bohrung::Bohrung(double x_, double y_, double diam) : Komponente{x_, y_}, diameter{diam > 0 ? diam : 6.0} {}

double Bohrung::getDiameter() const {
    return diameter;
}

void Bohrung::output(std::ostream &os) const {
    os << "Bohrung: ";
    Komponente::output(os);
    os << ", Durchmesser: " << getDiameter();
}


