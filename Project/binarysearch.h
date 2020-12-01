#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

#include "petdatabasesearchablesortbyname.h"

using namespace std;

class BinarySearch{
public:
    int search(PetDataBaseSearchableSortByName* searchableVector){
        int left=0;
        int right=searchableVector->getSize();
        int middle;
        while(left<=right){
            middle=(left+right)/2;
            if(searchableVector->compareAt(middle)<0)
                right=middle-1;
            else if(searchableVector->compareAt(middle)>0)
                left=middle+1;
            else
                return middle;
        }
        return -1;
    }
};

#endif // BINARYSEARCH_H
