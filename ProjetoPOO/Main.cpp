#include <iostream>
#include "SGestao.h"



extern void Menu();
int main()
{
	srand(time(NULL));// N�o retirar

	SGestao SG;
	SG.Load("Ficheiro_Teste.txt");
	SG.Run();
	return 0;
}

//Tirar o friend class e colocar os metodo publicos pq n � boa pratica
/*
Possiveis altera��es:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informa��es como quantos infectados na cidade
*/

