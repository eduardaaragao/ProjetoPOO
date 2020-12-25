#define _CRT_SECURE_NO_WARNINGS
#include "Pessoa.h"
#include "time.h"
#include "Ponto.h"
#include "Virus.h"
#include "Uteis.h"
#include "SGestao.h"

// Inicialização de uma pessoa e geraçao de uma primeira coordenada
Pessoa::Pessoa(string nome, string bi, Cidade* cidade, unsigned short int idade, Ponto* coordenada_atual, bool ebase = false,int contagiosprovocados = 0)
{
	Nome = nome;
	BI = bi;
	CIDADE = cidade;
	Idade = idade;
	Coordenada_Atual = coordenada_atual;
	eBaseContagio = ebase;
	ContagiosProvocados = contagiosprovocados;
}

Pessoa::~Pessoa()
{
	// cout << "Passei em " << __FUNCTION__ << endl;
<<<<<<< HEAD
=======
	delete(CIDADE);
>>>>>>> 1fc1e8055da10f2a0a44b18c0823e52bff2914fe
	delete(Coordenada_Atual);
	Virus_Contraidos.clear();
}

void Pessoa::Mostrar()
{

	cout << "\nNome: [" << Nome << "]\nBI: [" << BI << "]\nCidade: [" << CIDADE->getNome() << "]\nIdade: [" << Idade << "]\nCoordenada X: [" << Coordenada_Atual->Get_X() << "]\nCoordenada Y: [" << Coordenada_Atual->Get_Y() << "]" <<endl;
	list<Virus*>:: iterator it = Virus_Contraidos.begin();
	cout << "Lista de Virus:" << endl;
	while (it!= Virus_Contraidos.end())
	{
		cout << "[" << (*it)->Get_Nome_Virus() << "]" << endl;
		++it;
	}
}

bool Pessoa::Run(vector<Ponto*>* Movimentos)
{
	//Uteis::MSG("A viver....");
	Deslocar(Movimentos);
	return true;
}

void Pessoa::Deslocar(vector<Ponto*>* Movimentos)
{

	//Uteis::MSG("A deslocar-se...\n"); //Para testar
	//cout << "Posicao atual: " << *Coordenada_Atual << endl; //Para testar
	
	int index = rand() % Movimentos->size();

	//cout << *Movimentos->at(index) << endl; //Para testar

	Ponto AUX = *Coordenada_Atual + *Movimentos->at(index);

	if (((0 <= AUX.Get_X()) && (AUX.Get_X() <= 1000) && (0 <= AUX.Get_Y()) && (AUX.Get_Y() <= 1000)))
	{
		Coordenada_Atual->Set_X(AUX.Get_X());
		Coordenada_Atual->Set_Y(AUX.Get_Y());
	}

	//cout << "Nova posicao = " << *Coordenada_Atual << endl; //Para testar
}

