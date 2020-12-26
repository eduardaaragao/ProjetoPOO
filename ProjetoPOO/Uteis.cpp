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
	int index = rand() % max;

	return index;
}

bool Uteis::CompararNomes(const string &n1, const string &n2)
{
	return (_stricmp(n1.c_str(), n2.c_str()) == 0);
}