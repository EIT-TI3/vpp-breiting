//
// Created by deb on 04.05.22.
//

#ifndef CLIONPRAKTIKUM1_KOMPONENTENLIST_H
#define CLIONPRAKTIKUM1_KOMPONENTENLIST_H

#include "komponente.h"
#include "TElement.h"
#include "Iterator.h"

template<typename T>
class DeList {

private:
    int counter;
    TElement<T>* first;
    TElement<T>* getElement(Iterator<T> it) const;

protected:

public:
    DeList();
    DeList(DeList const& rhs);
    ~DeList();

    DeList& operator=(DeList const& rhs);

    void clear();
    int size() const;
    Iterator<T> erase(Iterator<T> pos);
    void push_back(IKomponente* k);
    Iterator<T> end() const;
    Iterator<T> begin() const;

};


#endif //CLIONPRAKTIKUM1_KOMPONENTENLIST_H
