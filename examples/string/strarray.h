#ifndef STRARRAY_H
#define STRARRAY_H

#include <iostream>

class StrArray {
    size_t cap, len;
    char *start;
public:
    StrArray(size_t c=10);
    StrArray(char ch, size_t c=10);

    void out(std::ostream &o) const;

    StrArray(const StrArray &src) =delete;

    ~StrArray() {
        delete [] start;
        start=nullptr;
        cap=len=0;
    };
};

/// Freie Funktion zur Ausgabe eines StrArray-Objekts
inline std::ostream &operator<<(std::ostream &o, const StrArray &s) {
    s.out(o);
    return o;
};

#endif // STRARRAY_H

