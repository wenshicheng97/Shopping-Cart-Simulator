#ifndef TOTALPRICEVISITOR_H
#define TOTALPRICEVISITOR_H

#include "visitor.h"
#include "pet.h"
#include "bundle.h"
#include "bird.h"
#include "cat.h"
#include "dog.h"
#include "fish.h"

class TotalPriceVisitor:public Visitor
{
protected:
    double sum;
public:
    TotalPriceVisitor():sum(0){};
    virtual ~TotalPriceVisitor(){};
    void VisitBird(Bird* bird){
        sum+=bird->getPrice();
    }
    void VisitCat(Cat* cat){
        sum+=cat->getPrice();
    }
    void VisitDog(Dog* dog){
        sum+=dog->getPrice();
    }
    void VisitFish(Fish* fish){
        sum+=fish->getPrice();
    }
    void VisitBundle(Bundle* bundle){
        for(unsigned int i=0;i<bundle->getSize();i++){
            if(bundle->getPet(i)->getClass()!="Bundle")
                bundle->getPet(i)->Accept(this);
            else
                sum+=bundle->getPet(i)->getPrice();
        }
    }
    double getResult(){
        double result=sum;
        sum=0;
        return result;
    }
};

#endif // TOTALPRICEVISITOR_H
