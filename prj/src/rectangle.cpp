
#include "rectangle.hh"
#include <fstream>
#include <iostream>

using namespace std;

Rectangle::Rectangle() // wczytanie pliku modelowego
{
    ifstream inputFile;
    inputFile.open( kModelRectangle);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Rectangle file!"
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

void Rectangle::draw(std::string filename) const
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