#pragma once

#include "mainObject.hh"
#include <string>

using std::string;

class Obstacle: public MainObject
{
    //klasa przeszkód (absrakcyjna) z funkcją nazw tych przeszkód (metoda czysto wirtualna)
public:

    virtual ~Obstacle() {}; //wirtualny destruktor
    virtual void getName() const =0; //tak samo jak na zajęciach

};
