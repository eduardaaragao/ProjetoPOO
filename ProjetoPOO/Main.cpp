#include <iostream>
using namespace std;
#include "SGestao.h"
#include "Uteis.h"

int main()
{
    srand(time(NULL));
    Uteis::MSG("Inicio do programa");
    SGestao SG;
    SG.Load("Ficheiro_Teste.txt");
    SG.LancarVirus();
    SG.Run();
    Uteis::MSG("Fim do programa");
    return 0;
}

/*while (true)
{

    SGestao::run();
    if (kbhit()) //include do conioh.
    {
        getchar();
        SGestao::Menu();
    }*/

/*
Possiveis altera��es:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informa��es como quantos infectados na cidade
*/

