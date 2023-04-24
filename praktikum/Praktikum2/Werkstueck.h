//
// Created by deb on 06.05.22.
//

#ifndef PRAKTIKUM_WERKSTUECK_H
#define PRAKTIKUM_WERKSTUECK_H

#include "komponente.h"
#include "deList.h"

class Werkstueck : public Komponente {

private:
    double height;
    double width;
    bool pathIsOptimized;
    DeList komponenten;

    Iterator getNearest(IKomponente const* pk) const;

protected:

public:
    explicit Werkstueck(double xPos = 0.0, double yPos = 0.0, double h = 1, double w = 1);
    ~Werkstueck() override = default;

    double getHeight() const {
        return height;
    };
    double getWidth() const {
        return width;
    };

    void add(IKomponente* k);
    void remove(IKomponente* k);

    IKomponente const* getChild(int i) const;
    double calcTotalPath() const override;
    double calcPathLength() const;
    void optimizePath();
    void output(std::ostream& os) const override;

};


#endif //PRAKTIKUM_WERKSTUECK_H
