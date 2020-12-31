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
		unsigned short int ContagiosProvocados;
		unsigned short int DiasQuarentena;
	public:
		//-----Construtores e Destrutores-----

		Pessoa(string nome, string bi, Cidade* cidade, unsigned short int idade, Ponto* coordenada_atual, bool ebase, unsigned short int contagiosprovocados, unsigned short int DiasQuarentena);
		virtual ~Pessoa();

		//----- Métodos -----

		void Mostrar();
		bool Run(vector<Ponto*>* Movimentos);
		void Deslocar(vector<Ponto*>* Movimentos);
		void FuiInfetado(Virus* V) { Virus_Contraidos.push_back(V);}
		int Memoria();
		bool Morrer();

		//---- Sets -----
		void set_eBaseContagio(bool estado) { eBaseContagio = estado; }
		void Set_ContagiosProvocados(int X) { ContagiosProvocados = X; }
		void Set_DiasQuarentena(unsigned short int X) { DiasQuarentena = X; }
		//----- Gets -----

		string Get_Nome() { return Nome; }
		string Get_BI() { return BI; }
		Cidade* Get_Cidade() { return CIDADE; }
		int Get_Idade() { return Idade; }
		int Get_DiasQuarentena() { return DiasQuarentena; }
		Ponto* Get_Coordenada_Atual() { return Coordenada_Atual; }
		bool Get_eBaseContagio() { return eBaseContagio; }
		int Get_ContagiosProvocados() { return ContagiosProvocados; }
		list <Virus*>* Get_Virus_Contraidos(){ return &Virus_Contraidos; }	
		int Get_Virus_Size() { return Virus_Contraidos.size(); }
};

#endif // !PESSOA__H
