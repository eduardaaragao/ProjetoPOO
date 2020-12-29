#ifndef PESSOA__H
#define PESSOA__H
#include "Cidade.h"
#include "Ponto.h"
#include <list>
#include <vector>

class Virus;

class Pessoa
{
private:
		//-----Atributos-----
		string Nome;
		string BI;
		Cidade* CIDADE; 
		unsigned short int Idade;
		Ponto* Coordenada_Atual; 
		list <Virus*> Virus_Contraidos;
		bool eBaseContagio;
		int ContagiosProvocados;
	public:
		//-----Construtores e Destrutores-----

		Pessoa(string nome, string bi, Cidade* cidade, unsigned short int idade, Ponto* coordenada_atual, bool ebase, int contagiosprovocados);
		virtual ~Pessoa();

		//----- Métodos -----

		void Mostrar();
		bool Run(vector<Ponto*>* Movimentos);
		void Deslocar(vector<Ponto*>* Movimentos);
		void FuiInfetado(Virus* V) { Virus_Contraidos.push_back(V);}
		int Memoria();

		//---- Sets -----
		void set_eBaseContagio(bool estado) { eBaseContagio = estado; }
		void Set_ContagiosProvocados(int X) { ContagiosProvocados = X; }
		//----- Gets -----

		string Get_Nome() { return Nome; }
		string Get_BI() { return BI; }
		Cidade* Get_Cidade() { return CIDADE; }
		int Get_Idade() { return Idade; }
		Ponto* Get_Coordenada_Atual() { return Coordenada_Atual; }
		bool Get_eBaseContagio() { return eBaseContagio; }
		int Get_ContagiosProvocados() { return ContagiosProvocados; }
		list <Virus*>* Get_Virus_Contraidos(){ return &Virus_Contraidos; }	
		int Get_Virus_Size() { return Virus_Contraidos.size(); }
};

#endif // !PESSOA__H
