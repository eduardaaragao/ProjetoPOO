#pragma once
using namespace std;
#include <time.h> 
#include <iostream>
#include <stdlib.h>


class Ponto
{
	private:

		//----- Variaveis -----
		
		int X, Y;
	
	public:
		//Construtores e destrutores são públicos

		Ponto(int x = rand() % 1000, int y = rand() % 1000);
		virtual ~Ponto();
		//----- Métodos -----
		
		
		//----- Getters -----

		int Get_X() { return X; }
		int Get_Y() { return Y; }
};

