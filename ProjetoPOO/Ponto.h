#ifndef PONTO_H
#define PONTO_H
using namespace std;
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

class Ponto
{
    int X, Y;

public:
    Ponto()
    {
        X = rand() % 1000;
        Y = rand() % 1000;
    }
    Ponto(int x, int y);
    virtual ~Ponto();
    bool EstaNoRaio(Ponto* P, double Raio);
    //----- Getters -----

    int Get_X() { return X; }
    int Get_Y() { return Y; }
    //----- Seters -----
    void Set_X(int x) { X = x; }
    void Set_Y(int y) { Y = y; }
    //----- Operator Overloading ------
    Ponto operator+(const Ponto& P);
    bool operator==(const Ponto& P);
    bool operator!=(const Ponto& P);
    bool operator>(const Ponto& P);
    friend ostream& operator<<(ostream& os, const Ponto& P);
};

#endif // PONTO_H

