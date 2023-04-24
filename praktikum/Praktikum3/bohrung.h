//
// Created by deb on 04.05.22.
//

#ifndef CLIONPRAKTIKUM1_BOHRUNG_H
#define CLIONPRAKTIKUM1_BOHRUNG_H

#include <iostream>
#include "komponente.h"

class Bohrung : public Komponente {

private:
    double diameter;

protected:

public:
    Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0);
    ~Bohrung() override = default;

    double getDiameter() const;
    void output(std::ostream& os) const override;

    QJsonObject toJson() const override;

};


#endif //CLIONPRAKTIKUM1_BOHRUNG_H
