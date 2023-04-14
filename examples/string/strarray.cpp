#include "strarray.h"


StrArray::StrArray(size_t c) : cap(c), len{0}, start(nullptr) {
    start = new char[c];
    if (c>0)
        *start = '\0'; // start[0] = '\0'; | *(start+0) = '\0';
}

StrArray::StrArray(char ch, size_t c) : cap(c>1 ? c: 2), len{1}, start(nullptr) {
    start = new char[cap];
    *start = ch;
    *(start+1) = '\0';
}

void StrArray::out(std::ostream &o) const {
    if (len > 0)
        o << start;
}

