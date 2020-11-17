#pragma once
using namespace std;
//-----Includes-----
#include <string>
#include <iostream>
#include <time.h>
#include "Data.h"
#include <list>
#include <fstream>
#include "Pessoa.h"

//-----Externs-----
extern void MSG(string Mensagem);

class Pessoa;
class Virus
{
	private:
		//-----Atributos-----

		list<Pessoa*> LP; // Lista de pessoas infetadas com este vírus
		friend class SGestao;
		friend class Pessoa;
		string Nome_Virus;
		double Raio_Contagio;
		short int Taxa_Contagio;
		short int Perigosidade;
		Data Data_Inicio;

		//----- Métodos -----
		void Mostrar_Virus();
		string Get_Nome() { return Nome_Virus; }
		void AfectarPessoa(Pessoa* P) { LP.push_back(P); } // Um vírus
	public:
		//-----Construtores e Destrutores-----
		Virus(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data data_inicio);
		virtual ~Virus();
};

