#pragma once
using namespace std;
//-----Includes-----
#include <string>
#include <iostream>
#include <time.h>
#include "Data.h"
#include <list>
#include <fstream>

//-----Externs-----
extern void MSG(string Mensagem);

class Virus
{
	private:
		friend class SGestao;
		friend class Pessoa;
		//-----Variaveis-----
		string Nome_Virus;
		double Raio_Contagio;
		short int Taxa_Contagio;
		short int Perigosidade;
		Data Data_Inicio;
		//-----Funcoes-----
		string Get_Nome() { return Nome_Virus; }

		Virus(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data data_inicio);
		virtual ~Virus();

		void Mostrar_Virus();
	public:
	
};

