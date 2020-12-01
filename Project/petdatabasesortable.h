#ifndef PETDATABASESORTABLE_H
#define PETDATABASESORTABLE_H

#include "pet.h"

class PetDataBaseSortable
{
public:
    virtual bool smaller(int i,int j)const=0;
    virtual void swap(int i,int j)=0;
    virtual unsigned int getSize() const=0;
    virtual Pet* getPet(int i) const=0;
};

#endif // PETDATABASESORTABLE_H
