//
// Created by deb on 04.05.22.
//

#ifndef CLIONPRAKTIKUM1_KOMPONENTE_H
#define CLIONPRAKTIKUM1_KOMPONENTE_H

#include <iostream>
#include "IKomponente.h"

class Komponente : public IKomponente {

private:
    double x, y;
    IKomponente const* parent;

protected:

public:
    explicit Komponente(double xPos = 0.0, double yPos = 0.0);
    ~Komponente() override = default;

    double calcTotalPath() const override;

    double getXAbsolute() const override;
    double getYAbsolute() const override;
    double getX() const override {
        return x;
    };
    double getY() const override {
        return y;
    };

    double distance(IKomponente const* k) const override;
    IKomponente const* getParent() const override;
    void setParent(IKomponente const* p) override;

    void output(std::ostream& os) const override;


};

#endif //CLIONPRAKTIKUM1_KOMPONENTE_H
