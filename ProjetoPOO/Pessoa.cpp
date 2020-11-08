#include "Pessoa.h"

Pessoa::Pessoa(string nome, char* bi, string cidade, unsigned short int idade, unsigned short int coordenada_x, unsigned short int coordenada_y, Virus* virus_infectado)
{
	// cout << "Passei em " << __FUNCTION__ << endl;
	Nome = nome;
	BI = bi;
	Cidade = cidade;
	Idade = idade;
	Coordenada_X = coordenada_x;
	Coordenada_Y = coordenada_y;
	Virus_Infectado = virus_infectado;
}

Pessoa::~Pessoa()
{
	// cout << "Passei em " << __FUNCTION__ << endl;
}

void Pessoa::Mostrar_Pessoa()
{

	cout << "\nNome: [" << Nome << "]\nBI: [" << BI << "]\nCidade: [" << Cidade << "]\nIdade: [" << Idade << "]\nCoordenada X: [" << Coordenada_X << "]\nCoordenada Y: [" << Coordenada_Y << "]\nVirus: [" << Virus_Infectado->Get_Nome() << "]" << endl;

}
