#include <iostream>
#include "SGestao.h"



extern void Menu();
int main()
{
	srand(time(NULL));// Não retirar

	SGestao SG;
	SG.Load("Ficheiro_Teste.txt");
	SG.Run();
	return 0;
}

//Tirar o friend class e colocar os metodo publicos pq n é boa pratica
/*
Possiveis alterações:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informações como quantos infectados na cidade
*/

