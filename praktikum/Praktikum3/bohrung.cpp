#include "bohrung.h"

Bohrung::Bohrung(double x_, double y_, double diam) : Komponente{x_, y_}, diameter{diam > 0 ? diam : 6.0 } {}

void Bohrung::output(std::ostream &os) const {
    os << "Bohrung: ";
    Komponente::output(os);
    os << ", Durchmesser: " << diameter;
}