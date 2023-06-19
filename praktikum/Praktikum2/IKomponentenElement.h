#ifndef I_KOMPONENTE_ELEMENT_H
#define I_KOMPONENTE_ELEMENT_H

#include "IKomponente.h"

struct IKomponentenElement {
    IKomponente* k;
    IKomponentenElement* before;
    IKomponentenElement* next;
};


#endif