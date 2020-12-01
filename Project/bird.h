#ifndef BIRD_H
#define BIRD_H

#include "pet.h"

class Bird:public Pet
{
protected:
    bool nocturnality;
public:
    Bird()=default;
    Bird(string name,string t,double price,bool noc):Pet(name,t,price),nocturnality(noc){};
    virtual void Accept(Visitor *v){
            v->VisitBird(this);
    }
    string getSpecial() const{
        ostringstream oss;
        oss<<((nocturnality)?"Nocturnal ":"Diurnal ")<<m_type;
        return oss.str();
    }
    string getClass() const{
        return "Bird";
    }
};

#endif // BIRD_H
