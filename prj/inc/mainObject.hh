#pragma once

#include<iostream>
#include<vector>
#include "Vector.hh"

/**
 * @brief Główna klasa abstrakcyjna, służąca do dziedziczenia obiektów
 *
 */
class MainObject
{
protected:

//  wektor współrzędnych obiektów
    std::vector<Vector3D> points;
//  wektor translacji/ przemieszczenia
    Vector3D translation;

public:

//  licznik ilości narysowanych wektorów
    static int counter;

/**
 * @brief Pusty konstruktor obiektór MainObject
 *
 */
    MainObject() {};

/**
 * @brief Pusty destruktor obiektór MainObject
 *
 */
    virtual ~MainObject() {};

/**
 * @brief  czysto wirtualna metoda służąca do rysowanie obiektów
 *
 * @param filename - nazwa pliku do zapisu
 */
    virtual void draw(std::string filename) const=0;


/**
 * @brief  metoda służąca do wyliczania maksymalnych wierzchołków
 *
 * @return Vector3D
 */
    Vector3D Max() const;

/**
 * @brief  metoda służąca do wyliczania minimalnych wierzchołków
 *
 * @return Vector3D
 */
    Vector3D Min() const;

/**
* @brief Metoda czysto wirtualna nadająca nazwę obiektu
*
*/
    virtual void getName() const =0; //tak samo jak na zajęciach
};