#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H

#include "bubblesort.h"
#include "petdatabasesortable.h"

class BubbleSortIncreasing:public BubbleSort
{
public:
    bool needSwap(PetDataBaseSortable *petdata, int i, int j){
        return !petdata->smaller(i,j);
    }
};

#endif // BUBBLESORTINCREASING_H
