#ifndef BOHRUNG_H
#define BOHRUNG_H

#include <ostream>
#include "komponente.h"

class Bohrung: public Komponente {
    private:
        double diameter;
    public:
        explicit Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0);
        ~Bohrung() override = default;
        double getDiameter() const;
        void output(std::ostream& os) const override;
        QJsonObject toJson() const override;
};

inline double Bohrung::getDiameter() const {
    return diameter;
}

#endif