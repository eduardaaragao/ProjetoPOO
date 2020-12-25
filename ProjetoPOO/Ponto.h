#ifndef PONTO_H
#define PONTO_H
using namespace std;
#include <time.h>
#include <iostream>
#include <stdlib.h>

class Ponto
{
    int X, Y;
public:
    Ponto(int x = rand() % 1000, int y = rand() % 1000);
    virtual ~Ponto();

    //----- Getters -----

    int Get_X() { return X; }
    int Get_Y() { return Y; }
    //----- Seters -----
    void Set_X(int x) { X = x; }
    void Set_Y(int y) { Y = y; }
    //----- Operator Overloading ------
    Ponto operator+(const Ponto& P);
    friend ostream& operator<<(ostream& os, const Ponto& P);
};

#endif // PONTO_H

