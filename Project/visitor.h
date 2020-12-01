#ifndef VISITOR_H
#define VISITOR_H

class Dog;
class Cat;
class Fish;
class Bird;
class Bundle;

class Visitor
{
public:
    Visitor(){};
    virtual ~Visitor(){};
    virtual void VisitDog(Dog*)=0;
    virtual void VisitCat(Cat*)=0;
    virtual void VisitFish(Fish*)=0;
    virtual void VisitBird(Bird*)=0;
    virtual void VisitBundle(Bundle*)=0;
};

#endif // VISITOR_H
