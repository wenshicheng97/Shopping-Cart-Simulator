#ifndef BUNDLELISTPARSER_H
#define BUNDLELISTPARSER_H

#include <string>
using std::string;
#include <fstream>
using std::ifstream;

#include "builder.h"
#include "binarysearch.h"
#include "petdatabasesearchablesortbyname.h"
#include "bubblesortincreasing.h"

class BundleListParser{
protected:
    Builder* m_builder;
public:
    void setBuilder(Builder* builder){
        m_builder=builder;
    }
    void parse(PetDataBaseSearchableSortByName* pdbssbn){
        ifstream inf("Bundles.csv");
        string line;
        BinarySearch bs;
        vector<Pet*> bundles;
        while(getline(inf,line)){
            int start=0,end=line.find(",");
            string name=line.substr(0,end);
            start=end+1;
            end=line.find(",",start);
            string price=line.substr(start,end-start);
            string petname;
            start=end+1;
            vector<Pet*> vp;
            while(end!=-1){
                end=line.find(",",start);
                petname=line.substr(start,end-start);
                pdbssbn->setQuery(petname);
                int result=bs.search(pdbssbn);
                if(result!=-1)
                    vp.push_back(pdbssbn->getPet(result));
                else{
                    for(auto e:bundles){
                        if(e->getName()==petname){
                            vp.push_back(e);
                            break;
                        }
                    }
                }
                start=end+1;
            }
            m_builder->addBundle(name,price,vp);
            Bundle* b=new Bundle(name,std::stod(price),vp);
            bundles.push_back(b);
        }
        for(unsigned int i=0;i<bundles.size();i++){
            delete bundles[i];
        }
    }
};

#endif // BUNDLELISTPARSER_H
