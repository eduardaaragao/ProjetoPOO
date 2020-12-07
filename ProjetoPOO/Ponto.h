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
    Ponto(short int x, short int y);
    virtual ~Ponto();

    //----- Getters -----

    int Get_X() { return X; }
    int Get_Y() { return Y; }

    //----- Operator Overloading ------
    Ponto operator+(const Ponto& P);
    friend ostream& operator<<(ostream& os, const Ponto& P);
};

#endif // PONTO_H

