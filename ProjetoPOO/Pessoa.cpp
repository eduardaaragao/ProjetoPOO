#include "Pessoa.h"

Pessoa::Pessoa(string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual, Virus* virus_infectado)
{
	// cout << "Passei em " << __FUNCTION__ << endl;
	Nome = nome;	
	BI = bi;
	Cidade = cidade;
	Idade = idade;
	Coordenada_Atual = coordenada_atual;
	if (virus_infectado != NULL) 
	{
		Virus_Infectados.push_back(virus_infectado);
	}
}

Pessoa::~Pessoa()
{
	// cout << "Passei em " << __FUNCTION__ << endl;
}

void Pessoa::Mostrar_Pessoa()
{

	cout << "\nNome: [" << Nome << "]\nBI: [" << BI << "]\nCidade: [" << Cidade << "]\nIdade: [" << Idade << "]\nCoordenada X: [" << Coordenada_Atual->X << "]\nCoordenada Y: [" << Coordenada_Atual->Y << "]" <<endl;
	list<Virus*>:: iterator it = Virus_Infectados.begin();
	cout << "Lista de Virus:" << endl;
	while (it!= Virus_Infectados.end())
	{
		cout << "[" << (*it)->Get_Nome() << "]" << endl;
		++it;
	}
}
