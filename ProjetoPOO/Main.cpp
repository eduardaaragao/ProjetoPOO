#include <iostream>
#include "SGestao.h"
#include "Virus.h"


extern void Menu();
int main()
{
	srand(time(NULL));// N�o retirar

	SGestao A;
	A.Load("Ficheiro_Pessoa.txt");
	A.Mostrar_L_Pessoas();
	//A.Mostrar_L_Virus();
	return 0;
}

//Tirar o friend class e colocar os metodo publicos pq n � boa pratica
/*
Possiveis altera��es:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informa��es como quantos infectados na cidade
*/

