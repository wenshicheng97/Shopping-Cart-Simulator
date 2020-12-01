#ifndef BUILDER_H
#define BUILDER_H

#include "pet.h"

#include <string>
using std::string;
#include <vector>
using std::vector;

class Builder
{
public:
    virtual void addDog(string name,string type,string price,string special)=0;
    virtual void addBird(string name,string type,string price,string special)=0;
    virtual void addCat(string name,string type,string price,string special)=0;
    virtual void addFish(string name,string type,string price,string special)=0;
    virtual void addBundle(string name,string price,vector<Pet*> vp)=0;
    virtual vector<Pet*> getList() const=0;
};

#endif // BUILDER_H
