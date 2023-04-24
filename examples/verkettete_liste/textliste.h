#ifndef TEXTLISTE_H
#define TEXTLISTE_H

#include <string>
#include <iostream>


struct Element {
    std::string text;
    Element *next;
};

class TextListe {
    Element *first=nullptr;
    size_t cnt=0;

public:
    TextListe() : first(nullptr), cnt(0) {};

    TextListe(std::initializer_list<std::string> l) :
        first(nullptr), cnt(0) {
        
        for (std::string element : l) {
            push_back(element);
        }
    }

    TextListe(const TextListe &src) : first(nullptr), cnt(0) {
        Element *acc = src.first;
        while (acc != nullptr) {
            push_back(acc->text);
            acc = acc -> next;
        }
    }

    ~TextListe() {
        first=nullptr;
        cnt=0;
        Element *acc = first;
        while (acc!=nullptr) {
            Element *next = acc->next;
            delete acc;
            acc = next;
        }
    }

    void clear() {
        Element *acc = first;
        while (acc != nullptr) {
            push_back(acc->text);
            delete acc;
            acc = acc -> next;
        }
        first=nullptr;
        cnt=0;
    }

    TextListe &operator=(const TextListe &src) {
        if (this!=&src) {
            Element *acc = src.first;
            while (acc != nullptr) {
                push_back(acc->text);
                acc = acc -> next;
            }
            first=nullptr;
            cnt=0;
        }
        return *this;
    }

    void push_back(const std::string &t) {
        Element *neu = new Element;
        neu -> text = t;
        neu -> next = nullptr;

        // Check if list is not empty
        if (first != nullptr) {
            Element *last = first;
            // loop until next is null
            while (last -> next!=nullptr) {
                last = last->next;
            }
            last->next=neu;
        } else {
            first = neu;
        }
        cnt++;
    }

    void out(std::ostream &o) const {
        Element *acc = first;
        while (acc!=nullptr) {
            o << acc->text;
            acc = acc->next;
        }
    }

};

#endif // TEXTLISTE_H