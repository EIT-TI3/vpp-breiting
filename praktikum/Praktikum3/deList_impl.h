#ifndef DELIST_IMPL_H
#define DELIST_IMPL_H
#include "deList.h"

template<typename T>
DeList<T>::DeList() : counter{0}, first{nullptr} {}

template<typename T>
Iterator<T> DeList<T>::end() const {
    return Iterator<T>();
}

template<typename T>
Iterator<T> DeList<T>::begin() const {
    return Iterator(first);
}

template<typename T>
TElement<T>* DeList<T>::getElement(Iterator<T> it) const {
    auto curr = first;
    TElement<T>* found = nullptr;
    for (int i=0; i<counter; i++) {
        if (curr->k == *it) {
            found = curr;
            break;
        }
        curr = curr ->next;
    }
    return found;
}

template<typename T>
DeList<T>::DeList(DeList<T> const& rhs) {
    for(auto element : rhs) {
        push_back(element);
    }
}

template<typename T>
DeList<T>& DeList<T>::operator=(DeList<T> const& rhs) {
    if(this != &rhs) {
        clear();
        for(auto element : rhs) {
            push_back(element);
        }
    }
    return *this;
}

template<typename T>
DeList<T>::~DeList() {
    clear();
}

template<typename T>
void DeList<T>::clear() {
    auto n = first;
    while (n != nullptr) {
        auto tmp = n -> next;
        delete n;
        n = tmp;
    }
    counter = 0;
    first = nullptr;
}

template<typename T>
int DeList<T>::size() const {
    return counter;
}

template<typename T>
Iterator<T> DeList<T>::erase(Iterator<T> pos) {
    TElement<T>* n = getElement(pos);
    if (n == nullptr)
        return Iterator<T>();

    TElement<T>* before = n->before;
    TElement<T>* next = n->next;

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

template<typename T>
void DeList<T>::push_back(IKomponente *k) {
    auto new_element = new TElement<T>;
    new_element->before = nullptr;
    new_element->k = k;
    new_element->next = nullptr;

    if(first == nullptr) {
        first = new_element;
    } else {
        TElement<T>* last_element = first;
        while(last_element->next != nullptr) 
            last_element = last_element->next;

        last_element->next = new_element;
        new_element->before = last_element;
    }
    counter++;
}

#endif