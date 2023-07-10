#ifndef WERKSTUEK_H
#define WERKSTUEK_H

#include "komponente.h"
#include "deList.h"

class Werkstueck : public Komponente {
    private:
        double height, width;
        bool pathIsOptimized;
        DeList<IKomponente*> komponenten;
        Iterator<IKomponente*> getNearest(IKomponente const* pk) const;
    public:
        Werkstueck(double xPos = 0.0, double yPos = 0.0, double h = 1, double w = 1);
        ~Werkstueck() override = default;

        double getHeight() const;
        double getWidth() const;

        void add(IKomponente* k);
        void remove(IKomponente const* k);

        IKomponente const* getChild(int i) const;

        double calcTotalPath() const;
        double calcPathLength() const;
        void optimizePath();
        
        void output(std::ostream& os) const;
        QJsonObject toJson() const override;
        
};

inline double Werkstueck::getHeight() const
{
    return height;
}

inline double Werkstueck::getWidth() const
{
    return width;
}

#endif