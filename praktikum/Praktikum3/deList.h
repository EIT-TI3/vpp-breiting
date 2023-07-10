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

        void push_back(T);
        
        Iterator<T> erase(Iterator<T> pos);
        Iterator<T> end() const;
        Iterator<T> begin() const;

        void output(std::ostream& os) const {
            os << "[";
            for (auto element : *this) {
                os << element << ", ";
            }
            os << "]" << std::endl;
        }
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const DeList<T>& ik) {
    ik.output(os);
    return os;
}

#endif