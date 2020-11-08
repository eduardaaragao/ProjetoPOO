#pragma once
using namespace std;
//-----Includes-----
#include <string>
#include <iostream>
#include <time.h>
#include "Data.h"
#include <list>
#include <fstream>

//-----Exerterns-----
extern void MSG(string Mensagem);

class Virus
{
	private:
		friend class SGestao;
		friend class Pessoa;
		//-----Variaveis-----
		string Nome;
		short int Raio_Contagio;
		short int Taxa_Contagio;
		short int Perigosidade;
		Data Data_Inicio;
		//-----Funcoes-----
		Virus(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data data_inicio);
		virtual ~Virus();
		void Mostrar_Virus();
		string Get_Nome() { return Nome; }
	public:
	
	
};

