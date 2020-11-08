#pragma once
#include "Virus.h"

class Pessoa
{
	private:
		friend class SGestao;
		//-----Variaveis-----
		string Nome;
		char* BI;
		string Cidade;
		unsigned short int Idade;
		unsigned short int Coordenada_X, Coordenada_Y;
		Virus* Virus_Infectado;
		//-----Funcoes-----
		Pessoa(string nome, char* bi, string cidade, unsigned short int idade, unsigned short int coordenada_x, unsigned short int coordenada_y, Virus* virus_infectado);
		virtual ~Pessoa();
		void Mostrar_Pessoa();
	public:

};

