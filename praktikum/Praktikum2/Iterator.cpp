#include "Iterator.h"

Iterator::Iterator(IKomponentenElement* begin) : curr{begin} {
}

Iterator& Iterator::operator++() {
    if (curr != nullptr)
        curr = curr ->next;
    return *this;
}

bool Iterator::operator!=(Iterator const& it) const {
    return !operator==(it);
}

bool Iterator::operator==(Iterator const& it) const {
    return curr == it.curr;
}

IKomponente* Iterator::operator*() const {
    if (curr == nullptr)
        return nullptr;

    return curr->k;
}