#pragma once
#include "Virus.h"
#include "Ponto.h"
#include <list>

class Pessoa
{
	private:
		//-----Atributos-----
		list<Virus*> ListaVirus;
		friend class SGestao;
		string Nome;
		char *BI;
		string Cidade;
		unsigned short int Idade;
		Ponto* Coordenada_Atual;

		//-----Métodos-----
		Pessoa(string nome, char* BI, string cidade, unsigned short int idade, Ponto* coordenada_atual, Virus* virus_infectado);
		virtual ~Pessoa();
		void Mostrar();
		bool Run();
		void Deslocar();
	public:

};

