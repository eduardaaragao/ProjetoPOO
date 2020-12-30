#ifndef VIRUS__H
#define VIRUS__H

using namespace std;
//-----Includes-----
#include <string>
#include <iostream>
#include <time.h>
#include "Data.h"
#include <list>
#include <fstream>

class Pessoa;
class Virus
{
	private:
		//-----Atributos-----

		string Nome_Virus;
		double Raio_Contagio;
		short int Taxa_Contagio;
		short int Perigosidade;
		Data* Data_Inicio;
		list<Pessoa*> LP; // Lista de pessoas infetadas com este vírus
	public:

		//-----Construtores e Destrutores-----

		Virus(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data* data_inicio);
		virtual ~Virus();

		//----- Métodos -----

		void Mostrar();
		void AfectarPessoa(Pessoa* pessoa);
		int Memoria();
		//----- Gets -----
		string Get_Nome_Virus() { return Nome_Virus; }
		double Get_Raio_Contagio() { return Raio_Contagio; }
		short int Get_Taxa_Contagio() { return Taxa_Contagio; }
		short int Get_Perigosidade() { return Perigosidade; }
		Data* Get_Data_Inicio() { return Data_Inicio; }
		list<Pessoa*>* Get_LP() { return &LP; }
		bool operator==(Virus* V)
		{
			return Nome_Virus == V->Get_Nome_Virus();
		}
};

#endif // !VIRUS__H