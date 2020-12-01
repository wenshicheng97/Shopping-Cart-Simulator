#include "pet.h"

string Pet::getName() const{
    return m_name;
}

double Pet::getPrice() const{
    return m_price;
}

string Pet::displayPrice() const{
    ostringstream oss;
    oss<<fixed<<setprecision(2)<<m_price;
    return oss.str();
}

string Pet::getType() const{
    return m_type;
}

void Pet::setName(std::string name){
    m_name=name;
}

void Pet::setPrice(double price){
    m_price=price;
}

void Pet::setType(std::string type){
    m_type=type;
}
