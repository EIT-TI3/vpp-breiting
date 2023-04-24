//
// Created by deb on 04.05.22.
//

#ifndef CLIONPRAKTIKUM1_FRAESUNG_H
#define CLIONPRAKTIKUM1_FRAESUNG_H

#include <iostream>
#include "bohrung.h"

class Fraesung : public Bohrung {

private:
    double length;
    double angle;

protected:

public:
    explicit Fraesung(double x, double y, double diam, double l, double a = 0.0);
    ~Fraesung() override = default;

    double calcTotalPath() const override;

    double getLength() const {
        return length;
    };
    double getAngle() const {
        return angle;
    };
    double getEndX() const;
    double getEndY() const;
    void output(std::ostream& os) const override;

    QJsonObject toJson() const override;

};
//
//inline std::ostream& operator<<(std::ostream& os, const Fraesung& k) {
//    k.output(os);
//    return os;
//}


#endif //CLIONPRAKTIKUM1_FRAESUNG_H
