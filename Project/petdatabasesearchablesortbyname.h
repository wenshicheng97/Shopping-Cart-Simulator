#ifndef PETDATABASESEARCHABLESORTBYNAME_H
#define PETDATABASESEARCHABLESORTBYNAME_H

#include <vector>
using std::vector;
#include <string>
using std::string;

#include "petdatabasesortable.h"

class PetDataBaseSearchableSortByName:public PetDataBaseSortable
{
protected:
    vector<Pet*> PetVector;
    string query;
public:
    PetDataBaseSearchableSortByName(vector<Pet*> petVector){
        for(auto e:petVector){
            PetVector.push_back(e);
        }
    }
    ~PetDataBaseSearchableSortByName(){
        PetVector.clear();
        PetVector.shrink_to_fit();
    }

    void setQuery(string q){
        query=q;
    }
    int compareAt(int i) const{
        //return strcmp(query,PetVector[i]->getName().c_str());
        if(query<PetVector[i]->getName())return -1;
        else if(query>PetVector[i]->getName())return 1;
        else return 0;
    }
    bool smaller(int i, int j) const{
        return PetVector[i]->getName()<PetVector[j]->getName();
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

#endif // PETDATABASESEARCHABLESORTBYNAME_H
