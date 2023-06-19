#include <cmath>
#include "fraesung.h"

Fraesung::Fraesung(double x, double y, double diam, double l, double a) :
    Bohrung{x, y, diam}, length(l >= 0.0 ? l : 0.0 ), angle{a} {}

double Fraesung::calcTotalPath() const {
    return 2*length;
}

double Fraesung::getLength() const {
    return length;
}

double Fraesung::getAngle() const {
    return angle;
}

double Fraesung::getEndX() const {
    return this->getX() + (length * cos(angle));
}

double Fraesung::getEndY() const {
    return this->getY() + (length * sin(angle));
}

void Fraesung::output(std::ostream &os) const {
    os << "Fraesung mit Start: ";
    Komponente::output(os);
    os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << "), Durchmesser: " << getDiameter();
}
