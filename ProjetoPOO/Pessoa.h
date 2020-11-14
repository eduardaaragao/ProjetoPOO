#pragma once
#include "Virus.h"
#include "Ponto.h"

class Pessoa
{
	private:
		friend class SGestao;
		//-----Variaveis-----
		string Nome;
		char* BI;
		string Cidade;
		unsigned short int Idade;
		Ponto* Coordenada_Atual;
		list<Virus*> Virus_Infectados;
		//-----Funcoes-----
		Pessoa(string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual, Virus* virus_infectado);
		virtual ~Pessoa();
		void Mostrar_Pessoa();
	public:

};

