#include <string>
using namespace std;
#ifndef CIDADE__H
#define CIDADE__H

class Cidade
{
	string nome;
	int cont;

public:
	int getCont() { return cont; }
	string getCidade() { return nome; }
	Cidade(string _nome);
	~Cidade();


};

Cidade::Cidade(string _nome)
{
	nome = _nome;
	cont = 0;
}

Cidade::~Cidade()
{
}


#endif // !CIDADE__H
