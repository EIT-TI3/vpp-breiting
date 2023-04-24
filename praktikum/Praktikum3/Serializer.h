//
// Created by deb on 17.06.22.
//

#ifndef PRAKTIKUM_SERIALIZER_H
#define PRAKTIKUM_SERIALIZER_H

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


#endif //PRAKTIKUM_SERIALIZER_H
