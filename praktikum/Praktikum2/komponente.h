#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include "IKomponente.h"

class Komponente : public IKomponente {
    private:
        double x, y = 0.0;
        IKomponente const* parent = nullptr;
    public:
        Komponente(double xPos, double yPos);
        double calcTotalPath() const;
        double getX() const override;
        double getY() const override;
        double getXAbsolute() const override;
        double getYAbsolute() const override;
        double distance(IKomponente const* k) const;
        IKomponente const* getParent() const;
        void setParent(IKomponente const* p);
        void output(std::ostream& os) const override;
};

inline double Komponente::calcTotalPath() const
{
    return 0.0;
}

inline double Komponente::getX() const
{
    return x;
}

inline double Komponente::getY() const
{
    return y;
}


#endif