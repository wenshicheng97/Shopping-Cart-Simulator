#ifndef FISH_H
#define FISH_H

#include "pet.h"

class Fish:public Pet
{
protected:
    string watertype;
public:
    Fish()=default;
    Fish(string name,string t,double price,string wt):Pet(name,t,price),watertype(wt){};
    virtual void Accept(Visitor *v){
            v->VisitFish(this);
    }
    string getSpecial() const{
        ostringstream oss;
        oss<<watertype<<' '<<m_type;
        return oss.str();
    }
    string getClass() const{
        return "Fish";
    }
};

#endif // FISH_H
