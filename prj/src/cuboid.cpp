#include "cuboid.hh"
#include <fstream>
#include <iostream>
#include "bottom.hh"
#include "water.hh"
using namespace std;

int MainObject::counter =0;

Cuboid::Cuboid() // wczytanie pliku modelowego
{
    ifstream inputFile;
    inputFile.open(kModelCuboid);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Cuboid file!" 
             << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        points.push_back(point); //tutaj points
        ++counter; //dodawanie wektorów
    }
    inputFile.close();
}


void Cuboid::draw(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open drone file!" << endl;
        return;
    }
    for(int i = 0; i < points.size(); ++i)
    {
        outputFile << points[i]+ translation;
        if(i % 4 == 3) // triggers after every 4 points
        {
            outputFile << "#\n\n";
        }
    }
}

void Cuboid::rotateZ(double angle)
{

    MatrixRot rot_matrix('Z',angle);
    rot_matrix.transpose(); //w szablonie zapisuje macierz transponowaną, tutaj muszę odwrócić
    for (int i = 0; i < points.size(); ++i)
    {
        points[i] = rot_matrix * points[i];
    }
}

int Cuboid::checkCollision()
{
    Bottom b;
    Water w;
    int result;
    if (translation[2] <= b.getDepth()+20) //te punkty wyznaczone doświadczalnie
    {
        result=1;
        return result;
    }
    else if(translation[2]>= w.getHeight()-5)
    {
        result=2;
        return result;
    }
}

int Cuboid::checkObstacleCollision(MainObject &o)
{
    Vector3D obstacleMax = o.Max();
    Vector3D obstacleMin = o.Min();
    Vector3D cuboidMax = this->Max();
    Vector3D cuboidMin = this->Min();
    int result;

//  Sprawdzanie czy przeszkoda i prostopadłośćian nachodzą na siebie poprzez maksymalne i minimalne wierzchołki
    if((cuboidMin[0] < obstacleMax[0] && cuboidMax[0] > obstacleMin[0]) &&
       (cuboidMax[1] > obstacleMin[1] && cuboidMin[1] < obstacleMax[1] ) &&
       (cuboidMin[2] < obstacleMax[2] && cuboidMax[2] > obstacleMin[2]))
    {
        result=1;
        return result;
    }
}

