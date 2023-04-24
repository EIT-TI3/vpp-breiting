
#ifndef PRAKTIKUM_DELIST_IMPL_H
#define PRAKTIKUM_DELIST_IMPL_H


#include "deList.h"

template<typename T>
DeList<T>::DeList() : counter{0}, first{nullptr} {}

template<typename T>
DeList<T>::DeList(const DeList &rhs) {
    for(auto element : rhs) {
        push_back(element);
    }
}

template<typename T>
DeList<T>::~DeList() {
    clear();
}

template<typename T>
int DeList<T>::size() const {
    return counter;
}

template<typename T>
TElement<T>* DeList<T>::getElement(Iterator<T> it) const {
    auto selected_element = first;
    TElement<T>* found_element = nullptr;
    for(int i=0; i < counter; i++) {
        if(selected_element->k == *it) {
            found_element = selected_element;
            break;
        }
        selected_element = selected_element->next;
    }
    return found_element;
}

//Komponente const *KomponentenList::at(int pos) const {
//    KomponentenElement* element = nullptr;
//    if(pos >= 0 && pos < counter) {
//        element = getElement(pos);
//    }
//    return element != nullptr ? element->k : nullptr;
//}

template<typename T>
Iterator<T> DeList<T>::erase(Iterator<T> pos) {
    TElement<T>* element_to_delete = getElement(pos);
    Iterator return_iterator = Iterator<T>();

    if(element_to_delete != nullptr) {
        TElement<T>* element_before = element_to_delete->before;
        TElement<T>* element_next = element_to_delete->next;

        delete element_to_delete;
        if(element_before == nullptr) {
            first = element_next;
            if(first != nullptr) {
                first->before = nullptr;
            }
        }
        if(element_before != nullptr) element_before->next = element_next;
        if(element_next != nullptr) element_next->before = element_before;
        counter--;
        if(element_next != nullptr) {
            return_iterator = Iterator{element_next};
        }
    }

    return return_iterator;
}

template<typename T>
void DeList<T>::push_back(IKomponente *k) {
    auto new_element = new TElement<T>;
    new_element->before = nullptr;
    new_element->k = k;
    new_element->next = nullptr;

    if(counter != 0) {
        TElement<T>* last_element = first;
        while(last_element->next != nullptr) last_element = last_element->next;

        last_element->next = new_element;
        new_element->before = last_element;
    } else {
        first = new_element;
    }

    counter++;
}

template<typename T>
Iterator<T> DeList<T>::end() const {
    return Iterator<T>{};
}

template<typename T>
Iterator<T> DeList<T>::begin() const {
    return Iterator{first};
}

template<typename T>
void DeList<T>::clear() {
    auto next_item_delete = first;
    while(next_item_delete != nullptr) {
        auto next_tmp = next_item_delete->next;
        delete next_item_delete;
        next_item_delete = next_tmp;
    }
    counter = 0;
}

template<typename T>
DeList<T> &DeList<T>::operator=(const DeList &rhs) {
    if(this != &rhs) {
        clear();
        for(auto element : rhs) {
            push_back(element);
        }
    }
    return *this;
}

#endif //PRAKTIKUM_DELIST_IMPL_H
