#pragma once
#include "Virus.h"
class Paludismo :
    public Virus
{
public:
	Paludismo(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data* data_inicio);
	  ~Paludismo();

};

