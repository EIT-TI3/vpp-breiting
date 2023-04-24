//
// Created by deb on 05.05.22.
//

#ifndef PRAKTIKUM_ITERATOR_H
#define PRAKTIKUM_ITERATOR_H


#include "IKomponentenElement.h"

class Iterator {

private:
    IKomponentenElement* curr;

protected:

public:
    explicit Iterator(IKomponentenElement* begin = nullptr);
    virtual ~Iterator() = default;

    Iterator& operator++() {
        curr = curr->next;
        return *this;
    }
    bool operator!=(Iterator const& it) const {
        return !operator==(it);
    }
    bool operator==(Iterator const& it) const {
        return this->curr == it.curr;
    }

    IKomponente* operator*() const {
        return curr->k;
    }
};


#endif //PRAKTIKUM_ITERATOR_H
