#include <iostream>
#include "SGestao.h"
#include "Virus.h"


extern void Menu();
int main()
{
	srand(time(NULL));// Não retirar

	SGestao A;
	A.Load("Ficheiro_Pessoa.txt");
	A.Mostrar_L_Pessoas();
	//A.Mostrar_L_Virus();
	return 0;
}

//Tirar o friend class e colocar os metodo publicos pq n é boa pratica
/*
Possiveis alterações:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informações como quantos infectados na cidade
*/

