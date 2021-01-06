#pragma once
#include "Virus.h"
class Ebola :
    public Virus
{
public:
    Ebola(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, short int taxa_cura, Data* data_inicio);
    ~Ebola();
};

