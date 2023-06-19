#include "deList.h"

IKomponentenElement* DeList::getElement(Iterator it) const {
    auto curr = first;
    IKomponentenElement* found = nullptr;
    for (int i=0; i<counter; i++) {
        if (curr->k == *it) {
            found = curr;
            break;
        }
        curr = curr ->next;
    }
    return found;
}

DeList::DeList() : counter{0}, first{nullptr} {}

DeList::DeList(DeList const& rhs) {
    for(auto element : rhs) {
        push_back(element);
    }
}

DeList& DeList::operator=(DeList const& rhs) {
    if(this != &rhs) {
        clear();
        for(auto element : rhs) {
            push_back(element);
        }
    }
    return *this;
}

DeList::~DeList() {
    clear();
}

void DeList::clear() {
    auto n = first;
    while (n != nullptr) {
        auto tmp = n -> next;
        delete n;
        n = tmp;
    }
    counter = 0;
    first = nullptr;
}

int DeList::size() const {
    return counter;
}

Iterator DeList::erase(Iterator pos) {
    auto n = getElement(pos);
    if (n == nullptr)
        return Iterator();

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
    return Iterator(next);
}

void DeList::push_back(IKomponente *k) {
    auto new_element = new IKomponentenElement;
    new_element->before = nullptr;
    new_element->k = k;
    new_element->next = nullptr;

    if(first == nullptr) {
        first = new_element;
    } else {
        auto last_element = first;
        while(last_element->next != nullptr) 
            last_element = last_element->next;

        last_element->next = new_element;
        new_element->before = last_element;
    }
    counter++;
}

Iterator DeList::end() const {
    return Iterator();
}

Iterator DeList::begin() const {
    return Iterator(first);
}