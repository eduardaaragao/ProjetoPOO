#include "Virus.h"

Virus::Virus(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data data_inicio)
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
	cout << "\nNome: [" << Nome_Virus << "]\nRaio: [" << Raio_Contagio << "]\nTaxa de Contagio: [" << Taxa_Contagio << "]\nPerigosidade: [" << Perigosidade << "]\nData de Inicio: [" << Data_Inicio.Dia << "/" << Data_Inicio.Mes << "/" << Data_Inicio.Ano << "]" << endl;
}
