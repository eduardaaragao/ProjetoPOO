#include <iostream>
using namespace std;
#include "SGestao.h"

int main()
{
    //  srand(time(NULL));// N�o retirar
    cout << "Inicio do programa" << endl;
    SGestao SG;
    SG.Load("Ficheiro_Teste.txt");
    SG.LancarVirus();
    SG.Run();
    cout << "Final do programa" << endl;
    return 0;
}   

//Tirar o friend class e colocar os metodo publicos pq n � boa pratica
/*
Possiveis altera��es:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informa��es como quantos infectados na cidade
*/

