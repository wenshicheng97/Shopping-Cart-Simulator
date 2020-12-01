#ifndef BUNDLE_H
#define BUNDLE_H

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "pet.h"

class Bundle:public Pet
{
protected:
    vector<Pet*> includes;
    double total;
public:
    Bundle(string name,double price,vector<Pet*> bundle):Pet(name,"Bundle",price){
        for(auto e:bundle){
            includes.push_back(e);
        }
        total=computeTotal();
    };
    string getClass() const{
        return "Bundle";
    }
    string getSpecial() const{
        ostringstream oss;
        double saving=(total-m_price)/total;
        oss<<int(saving*100+0.5)<<'%';
        return oss.str();
    }
    //double getTotal() const{return total;}
    void addPet(Pet* pet);
    Pet* getPet(int i){return includes[i];}
    double computeTotal();
    unsigned int getSize() const;
    void Accept(Visitor *v);
};

#endif // BUNDLE_H
