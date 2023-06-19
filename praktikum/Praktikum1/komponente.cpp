#include "komponente.h"

Komponente::Komponente(double xPos, double yPos) : x{xPos}, y{yPos} {}

void Komponente::output(std::ostream &os) const {
    os << "(" << getX() << ", " << getY() << ")";
}

double Komponente::getX() const {
    return x;
}

double Komponente::getY() const {
    return y;
}
