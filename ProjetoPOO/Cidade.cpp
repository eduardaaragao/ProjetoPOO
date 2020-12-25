#include"Cidade.h"
#include <iostream>

Cidade::Cidade(string _nome)
{
	nome = _nome;
	
}

Cidade::~Cidade()
{
	Lista_Pessoas.clear();
}

void Cidade::Mostrar()
{
	cout << "\nNome: [" << nome << "]" << "Numero de Infectados: ["<< Lista_Pessoas.size() << "]" <<endl;
}