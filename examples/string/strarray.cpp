#include "strarray.h"

StrArray::StrArray(size_t c) : cap(c), len{0}, start(nullptr)
{
    //cout << "ctor" << endl;

    start=new char[c];
    if (c>0)
        *start='\0';  // start[0]='\0'; // *(start+0)='\0';
}

StrArray::StrArray(char ch, size_t c) :
    cap(c>1? c : 2), len{1}, start(nullptr)
{
    //cout << "ctor" << endl;

    start=new char[cap];
    *start=ch;  // start[0]=ch; // *(start+0)=ch;
    *(start+1)='\0';  // start[1]='\0';
}

StrArray::~StrArray() {
    // cout << "dtor" << endl;
    delete [] start;
    start=nullptr;
    cap=len=0;
}

void StrArray::out(ostream &o) const {
    if (len>0)
        o << start;
    /*
     * for (size_t i=0; i<len; ++i)
     *    o<< start[i];
     */
}

StrArray &StrArray::operator+=(const StrArray &src)
{
    size_t newlen=src.len+len;
    if (cap<newlen+1)
    {
        char *temp=new char[newlen+1];
        for (size_t i=0; i<len; ++i)
            temp[i]=start[i];
        delete [] start;
        start=temp;
        cap=newlen+1;
    }

    for (size_t i=0; i<src.len; ++i)
        start[i+len]=src.start[i];

    len+=src.len;
    start[len]='\0';

    return *this;
}

/// freie Funktion

/*ostream &operator<<(ostream &o, const StrArray &s) {
    s.out(o);
    return o;
}
*/
