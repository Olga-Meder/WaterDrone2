#pragma once

#include "mainObject.hh"
#include <string>

using std::string;


/**
 * @brief Klasa abstrakcyjna przeszkoda, dziedziczy z MainObject
 *
 */
class Obstacle: public MainObject
{

public:

/**
 * @brief Destruktor przeszkody
 *
 */
    virtual ~Obstacle() {};

/**
* @brief Metoda czysto wirtualna nadająca nazwę obiektu
*
*/
    virtual void getName() const =0;
};
