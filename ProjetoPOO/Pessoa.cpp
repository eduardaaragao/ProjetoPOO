#define _CRT_SECURE_NO_WARNINGS
#include "Pessoa.h"
#include"time.h"
#include"Ponto.h"

// Inicializaçaõ de uma pessoa e geraçao de uma primeira coordenada
Pessoa::Pessoa(string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual)
{
	// cout << "Passei em " << __FUNCTION__ << endl;
	Nome = nome;	
	strcpy(BI,bi);
	Cidade = cidade;
	Idade = idade;
	Coordenada_Atual = coordenada_atual;
}

Pessoa::~Pessoa()
{
	// cout << "Passei em " << __FUNCTION__ << endl;
}

void Pessoa::Mostrar()
{

	cout << "\nNome: [" << Nome << "]\nBI: [" << BI << "]\nCidade: [" << Cidade << "]\nIdade: [" << Idade << "]\nCoordenada X: [" << Coordenada_Atual->Get_X() << "]\nCoordenada Y: [" << Coordenada_Atual->Get_Y() << "]" <<endl;
	list<Virus*>:: iterator it = Virus_Contraidos.begin();
	cout << "Lista de Virus:" << endl;
	while (it!= Virus_Contraidos.end())
	{
		cout << "[" << (*it)->Get_Nome_Virus() << "]" << endl;
		++it;
	}
}

bool Pessoa::Run()
{
	cout << "A viver" << endl;
	Deslocar();
	return true;
}

void Pessoa::Deslocar()
{
	/*Coordenada tem de ser + ou - 1 e tem de add condição para não ultrapassar os limites*/
	
	//Coordenada_Atual->X += 1;
	//Coordenada_Atual->Y += 1;
}