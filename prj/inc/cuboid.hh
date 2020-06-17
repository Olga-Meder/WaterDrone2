#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "MatrixRot.hh"
#include "mainObject.hh"



const std::string kModelCuboid("solid/model.dat");

/**
 * @brief Klasa prostopadłościan, dziedziczy z MainObject
 *
 */
class Cuboid: public MainObject{

public:

    double angle=0; //kąt o jaki prostopadłościan się obrócił

/**
 * @brief Konstruktor nowych prostopadłościanów, czyta z pliku kModelCuboid
 *
 */
    Cuboid();
/**
 * @brief Destruktor nowych prostopadłościanów, odejmuje licznik
 *
 */
    ~Cuboid() {--counter;}

/**
 * @brief metoda, która zapisuje do pliku punkty po translacji
 *
 * @param filename - plik, do którego zapisujemy
 */
    virtual void draw(std::string filename) const override;

/**
 * @brief Metoda, która przesuwa o wektor change
 *
 * @param change - wektor przesunięcia
 */
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }

/**
 * @brief Metoda, która przesuwa o wektor change
 *
 * @param change - wektor przesunięcia
 */
    void rotateZ(double angle);


/**
 * @brief Metoda, która sprawdza, czy nie ma kolizcji z dnem i powierzchnią
 * (1 -kolizja z dnem 2- kolizja z powierzchnią)
 * @return int
 */
    int checkCollision();

/**
 * @brief Metoda, która sprawdza, czy nie ma kolizcji z przeszkodami
 * (1 -kolizja z przszkodą)
 * @return int
 */
    int checkObstacleCollision(MainObject &o); //MUSI BYĆ REFERENCJA BO TO KLASA ABSTRAKCYJNA

/**
* @brief Nadpisana metoda z metody czysto wirtualnej w mainObject nadająca nazwę obiektu
*
*/
    virtual void getName() const override
    {
        std::cout<< "Prostopadłościan";
    }
};


