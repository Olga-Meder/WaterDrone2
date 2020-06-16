#pragma once

#include "obstacle.hh"
#include <string>

const std::string kModelRod("solid/rod.dat");

class Rod: public Obstacle
{
public:

    // klasa pręt, która ma za zadanie zostać nazwana i narysowana (później kolizja)

    Rod();
    virtual ~Rod() {};

    virtual void getName() const override
    {
        std::cout<< "Pręt";
    }

    virtual void draw(std::string filename) const override;
};