#ifndef PESSOA__H
#define PESSOA__H

#include "Virus.h"
#include "Ponto.h"
#include<list>

class Pessoa
{
	private:
		//-----Atributos-----
		list<Virus*> ListaVirus;
		friend class SGestao;
		string Nome;
		char* BI;
		string Cidade;
		unsigned short int Idade;
		Ponto* Coordenada_Atual; 

		//-----Métodos-----
		Pessoa(string nome, char* bi, string cidade, unsigned short int idade); // se pessoa acabou de ser criada
		void DadosPessoa(string nome, char* bi, string cidade, unsigned short int idade, int x, int y, list<Virus*>virus);
		virtual ~Pessoa();
		void Mostrar();
		bool Run();
		void Deslocar();
	public:

};

#endif // !PESSOA__H
