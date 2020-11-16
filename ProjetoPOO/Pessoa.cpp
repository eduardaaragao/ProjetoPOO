#include "Pessoa.h"
#include"time.h"
#include"Ponto.h"

// Inicializaçaõ de uma pessoa e geraçao de uma primeira coordenada
Pessoa::Pessoa(string nome, char* bi, string cidade, unsigned short int idade)
{
	// cout << "Passei em " << __FUNCTION__ << endl;
	Nome = nome;	
	BI = bi;
	Cidade = cidade;
	Idade = idade;
	Ponto* cord_inicial;
	cord_inicial = new Ponto((0 + rand() % (1000 + 1)), (0 + rand() % (1000 + 1)));
	
	
}

Pessoa::~Pessoa()
{
	// cout << "Passei em " << __FUNCTION__ << endl;
}

void Pessoa::DadosPessoa(string nome, char* bi, string cidade, unsigned short int idade, int x, int y, list<Virus*>virus)
{
	Nome = nome;
	BI = bi;
	Cidade = cidade;
	Idade = idade;
	Ponto* cord;
	cord = new Ponto(x, y);
	list<Virus*> ::iterator i;
	i = virus.begin();
	
	while (i != virus.end())
	{
		ListaVirus.push_back((*i));
	}
}

void Pessoa::Mostrar()
{

	cout << "\nNome: [" << Nome << "]\nBI: [" << BI << "]\nCidade: [" << Cidade << "]\nIdade: [" << Idade << "]\nCoordenada X: [" << Coordenada_Atual->X << "]\nCoordenada Y: [" << Coordenada_Atual->Y << "]" <<endl;
	list<Virus*>:: iterator it = ListaVirus.begin();
	cout << "Lista de Virus:" << endl;
	while (it!= ListaVirus.end())
	{
		cout << "[" << (*it)->Get_Nome() << "]" << endl;
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
	Coordenada_Atual->X += 1;
	Coordenada_Atual->Y += 1;
}