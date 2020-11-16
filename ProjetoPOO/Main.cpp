#include <iostream>
#include "SGestao.h"
#include "Virus.h"

extern void Menu();
int main()
{
	SGestao A;
	//A.Load("Ficheiro_Pessoa.txt");
	A.Mostrar_L_Pessoas();
	return 0;
}


/*
Possiveis alterações:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informações como quantos infectados na cidade
*/

