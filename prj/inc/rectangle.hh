#pragma once

#include "obstacle.hh"
#include <string>
#include <iostream>

const std::string kModelRectangle("solid/rectangle.dat");

/**
 * @brief Klasa prostokąt, dziedziczy z Obstacle
 *
 */
class Rectangle: public Obstacle
{

public:
/**
 * @brief Konstruktor nowych prostokątów, czyta z pliku kModelRectangle
 *
 */
    Rectangle();

/**
 * @brief Destruktor nowych prostokątów
 *
 */
    virtual ~Rectangle() {}; //wszystko virtual, bo dziedziczymy z klasy abstrakcyjnej

/**
* @brief Nadpisana metoda z metody czysto wirtualnej w mainObject nadająca nazwę obiektu
*
*/
    virtual void getName() const override
    {
      std::cout<<"Prostokąt";
    }

/**
 * @brief metoda, która zapisuje do pliku punkty przeszkody
 *
 * @param filename - plik, do którego zapisujemy
 */
    virtual void draw(std::string filename) const override;

};