#include <iostream>
using namespace std;
#include "SGestao.h"
#include "Uteis.h"

int main()
{
    srand(time(NULL));// Não retirar
    Uteis::MSG("Inicio do programa");
    SGestao SG;
    SG.Load("Ficheiro_Teste.txt");
    SG.LancarVirus();
    SG.Run();
    Uteis::MSG("Fim do programa");
    return 0;
}

//Tirar o friend class e colocar os metodo publicos pq n é boa pratica
/*
Possiveis alterações:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informações como quantos infectados na cidade
*/

