#include "Werkstueck.h"

Werkstueck::Werkstueck(double xPos, double yPos, double h, double w) : Komponente(xPos, yPos), height{h}, width{w}, pathIsOptimized{false}
{
}

void Werkstueck::add(IKomponente *k)
{
    if (k == nullptr)
        return;
    if (k->getParent() != nullptr)
        return;
    k->setParent(this);
    komponenten.push_back(k);
    pathIsOptimized = false;
}

void Werkstueck::remove(IKomponente const *k)
{
    auto it = komponenten.begin();
    while (it != komponenten.end())
    {
        if (*it == k)
        {
            komponenten.erase(it);
            pathIsOptimized = false;
            break;
        }
        ++it;
    }
}

IKomponente const *Werkstueck::getChild(int i) const
{
    auto it = komponenten.begin();
    for (int j = 0; j < i && it != komponenten.end(); j++)
    {
        ++it;
    }
    return it != komponenten.end() ? *it : nullptr ;
}

double Werkstueck::calcTotalPath() const
{
    double path = calcPathLength();
    for (auto k : komponenten)
        path += k->calcTotalPath();
    return path;
}

double Werkstueck::calcPathLength() const
{
    double path = 0.0;
    const IKomponente* last = this;
    for (auto komponente : komponenten)
    {
        path += last->distance(komponente);
        last = komponente;
    }
    path += last->distance(this);
    return path;
}

void Werkstueck::optimizePath()
{
    if (!pathIsOptimized && komponenten.size() > 0)
    {
        auto it = komponenten.begin();
        while (it != komponenten.end())
        {
            Werkstueck *w = dynamic_cast<Werkstueck *>(*it);
            if (w != nullptr)
            {
                w->optimizePath();
            }
            ++it;
        }
        DeList sorted;
        IKomponente *current = this;
        auto nearest = getNearest(current);
        sorted.push_back(*nearest);
        current = *nearest;
        komponenten.erase(nearest);
        while (komponenten.size() > 0)
        {
            nearest = getNearest(current);
            sorted.push_back(*nearest);
            current = *nearest;
            komponenten.erase(nearest);
        }
        komponenten = sorted;
        pathIsOptimized = true;
    }
}

Iterator Werkstueck::getNearest(IKomponente const *pk) const
{
    if (pk == nullptr)
        return Iterator{};
    if (komponenten.size() == 0)
        return Iterator{};

    // Get first element as nearest
    auto it_komponente = komponenten.begin();
    auto nearest_it = Iterator{it_komponente};
    auto nearest_dist = pk->distance(*nearest_it);
    ++it_komponente;

    while (it_komponente != komponenten.end())
    {
        auto distance = pk->distance(*it_komponente);
        if (distance < nearest_dist)
        {
            nearest_dist = distance;
            nearest_it = Iterator{it_komponente};
        }
        ++it_komponente;
    }
    return nearest_it;
}

void Werkstueck::output(std::ostream &os) const
{
    std::string pad;
    const IKomponente *last = getParent();
    while (last != nullptr)
    {
        last = last->getParent();
        pad.append(" ");
    }

    os << pad << "Werkstueck:\n"
       << pad << "Verankerung: (" << getX() << ", " << getY() << ")\n"
       << pad << "height: " << getHeight() << ", width: " << getWidth() << "\n"
       << pad << "Komponenten:" << std::endl;

    for (auto komponente : komponenten)
    {
        if (dynamic_cast<Werkstueck *>(komponente) == nullptr)
        {
            os << pad;
        }
        os << *komponente;
        if (dynamic_cast<Werkstueck *>(komponente) == nullptr)
        {
            os << std::endl;
        }
    }
}