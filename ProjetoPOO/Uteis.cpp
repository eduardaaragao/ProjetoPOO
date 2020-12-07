#include <iostream>
#include "Ponto.h"
#include "Pessoa.h"
#include <time.h> 
#include <stdlib.h>
#include "Uteis.h"
using namespace std;

Uteis::Uteis()
{}


Uteis::~Uteis()
{}

void Uteis::MSG(string msg)
{
	cout << msg << endl;
}

int Uteis:: GetPosicaoAleatoria(int max)
{
	int index;
	return index = rand() % max;
}