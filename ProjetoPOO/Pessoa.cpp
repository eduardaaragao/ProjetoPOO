#define _CRT_SECURE_NO_WARNINGS
#include "Pessoa.h"
#include "time.h"
#include "Ponto.h"
#include "Virus.h"
#include "Uteis.h"

// Inicialização de uma pessoa e geraçao de uma primeira coordenada
Pessoa::Pessoa(string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual)
{
	Nome = nome;
	strcpy(BI, bi);
	Cidade = cidade;
	Idade = idade;
	Coordenada_Atual = coordenada_atual;

	MovimentosPossiveis.push_back(Ponto(-1, 0));
	MovimentosPossiveis.push_back(Ponto(1, 0));
	MovimentosPossiveis.push_back(Ponto(0, 1));
	MovimentosPossiveis.push_back(Ponto(0, -1));

	for (int i = 0; i < 4; i++)
	{
		MovimentosPossiveis.push_back(Ponto(0, 0));
	}
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
	//Uteis::MSG("A viver....");
	Deslocar();
	return true;
}

void Pessoa::Deslocar()
{
	//Uteis::MSG("A deslocar-se...");
	//cout << "Posicao atual: " << *Coordenada_Atual << endl;

	int index = rand() % MovimentosPossiveis.size();

	*Coordenada_Atual = *Coordenada_Atual + MovimentosPossiveis[index];
	//cout << "Nova posicao = " << *Coordenada_Atual << endl;
}

