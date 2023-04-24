//
// Created by deb on 06.05.22.
//

#include "Werkstueck.h"
#include "deList_impl.h"
#include <string>
#include <iostream>
#include <QJsonArray>

Werkstueck::Werkstueck(double xPos, double yPos, double h, double w) : Komponente(xPos, yPos), height{h}, width{w}, pathIsOptimized{false} {
}

void Werkstueck::add(IKomponente *k) {
    if(k != nullptr) {
        k->setParent(this);
        komponenten.push_back(k);
        pathIsOptimized = false;
    }
}

void Werkstueck::remove(IKomponente* k) {
    if(k != nullptr) {
        auto element = TElement<IKomponente*>{k, nullptr, nullptr};
        komponenten.erase(Iterator{&element});
        k->setParent(nullptr);
        pathIsOptimized = false;
    }
}

IKomponente const* Werkstueck::getChild(int i) const {
    auto komp_iter = komponenten.begin();
    IKomponente* next_komponente = nullptr;
    for(int cnt = 0; cnt <= i && komp_iter != komponenten.end(); i++) {
        next_komponente = *komp_iter;
        ++komp_iter;
    }
    return next_komponente;
}

double Werkstueck::calcPathLength() const {
    double totalPathLength = 0.0;
    const IKomponente* last_element = this;
    for(auto komponente : komponenten) {
        totalPathLength += last_element->distance(komponente);
        last_element = komponente;
    }
    // Add path len to home position.
    totalPathLength += last_element->distance(this);

    return totalPathLength;
}

double Werkstueck::calcTotalPath() const {
    double totalPathLength = 0.0;
    for(auto komponente : komponenten) {
        totalPathLength += komponente->calcTotalPath();
    }
    totalPathLength += calcPathLength();

    return totalPathLength;
}

void Werkstueck::output(std::ostream &os) const {
    // get tree depth padding
    std::string padding;
    const IKomponente* last_parent = getParent();
    while (last_parent != nullptr) {
        last_parent = last_parent->getParent();
        padding.append(" ");
    }

    os << padding << "Werkstueck:\n"
       << padding << "Verankerung: (" << getX() << ", " << getY() << ")\n"
       << padding << "height: " << height << ", width: " << width << "\n"
       << padding << "Komponenten:" << std::endl;

    for(auto komponente : komponenten) {
        if(dynamic_cast<Werkstueck*>(komponente) == nullptr) {
            os << padding;
        }
        os << *komponente;
        if(dynamic_cast<Werkstueck*>(komponente) == nullptr) {
            os << std::endl;
        }
    }
}

Iterator<IKomponente*> Werkstueck::getNearest(const IKomponente *pk) const {
    auto iter_komponente = komponenten.begin();
    if(iter_komponente == komponenten.end()) {  // no children in list
        return Iterator<IKomponente*>{};
    }

    Iterator nearest_iter = Iterator{iter_komponente};
    double nearest_distance = pk->distance(*nearest_iter);
    ++iter_komponente;

    while(iter_komponente != komponenten.end()) {
        auto distance = pk->distance(*iter_komponente);
        if(distance < nearest_distance) {
            nearest_distance = distance;
            nearest_iter = Iterator{iter_komponente};
        }
        ++iter_komponente;
    }
    return nearest_iter;
}

// Solve approximately the Traveling Sales Man Problem (TSP) using a
// nearses neighbour strategy:
// round trip starts at the linking point of the Werkstueck.
// then go always to the nearest neighbour among the components
// that are not already on the new path
void Werkstueck::optimizePath() {
    if (!pathIsOptimized && komponenten.size() > 0) {
        // first call optimizePath for all Components,
        // which are of type Werkstueck recursively
        Iterator it = komponenten.begin();
        while (it != komponenten.end()) {
            Werkstueck* w = dynamic_cast<Werkstueck*>(*it);
            if (w != nullptr) {
                w->optimizePath();
            }
            ++it;
        }
        // Now determine a nearest neighbour-sorting
        // of all components
        DeList<IKomponente*> komponentenSortiert;
        IKomponente* pcurrent = this;
        Iterator nearest = getNearest(pcurrent);
        komponentenSortiert.push_back(*nearest);
        pcurrent = *nearest;
        komponenten.erase(nearest);
        while (komponenten.size() > 0) {
            nearest = getNearest(pcurrent);
            komponentenSortiert.push_back(*nearest);
            pcurrent = *nearest;
            komponenten.erase(nearest);
        }
        komponenten = komponentenSortiert;
        pathIsOptimized = true;
    }
}

QJsonObject Werkstueck::toJson() const {
    QJsonObject werkstueckObject;

    QJsonArray componentArray;
    for(auto komponente : komponenten) {
        auto componentObject = komponente->toJson();
        componentArray.append(componentObject);
    }
    werkstueckObject["components"] = componentArray;

    werkstueckObject["hasParent"] = getParent() != nullptr;
    werkstueckObject["height"] = getHeight();
    werkstueckObject["pathIsOptimized"] = pathIsOptimized;
    werkstueckObject["type"] = "Werkstueck";
    werkstueckObject["width"] = getWidth();
    werkstueckObject["x"] = getX();
    werkstueckObject["y"] = getY();

    return werkstueckObject;
}
