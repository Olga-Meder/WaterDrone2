#pragma once

#include "obstacle.hh"
#include <string>
#include <iostream>

const std::string kModelRectangle("solid/rectangle.dat");

class Rectangle: public Obstacle
{
    //klasa prostokąt, która ma za zadanie zostać nazwana i narysowana (później kolizja)
public:

    Rectangle();

    virtual ~Rectangle() {}; //wszystko virtual, bo dziedziczymy z klasy abstrakcyjnej

    virtual void getName() const override
    {
      std::cout<<"Prostokąt";
    }

    virtual void draw(std::string filename) const override;

};