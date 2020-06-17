#include <iostream>
#include <string>
#include "gnuplot_link.hh"
#include "cuboid.hh"
#include"water.hh"
#include <chrono>
#include <thread>
#include"bottom.hh"
#include <cmath>
#include "mainObject.hh"
#include "Vector.hh"
#include "rod.hh"
#include "rectangle.hh"
#include "solid.hh"

constexpr int SLEEP= 10000000; //stała potrzebna do funkcji sleep_for
constexpr int FRAME=50; //ilość klatek poczas animacji
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

const string kDroneFile("solid/drone.dat");
const string kWaterFile("solid/water2.dat");
const string kBottomFile("solid/bottom2.dat");
const string kRodFile("solid/rod2.dat");
const string kRectangleFile("solid/rectangle2.dat");
const string kSolidFile("solid/solid2.dat");
int main()
{
//  STWORZONE NOWE OBIEKTY
    Cuboid cuboid;
    Water water;
    Bottom bottom;

    PzG::GnuplotLink link; // Ta zmienna jest potrzebna do wizualizacji

//  INICJACJA
    link.Init();

//  DODANIE WSZYSTKICH PLIKÓW
    link.AddFilename(kDroneFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kWaterFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kBottomFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kRodFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kRectangleFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kSolidFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.SetDrawingMode(PzG::DM_3D);

//  ZAPISANIE PUNKTÓW DO PLIKÓW
    cuboid.draw(kDroneFile);
    water.draw(kWaterFile);
    bottom.draw(kBottomFile);

//  WSKAŹNIKI NA PRZESZKODY
    shared_ptr<MainObject> r = make_shared<Rod>(); //wskaźnik na pręt (rod)
    shared_ptr<MainObject> rec = make_shared<Rectangle>(); //wskaźnik na prostokąt (rectangle)
    shared_ptr<MainObject> s = make_shared<Solid>(); //wskaźnik na bryłę (solid)

//  RYSOWANIE PRZESZKÓD
    r->draw(kRodFile);
    rec->draw(kRectangleFile);
    s->draw(kSolidFile);

//  WEKTOR SHARED POINTERÓW
    vector<shared_ptr<MainObject>> obstacles; // lista wskaźników na przeszkody

//  DODANIE WEKTORÓW DO LISTY
    obstacles.push_back(r);
    obstacles.push_back(rec);
    obstacles.push_back(s);

    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
    cin.ignore(100000, '\n');


    /*****************************************************************************************
     * MENU
     */
    char choice; //wybór w menu
    double a; //wybór kąta
    double angle_rot; //wybór kąta rotacji
    double distance=1; //dystans do pokonania

    do
    {
        cout << "MENU:" << endl;
        cout << "o - obrót wokół osi " << endl;
        cout<< "r - ruch" << endl;
        cout<< "k - koniec" << endl;

        cin >> choice;

        if(choice=='o')
        {
            cout << "Podaj obrót w stopniach: " << endl;
            cin >> angle_rot;
            cuboid.angle += angle_rot; //przypisanie do kąta globalnego

//          PĘTLA TWORZĄCA ANIMACJĘ
            for(int i=0;i<FRAME;i++)
            {
                cuboid.rotateZ(angle_rot/FRAME);
                sleep_for(nanoseconds(SLEEP));
                cuboid.draw(kDroneFile);
                link.Draw();
            }

        }
        else if(choice=='r')
        {
            cout << "Podaj odległość " << endl;
            cin >> distance;
            cout << "Podaj kąt wznoszenia/opadania w stopniach" << endl;
            cin >> a;
            double rad=a*M_PI/180; //zamiana na radiany
            Vector3D change; //wektor zmiany przesunięcia
            MatrixRot rot('Z',angle_rot);
            change[0]=distance*cos(rad); //współrzędne kartezjańskie
            change[1]=0;
            change[2]=distance*sin(rad);
            change= rot*change;

//          PĘTLA TWORZĄCA ANIMACJĘ
            for(int i=0;i<FRAME;i++)
            {
                int check=0; //zmienna służąca do sprawdzenia kolizji
                cuboid.translate(change/FRAME); //translacja
                sleep_for(nanoseconds(SLEEP));
                cuboid.draw(kDroneFile);
                link.Draw();
//              SPRAWDZANIE KOLIZJI
                if(cuboid.checkCollision()==1)
                {
                    cerr <<"Uwaga, jesteś na dnie" <<endl;
                    distance=0;
                }
                else if(cuboid.checkCollision()==2)
                {
                    cerr << "Uwaga, jesteś na powierzchni" << endl;
                    distance=0;
                }
//              SPRAWDZENIE KOLIZJI Z PRZESZKODAMI

                for(int j=0; j<obstacles.size(); j++) //pętla z przeszkodami
                {
                    check = cuboid.checkObstacleCollision(*obstacles[j]); //wywołanie sprawdzenia kolizji
                    if(check == 1)
                    {
                        cout<< "Uwaga ";
                        obstacles[j]->getName();
                    }
                }


            }
        }
        else if(choice=='k')
        {
            cout<<"Koniec programu"<< endl;
            return 0;
        }
        else
        {
            cout<<"Błędny wybór, spróbuj ponownie"<<endl;
            MainObject::counter =0;
        }


    } while (choice != 'k');


    return 0;

}
