//
// Created by deb on 04.05.22.
//

#ifndef CLIONPRAKTIKUM1_KOMPONENTENLIST_H
#define CLIONPRAKTIKUM1_KOMPONENTENLIST_H

#include "komponente.h"
#include "IKomponentenElement.h"
#include "Iterator.h"

class DeList {

private:
    int counter;
    IKomponentenElement* first;
    IKomponentenElement* getElement(Iterator it) const;

protected:

public:
    DeList();
    DeList(DeList const& rhs);
    ~DeList();

    DeList& operator=(DeList const& rhs);

    void clear();
    int size() const;
    Iterator erase(Iterator pos);
    void push_back(IKomponente* k);
    Iterator end() const;
    Iterator begin() const;

};


#endif //CLIONPRAKTIKUM1_KOMPONENTENLIST_H
