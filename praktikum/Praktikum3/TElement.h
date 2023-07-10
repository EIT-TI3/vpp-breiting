#ifndef T_ELEMENT_H
#define T_ELEMENT_H

template <typename T>
struct TElement {
    T k;
    TElement* before;
    TElement* next;
};


#endif