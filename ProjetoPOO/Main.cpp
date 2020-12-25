#include <iostream>
using namespace std;
#include "SGestao.h"
#include "Uteis.h"

int main()
{
    srand(time(NULL));
    SGestao SG;
  
    SG.Load("Ficheiro_Teste.txt");
  //  SG.Mostrar_Casos_Cidades();
  //  SG.Mostrar_L_Pessoas();
  //  SG.Mostrar_L_Virus();

    SG.Run(SG.GetMovimentosPossiveis());
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
Possiveis alterações:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informações como quantos infectados na cidade
*/

