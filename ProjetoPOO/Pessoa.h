#ifndef PESSOA__H
#define PESSOA__H

#include "Virus.h"
#include "Ponto.h"
#include<list>

class Pessoa
{
	private:
		//-----Atributos-----
		string Nome;
		char BI[10];
		string Cidade;
		unsigned short int Idade;
		Ponto* Coordenada_Atual; 
		list <Virus*> Virus_Contraidos;

	public:
		//-----Construtores e Destrutores-----

		Pessoa(string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual);
		virtual ~Pessoa();

		//----- Métodos -----

		void Mostrar();
		bool Run();
		void Deslocar();

		//----- Gets -----

		string Get_Nome() { return Nome; }
		char* Get_BI() { return BI; }
		string Get_Cidade() { return Cidade; }
		int Get_Idade() { return Idade; }
		Ponto* Get_Coordenada_Atual() { return Coordenada_Atual; }
		list <Virus*>* Get_Virus_Contraidos(){ return &Virus_Contraidos; }
		

};

#endif // !PESSOA__H
