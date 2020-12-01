#ifndef PETDATABASESORTBYPRICE_H
#define PETDATABASESORTBYPRICE_H

#include <vector>
using std::vector;

#include "petdatabasesortable.h"

class PetDataBaseSortByPrice:public PetDataBaseSortable
{
protected:
    vector<Pet*> PetVector;
public:
    PetDataBaseSortByPrice(vector<Pet*> petVector){
        for(auto e:petVector){
            PetVector.push_back(e);
        }
    }
    ~PetDataBaseSortByPrice(){
        PetVector.clear();
        PetVector.shrink_to_fit();
    }

    bool smaller(int i, int j) const{
        //return PetVector[i]->getName()<PetVector[j]->getName();
        return PetVector[i]->getPrice()<PetVector[j]->getPrice();
    }
    void swap(int i, int j){
        Pet* temp=PetVector[i];
        PetVector[i]=PetVector[j];
        PetVector[j]=temp;
        temp=nullptr;
    }
    unsigned int getSize() const{
        return PetVector.size();
    }
    Pet* getPet(int i) const{
        return PetVector[i];
    }
};

#endif // PETDATABASESORTBYPRICE_H
