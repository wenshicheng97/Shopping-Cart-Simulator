#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "petdatabasesortable.h"

class BubbleSort
{
public:
    void sort(PetDataBaseSortable* petdata){
        bool sorted=false;
        int n=petdata->getSize();
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(needSwap(petdata,i-1,i)){
                    petdata->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }
    }
    virtual bool needSwap(PetDataBaseSortable* petdata,int i,int j);
};

#endif // BUBBLESORT_H
