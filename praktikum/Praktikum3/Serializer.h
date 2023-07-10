#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "IKomponente.h"

class Serializer {
private:
    IKomponente const& ik;
protected:

public:
    explicit Serializer(IKomponente const& root);
    ~Serializer() = default;

    void writeToJson(char const* fname);

};


#endif
