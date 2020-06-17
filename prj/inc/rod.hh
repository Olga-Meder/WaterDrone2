#pragma once

#include "obstacle.hh"
#include <string>

const std::string kModelRod("solid/rod.dat");

/**
 * @brief Klasa pręt, dziedziczy z Obstacle
 *
 */
class Rod: public Obstacle
{
public:
/**
* @brief Konstruktor nowych prętów, czyta z pliku kModelRod
*
*/
    Rod();

/**
 * @brief Destruktor nowych prętów
 *
 */
    virtual ~Rod() {};

/**
* @brief Nadpisana metoda z metody czysto wirtualnej w mainObject nadająca nazwę obiektu
*
*/
    virtual void getName() const override
    {
        std::cout<< "Pręt";
    }

/**
 * @brief metoda, która zapisuje do pliku punkty przeszkody
 *
 * @param filename - plik, do którego zapisujemy
 */
    virtual void draw(std::string filename) const override;
};