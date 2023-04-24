//
// Created by deb on 04.05.22.
//

#include <cmath>
#include "fraesung.h"

Fraesung::Fraesung(double x, double y, double diam, double l, double a) :
        Bohrung{x, y, diam},
        length{l >= 0 ? l : 0},
        angle{a}
    {}

double Fraesung::getEndX() const {
    return getX() + (cos(getAngle()) * getLength());
}

double Fraesung::getEndY() const {
    return getY() + (sin(getAngle()) * getLength());
}

void Fraesung::output(std::ostream &os) const {
    os << "Fraesung mit Start: ";
    Komponente::output(os);
    os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << "), Durchmesser: " << getDiameter();
}

double Fraesung::calcTotalPath() const {
    return 2 * length;
}

QJsonObject Fraesung::toJson() const {
    QJsonObject jsonObject;
    jsonObject["angle"] = getAngle();
    jsonObject["diameter"] = getDiameter();
    jsonObject["hasParent"] = getParent() != nullptr;
    jsonObject["length"] = getLength();
    jsonObject["type"] = "Fraesung";
    jsonObject["x"] = getX();
    jsonObject["y"] = getY();

    return jsonObject;
}

