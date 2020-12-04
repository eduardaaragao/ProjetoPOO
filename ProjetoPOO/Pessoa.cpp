#define _CRT_SECURE_NO_WARNINGS
#include "Pessoa.h"
#include "time.h"
#include "Ponto.h"
#include "Virus.h"

// Inicialização de uma pessoa e geraçao de uma primeira coordenada
Pessoa::Pessoa(string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual)
{
	// cout << "Passei em " << __FUNCTION__ << endl;
	Nome = nome;
	strcpy(BI, bi);
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

int Pessoa::escalaoIdade(int Idade)
{
	if (Idade < 10)
		return 0;
	if (Idade >= 10 && Idade < 20)
		return 1;
	if (Idade >= 20 && Idade < 30)
		return 2;
	if (Idade >= 30 && Idade < 40)
		return 3;
	if (Idade >= 40 && Idade < 50)
		return 4;
	if (Idade >= 50 && Idade < 60)
		return 5;
	if (Idade >= 60 && Idade < 70)
		return 6;
	if (Idade >= 70 && Idade < 80)
		return 7;
	if (Idade >= 80 && Idade < 90)
		return 8;
	if (Idade >= 90)
		return 8;

}
