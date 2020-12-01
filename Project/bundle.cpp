#include "bundle.h"

#include "totalpricevisitor.h"

void Bundle::addPet(Pet *pet){
    includes.push_back(pet);
    total+=pet->getPrice();
}

unsigned int Bundle::getSize() const{
    return includes.size();
}

void Bundle::Accept(Visitor *v){
    v->VisitBundle(this);
}

double Bundle::computeTotal(){
    //return total;
    TotalPriceVisitor tpv;
    this->Accept(&tpv);
    //total=tpv.getResult();
    return tpv.getResult();
}
