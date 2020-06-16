#pragma once

#include "obstacle.hh"
#include <string>

const std::string kModelSolid("solid/model.dat"); //zmienić to później na inny prostopadłościan
class Solid: public Obstacle
{
    //klasa bryła, która ma za zadanie zostać nazwana i narysowana (później kolizja)
public:
    Solid();
    virtual ~Solid() {};
    virtual void getName() const override
    {
        std::cout<< "Bryła";
    }
    virtual void draw(std::string filename) const override;
};