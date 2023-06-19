#include <cmath>
#include "komponente.h"

Komponente::Komponente(double xPos, double yPos) : x{xPos}, y{yPos} {}

double Komponente::getXAbsolute() const
{
    auto res = getX();
    if (getParent() != nullptr)
        res += getParent()->getXAbsolute();
    return res;
}

double Komponente::getYAbsolute() const
{
    auto res = getY();
    if (getParent() != nullptr)
        res += getParent()->getYAbsolute();
    return res;
}

double Komponente::distance(IKomponente const *k) const
{
    if (k == nullptr)
        return 0.0;
    return sqrt(pow(this->getXAbsolute() - k->getXAbsolute(), 2) + 
                pow(this->getYAbsolute() - k->getYAbsolute(), 2));
}

IKomponente const *Komponente::getParent() const
{
    return parent;
}

void Komponente::setParent(IKomponente const *p)
{
    parent = p;
}

void Komponente::output(std::ostream &os) const
{
    os << "(" << getX() << ", " << getY() << ")";
}