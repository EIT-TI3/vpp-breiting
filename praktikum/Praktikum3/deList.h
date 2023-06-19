#ifndef DE_LIST_H
#define DE_LIST_H

#include "TElement.h"
#include "Iterator.h"

template<typename T>
class DeList {
    private:
        int counter;
        TElement<T>* first;
        TElement<T>* getElement(Iterator<T> it) const;
        
    public:
        DeList();
        DeList(DeList const& rhs);
        ~DeList();

        DeList& operator=(DeList<T> const& rhs);
        
        void clear();
        int size() const;
        void push_back(IKomponente* k);
        
        Iterator<T> erase(Iterator<T> pos);
        Iterator<T> end() const;
        Iterator<T> begin() const;
};

#endif