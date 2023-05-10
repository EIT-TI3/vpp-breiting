#include "komponentenList.h"

KomponentenList::KomponentenList() : counter{0}, first{nullptr} {}

KomponentenList::~KomponentenList() {
    auto n = first;
    while (n != nullptr) {
        auto tmp = n -> next;
        delete n;
        n = tmp;
    }
}

KomponentenElement* KomponentenList::getElement(int pos) const {
    if (pos > counter || pos < 0)
        return nullptr;
    auto n = first;
    for(int i=0; i < pos; i++) {
        if (n == nullptr)
            break;
        n = n->next;
    }

    return n;
}

int KomponentenList::size() const {
    return counter;
}

const Komponente* KomponentenList::at(int pos) const {
    auto n = getElement(pos);
    return n != nullptr ? n->k : nullptr;
}

int KomponentenList::erase(int pos) {
    auto n = getElement(pos);
    if (n == nullptr)
        return -1;

    auto before = n->before;
    auto next = n->next;

    if (n == first) {
        first = next;
    } else {
        if (before != nullptr)
            before->next = next;
    }
    if (next != nullptr)
        next->before = before;
    delete n;
    counter --;
    return pos;
}

KomponentenElement* KomponentenList::end() const {
    return nullptr;
}

KomponentenElement* KomponentenList::begin() const {
    return first;
}

void KomponentenList::push_back(Komponente* k) {
    auto *n = new KomponentenElement;
    n->k = k;
    n->next = nullptr;

    if (first == nullptr) {
        n->before = nullptr;
        first = n;
    } else {
        auto* last = getElement(counter - 1);
        n->before = last;
        last->next = n;
    }
    counter++;
}