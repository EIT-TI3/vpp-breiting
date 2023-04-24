//
// Created by deb on 05.05.22.
//

#ifndef PRAKTIKUM_IKOMPONENTENELEMENT_H
#define PRAKTIKUM_IKOMPONENTENELEMENT_H

#include "IKomponente.h"

struct IKomponentenElement {
    IKomponente* k;
    IKomponentenElement* before;
    IKomponentenElement* next;
};

#endif //PRAKTIKUM_IKOMPONENTENELEMENT_H
