#ifndef PET_H
#define PET_H

#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <iomanip>
using std::fixed;
using std::setprecision;

#include "visitor.h"

class Pet
{
protected:
    string m_name;
    double m_price;
    string m_type;
public:
    Pet(string name,string t,double price):m_name(name),m_price(price),m_type(t){};
    virtual ~Pet(){};
    virtual void Accept(Visitor*)=0;
    string getName() const;
    void setName(string name);
    double getPrice() const;
    string displayPrice() const;
    void setPrice(double price);
    string getType() const;
    void setType(string type);
    virtual string getClass() const=0;
    virtual string getSpecial() const=0;

};

#endif // PET_H
