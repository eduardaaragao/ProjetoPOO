#include <iostream>
using namespace std;
#include "SGestao.h"
#include "Uteis.h"

int main()
{
    srand(time(NULL));// N�o retirar
    Uteis::MSG("Inicio do programa");
    SGestao SG;
    SG.Load("Ficheiro_Teste.txt");
    SG.LancarVirus();
    SG.Run();
    Uteis::MSG("Fim do programa");
    return 0;
}

//Tirar o friend class e colocar os metodo publicos pq n � boa pratica
/*
Possiveis altera��es:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informa��es como quantos infectados na cidade
*/

