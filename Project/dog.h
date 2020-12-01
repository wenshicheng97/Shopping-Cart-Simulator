#ifndef DOG_H
#define DOG_H

#include"pet.h"

class Dog:public Pet
{
protected:
    string m_category;
public:
    Dog()=default;
    Dog(string name,string t,double price,string category):Pet(name,t,price),m_category(category){};
    virtual void Accept(Visitor *v){
            v->VisitDog(this);
    }
    string getSpecial() const{
        ostringstream oss;
        oss<<m_type;
        return oss.str();
    }
    string getClass() const{
        return "Dog";
    }

};

#endif // DOG_H
