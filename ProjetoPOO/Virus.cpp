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

void Virus::Mostrar()
{
	cout << "\nNome: [" << Nome_Virus << "]\nRaio: [" << Raio_Contagio << "]\nTaxa de Contagio: [" << Taxa_Contagio << "]\nPerigosidade: [" << Perigosidade << "]\nData de Inicio: [" << Data_Inicio->Get_Dia() << "/" << Data_Inicio->Get_Mes() << "/" << Data_Inicio->Get_Ano() << "]" << "\nPessoas Infetadas: " << LP.size() << endl;
}

void Virus::AfectarPessoa(Pessoa* P)
{
	LP.push_back(P);
}

int Virus::Contar_Virus(Virus* X) 
{
	if (Get_Nome_Virus() == X->Get_Nome_Virus())
		return 1;
	return 0;
}