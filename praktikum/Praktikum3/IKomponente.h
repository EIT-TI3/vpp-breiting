#ifndef IKOMPONENTE_H  
#define IKOMPONENTE_H 

#include <iostream>
#include <QJsonObject>
#include <QJsonArray>
#include <typeinfo>

class IKomponente {
    public:
        virtual ~IKomponente() = default;
                
        virtual double getX() const = 0;
        virtual double getY() const = 0;
        
        virtual double getXAbsolute() const = 0;
        virtual double getYAbsolute() const = 0;

        virtual double calcTotalPath() const = 0;
        virtual double distance(IKomponente const* k) const = 0;

        virtual IKomponente const* getParent() const = 0;
        virtual void setParent(IKomponente const* p) = 0;
        
        virtual void output(std::ostream& os) const = 0;
        virtual QJsonObject toJson() const = 0;

};

inline std::ostream& operator<<(std::ostream& os, const IKomponente& ik) {
    ik.output(os);
    return os;
}

#endif