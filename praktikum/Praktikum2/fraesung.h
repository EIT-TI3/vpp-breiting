#ifndef FRAESUNG_H
#define FRAESUNG_H

#include "bohrung.h"

class Fraesung : public Bohrung {
    private:
        double length, angle;
    public:
        Fraesung(double x, double y, double diam, double l, double a = 0.0);
        double calcTotalPath() const;
        double getLength() const;
        double getAngle() const;
        void output(std::ostream& os) const;
        double getEndX() const;
        double getEndY() const;
        
};

#endif