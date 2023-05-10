#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include <iostream>

class Komponente {

private:
    double x, y;

protected:

public:
    explicit Komponente(double xPos = 0.0, double yPos = 0.0);
    virtual ~Komponente() = default;

    double getX() const;
    double getY() const;

    virtual void output(std::ostream& os) const;

};

inline std::ostream& operator<<(std::ostream& os, const Komponente& k) {
    k.output(os);
    return os;
}

#endif
