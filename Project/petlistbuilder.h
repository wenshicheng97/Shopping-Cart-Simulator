#ifndef PETLISTBUILDER_H
#define PETLISTBUILDER_H

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "builder.h"
#include "pet.h"
#include "bird.h"
#include "cat.h"
#include "dog.h"
#include "fish.h"
#include "bundle.h"

class PetListBuilder:public Builder
{
protected:
    vector<Pet*> pet_list;
public:
    void addBird(string name,string type,string price,string special){
        bool nocturnality;
        if(special=="TRUE"){
            nocturnality=true;
        }
        else{
            nocturnality=false;
        }
        Bird* bird=new Bird(name,type,std::stod(price),nocturnality);
        pet_list.push_back(bird);
    }
    void addCat(string name,string type,string price,string special){
        bool fluffy;
        if(special=="TRUE"){
            fluffy=true;
        }
        else{
            fluffy=false;
        }
        Cat* cat=new Cat(name,type,std::stod(price),fluffy);
        pet_list.push_back(cat);
    }
    void addDog(string name,string type,string price,string special){
        Dog* dog=new Dog(name,type,std::stod(price),special);
        pet_list.push_back(dog);
    }
    void addFish(string name,string type,string price,string special){
        Fish* fish=new Fish(name,type,std::stod(price),special);
        pet_list.push_back(fish);
    }
    void addBundle(string name,string price,vector<Pet*> vp){
        Bundle* bundle=new Bundle(name,std::stod(price),vp);
        pet_list.push_back(bundle);
    }
    vector<Pet*> getList() const{
        return pet_list;
    }
};

#endif // PETLISTBUILDER_H
