#include "Virus.h"
#include"Pessoa.h"
Virus::Virus(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data* data_inicio)
{
	// cout << "Passei em " << __FUNCTION__ << endl;
	Nome_Virus = nome;
	Raio_Contagio = raio_contagio;
	Taxa_Contagio = taxa_contagio;
	Perigosidade = perigosidade;
	Data_Inicio = data_inicio;
}

Virus::~Virus()
{
	// cout << "Passei em " << __FUNCTION__ << endl;
}

void Virus::Mostrar_Virus()
{
	cout << "\nNome: [" << Nome_Virus << "]\nRaio: [" << Raio_Contagio << "]\nTaxa de Contagio: [" << Taxa_Contagio << "]\nPerigosidade: [" << Perigosidade << "]\nData de Inicio: [" << Data_Inicio->Get_Dia() << "/" << Data_Inicio->Get_Mes() << "/" << Data_Inicio->Get_Ano() << "]" << endl;
}

void Virus::Infectar_Pessoa(Pessoa* pessoa)
{
	pessoa->Get_Virus_Contraidos()->push_back(this);
}
