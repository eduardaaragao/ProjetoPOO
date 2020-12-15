#ifndef PESSOA__H
#define PESSOA__H

#include "Ponto.h"
#include <list>
#include <vector>

class Virus;

class Pessoa
{
private:
		//-----Atributos-----
		string Nome;
		Pessoa(string nome, char* BI, string cidade, unsigned short int idade, Ponto* coordenada_atual, Virus* virus_infectado);
		char BI[10];
		string Cidade; // GUSTAVO: Mudar para apontar para elemento da lista das cidades, mudar no LOAD
		unsigned short int Idade;
		Ponto* Coordenada_Atual; 
		list <Virus*> Virus_Contraidos;
		vector<Ponto> MovimentosPossiveis;
		// bool eBaseContagio;
	public:
		//-----Construtores e Destrutores-----

		Pessoa(string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual);
		virtual ~Pessoa();

		//----- Métodos -----

		void Mostrar();
		bool Run();
		void Deslocar();
		void FuiInfetado(Virus* V) { Virus_Contraidos.push_back(V);}

		//----- Gets -----

		string Get_Nome() { return Nome; }
		char* Get_BI() { return BI; }
		string Get_Cidade() { return Cidade; }
		int Get_Idade() { return Idade; }
		Ponto* Get_Coordenada_Atual() { return Coordenada_Atual; }
		list <Virus*>* Get_Virus_Contraidos(){ return &Virus_Contraidos; }

		
};

#endif // !PESSOA__H
