#include "Ponto.h"

Ponto::Ponto(int _x, int _y)
{
    X = _x;
    Y = _y;
    //ctor
}

Ponto::Ponto(short int _x, short int _y)
{
    X = _x;
    Y = _y;
    //ctor
}

Ponto::~Ponto()
{
    //dtor
}

Ponto Ponto::operator+(const Ponto& P)
{
    Ponto Aux;
    Aux.X = this->X + P.X;
    Aux.Y = this->Y + P.Y;

    return Aux;
}

ostream& operator<<(ostream& os, const Ponto& P)
{
    os << "X = " << P.X << " Y = " << P.Y << endl;
    return os;
}