#ifndef STRARRAY_H
#define STRARRAY_H

#include <iostream>

using std::ostream;
using std::cout;
using std::endl;


class StrArray
{
    size_t cap, len;
    char *start;
public:
    StrArray(size_t c=10);
    StrArray(char ch, size_t c=10);
    // StrArray(const char *str);

    StrArray(const StrArray &src) :
        cap(0), len(src.len), start{nullptr}
    {
        start=new char[src.cap];
        for (size_t i=0; i< src.len; ++i)
            start[i]=src.start[i];
        start[src.size()]='\0';

        len=src.len; // src.size()
        cap=src.capacity();
    }
    void out(ostream &o) const;

    StrArray &operator+=(const StrArray &src);
    StrArray &operator=(const StrArray &src) {

        if (this!=&src) {
            delete [] start;
            cap=src.cap;
            len=src.len;
            start=new char[cap];
            for (size_t i=0; i<len; ++i)
                start[i]=src.start[i];

            if (cap>0)
                start[len]='\0';

        }

        return *this;
    }


    size_t size() const { return len; }
    size_t capacity() const { return cap; }


    ~StrArray();

};

// ostream &operator<<(ostream &o, const StrArray &s);
inline ostream &operator<<(ostream &o, const StrArray &s) {
    s.out(o);
    return o;
}

// Operator +
inline StrArray operator+(const StrArray &a, const StrArray &b)
{
    StrArray ret{a};
    ret+=b;
    return ret;
}
#endif // STRARRAY_H
