#pragma once

#include "obstacle.hh"
#include <string>

const std::string kModelSolid("solid/solid.dat");

/**
 * @brief Klasa bryła, dziedziczy z Obstacle
 *
 */
class Solid: public Obstacle
{

public:
/**
 * @brief Konstruktor nowych brył, czyta z pliku kModelSolid
 *
 */
    Solid();

/**
 * @brief Destruktor nowych prostokątów
 *
 */
    virtual ~Solid() {};

/**
* @brief Nadpisana metoda z metody czysto wirtualnej w mainObject nadająca nazwę obiektu
*
*/
    virtual void getName() const override
    {
        std::cout<< "Bryła";
    }

/**
 * @brief metoda, która zapisuje do pliku punkty przeszkody
 *
 * @param filename - plik, do którego zapisujemy
 */
    virtual void draw(std::string filename) const override;
};