
#include "mainObject.hh"

Vector3D MainObject::Max() const
{
    Vector3D  tmp;
    double x=tmp[0]=-201; //nie ma mniejszych punktów
    double y=tmp[1]=-201;
    double z=tmp[2]=-201;
    for(int i = 0; i < points.size(); ++i)
    {
        if(points[i][0] >= x)
        {
            tmp[0] = points[i][0] +translation[0];
        }
        else if(points[i][1] >= y)
        {
            tmp[1] = points[i][1] +translation[1];
        }
        else if(points[i][2] >= z)
        {
            tmp[2] = points[i][2] + translation[2];
        }

    }
    return tmp;
}
Vector3D MainObject::Min() const
{
    Vector3D  tmp;
    double x=tmp[0]= 101; //nie ma większych punktów
    double y=tmp[1]= 101;
    double z=tmp[2]= 101;
    for(int i = 0; i < points.size(); ++i)
    {
        if(points[i][0] < x)
        {
            tmp[0] = points[i][0] +translation[0];
        }
        else if(points[i][1] < y)
        {
            tmp[1] = points[i][1] +translation[1];
        }
        else if(points[i][2] < z)
        {
            tmp[2] = points[i][2] +translation[2];
        }

    }
    return tmp;

}