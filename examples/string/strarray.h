#ifndef STRARRAY_H
#define STRARRAY_H

#include <iostream>

class StrArray {
    size_t cap, len;
public:
    char *start;
public:
    StrArray(size_t c=10);
    StrArray(char ch, size_t c=10);

    StrArray(const StrArray &src) =delete;

    ~StrArray() {
        delete [] start;
        start=nullptr;
        cap=len=0;
    };
};

#endif // STRARRAY_H

