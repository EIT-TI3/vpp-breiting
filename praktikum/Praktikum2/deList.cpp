//
// Created by deb on 04.05.22.
//

#include "deList.h"

DeList::DeList() : counter{0}, first{nullptr} {}

DeList::DeList(const DeList &rhs) {
    for(auto element : rhs) {
        push_back(element);
    }
}

DeList::~DeList() {
    clear();
}

int DeList::size() const {
    return counter;
}

IKomponentenElement* DeList::getElement(Iterator it) const {
    auto selected_element = first;
    IKomponentenElement* found_element = nullptr;
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

Iterator DeList::erase(Iterator pos) {
    IKomponentenElement* element_to_delete = getElement(pos);
    Iterator return_iterator = Iterator();

    if(element_to_delete != nullptr) {
        IKomponentenElement* element_before = element_to_delete->before;
        IKomponentenElement* element_next = element_to_delete->next;

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

void DeList::push_back(IKomponente *k) {
    auto new_element = new IKomponentenElement;
    new_element->before = nullptr;
    new_element->k = k;
    new_element->next = nullptr;

    if(counter != 0) {
        IKomponentenElement* last_element = first;
        while(last_element->next != nullptr) last_element = last_element->next;

        last_element->next = new_element;
        new_element->before = last_element;
    } else {
        first = new_element;
    }

    counter++;
}

Iterator DeList::end() const {
    return Iterator{};
}

Iterator DeList::begin() const {
    return Iterator{first};
}

void DeList::clear() {
    auto next_item_delete = first;
    while(next_item_delete != nullptr) {
        auto next_tmp = next_item_delete->next;
        delete next_item_delete;
        next_item_delete = next_tmp;
    }
    counter = 0;
}

DeList &DeList::operator=(const DeList &rhs) {
    if(this != &rhs) {
        clear();
        for(auto element : rhs) {
            push_back(element);
        }
    }
    return *this;
}

