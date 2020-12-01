#ifndef PETLISTPARSER_H
#define PETLISTPARSER_H

#include <string>
using std::string;
#include <fstream>
using std::ifstream;

#include "builder.h"

class PetListParser{
protected:
    Builder* m_builder;
public:
    void setBuilder(Builder* builder){
        m_builder=builder;
    }
    void parse(){
        ifstream inf("Pets.csv");
        string line;
        while(getline(inf,line)){
            int start,end=line.find(",");
            string c=line.substr(0,end);
            start=end+1;
            end=line.find(",",start);
            string name=line.substr(start,end-start);
            start=end+1;
            end=line.find(",",start);
            string type=line.substr(start,end-start);
            start=end+1;
            end=line.find(",",start);
            string weight=line.substr(start,end-start);
            start=end+1;
            end=line.find(",",start);
            string price=line.substr(start,end-start);
            start=end+1;
            end=line.find(",",start);
            string special=line.substr(start,end-start);
            if(c=="Dog"){
                m_builder->addDog(name,type,price,special);
            }
            if(c=="Cat"){
                m_builder->addCat(name,type,price,special);
            }
            if(c=="Bird"){
                m_builder->addBird(name,type,price,special);
            }
            if(c=="Fish"){
                m_builder->addFish(name,type,price,special);
            }
        }
    }
};

#endif // PETLISTPARSER_H
