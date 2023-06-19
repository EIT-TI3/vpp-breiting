#ifndef DE_LIST_H
#define DE_LIST_H

#include "IKomponentenElement.h"
#include "Iterator.h"

class DeList {
    private:
        int counter;
        IKomponentenElement* first;
        IKomponentenElement* getElement(Iterator it) const;
        
    public:
        DeList();
        DeList(DeList const& rhs);
        DeList& operator=(DeList const& rhs);
        ~DeList();
        void clear();
        int size() const;
        Iterator erase(Iterator pos);
        void push_back(IKomponente* k);
        Iterator end() const;
        Iterator begin() const;
};

#endif