#include "Werkstueck.h"
#include "deList_impl.h"

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
    if (k == nullptr)
        return;
    auto it = komponenten.begin();
    while (it != komponenten.end())
    {
        if (*it == k)
        {
            (*it)->setParent(nullptr);
            komponenten.erase(it);
            pathIsOptimized = false;
            break;
        }
        ++it;
    }
}

IKomponente const *Werkstueck::getChild(int i) const
{
    if (i < 0)
        return nullptr;
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
    for (const auto& komponente : komponenten)
        path += komponente->calcTotalPath();
    return path;
}

double Werkstueck::calcPathLength() const
{
    double path = 0.0;
    const IKomponente* last = this;
    for (const auto& komponente : komponenten)
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
        DeList<IKomponente*> sorted;
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

Iterator<IKomponente*> Werkstueck::getNearest(IKomponente const *pk) const
{
    if (pk == nullptr || komponenten.size() == 0)
        return Iterator<IKomponente*>{};

    // Get first element as nearest
    auto it_komponente = komponenten.begin();
    auto nearest_it = Iterator<IKomponente*>{it_komponente};
    auto nearest_dist = pk->distance(*nearest_it);
    ++it_komponente;

    while (it_komponente != komponenten.end())
    {
        auto distance = pk->distance(*it_komponente);
        if (distance < nearest_dist)
        {
            nearest_dist = distance;
            nearest_it = Iterator<IKomponente*>{it_komponente};
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

QJsonObject Werkstueck::toJson() const {
    auto components = QJsonArray{};
    auto obj = Komponente::toJson();
    for (const auto& komponente : komponenten) {
        auto object = komponente->toJson();
        components.append(object);
    }
    obj["components"] = components;
    obj["height"] = getHeight();
    obj["width"] = getWidth();
    obj["pathIsOptimized"] = pathIsOptimized;
    obj["type"] = "Werkstueck";
    return obj;
}