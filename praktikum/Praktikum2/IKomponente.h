//
// Created by deb on 05.05.22.
//

#ifndef PRAKTIKUM1_IKOMPONENTE_H
#define PRAKTIKUM1_IKOMPONENTE_H

#include <iostream>

class IKomponente {

private:

protected:

public:
    virtual ~IKomponente() = default;

    virtual double calcTotalPath() const = 0;

    virtual double getXAbsolute() const = 0;
    virtual double getYAbsolute() const = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;

    virtual double distance(IKomponente const* k) const = 0;
    virtual IKomponente const* getParent() const = 0;
    virtual void setParent(IKomponente const* p) = 0;

    virtual void output(std::ostream& os) const = 0;

};

inline std::ostream& operator<<(std::ostream& os, const IKomponente& k) {
    k.output(os);
    return os;
}


#endif //PRAKTIKUM1_IKOMPONENTE_H
