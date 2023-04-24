//
// Created by deb on 05.05.22.
//

#ifndef PRAKTIKUM_TELEMENT_H
#define PRAKTIKUM_TELEMENT_H

#include "IKomponente.h"

template<typename T>
struct TElement {
    T k;
    TElement* before;
    TElement* next;
};

#endif //PRAKTIKUM_TELEMENT_H
