#ifndef CAT_H
#define CAT_H

#include "pet.h"

class Cat:public Pet
{
protected:
    bool fluffy;
public:
    Cat()=default;
    Cat(string name,string t,double price,double f):Pet(name,t,price),fluffy(f){};
    virtual void Accept(Visitor *v){
            v->VisitCat(this);
    }
    string getSpecial() const{
        ostringstream oss;
        oss<<((fluffy)?"Fluffy ":"Non-fluffy ")<<m_type;
        return oss.str();
    }
    string getClass() const{
        return "Cat";
    }
};

#endif // CAT_H
