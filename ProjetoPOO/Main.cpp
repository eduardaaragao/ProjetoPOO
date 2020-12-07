#include <iostream>
using namespace std;
#include "SGestao.h"

int main()
{
    //  srand(time(NULL));// Não retirar
    cout << "Inicio do programa" << endl;
    SGestao SG;
    SG.Load("Ficheiro_Teste.txt");
    SG.LancarVirus();
    SG.Run();
    cout << "Final do programa" << endl;
    return 0;
}   

//Tirar o friend class e colocar os metodo publicos pq n é boa pratica
/*
Possiveis alterações:
Criar classe cidade -> Pessoa com ponteiro pra Cidade -> Para guardar informações como quantos infectados na cidade
*/

