#include <string>
#include <list>

using namespace std;
#ifndef CIDADE__H
#define CIDADE__H

class Pessoa;
class Cidade
{
	//------ Variaveis -----
	string nome;
	list <Pessoa*> Lista_Pessoas;

public:
	Cidade(string _nome);
	~Cidade();
	void Mostrar();
	int Memoria();
	//------ Gets ------

	string getNome() { return nome; }
	list <Pessoa*>* Get_L_Cidade() { return &Lista_Pessoas; }

	//----- Sets -----

};



#endif // !CIDADE__H
