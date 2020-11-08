#define _CRT_SECURE_NO_WARNINGS
#include "SGestao.h"


SGestao::SGestao()
{
   // cout << "Passei em " << __FUNCTION__ << endl;

    //Inicia as lista, somente para teste, apagar depois
    Data B;
    B.Dia = 20;
    B.Mes = 05;
    B.Ano = 2020;

    Virus *A1 = new Virus("Vid-56", 10, 20, 30, B);

    Lista_Virus.push_back(A1);
    Virus* A2 = new Virus("co-63", 65, 20, 57, B);
    Lista_Virus.push_back(A2);
    Virus* A3 = new Virus("hs-66", 28, 30, 50, B);
    Lista_Virus.push_back(A3);

    char* BI = (char*)malloc(9 * sizeof(char)); 
    strcpy(BI,"12345678");

    Pessoa *C1 = new Pessoa("Carlos", BI, "Mangualde", 30, 22, 55, A1);
    Lista_Pessoas.push_back(C1);

    Pessoa* C2 = new Pessoa("Rafael", BI, "Viseu", 24, 6, 87, A2);
    Lista_Pessoas.push_back(C2);

    Pessoa* C3 = new Pessoa("Ricardo", BI, "Porto", 55, 8, 66, A3);
    Lista_Pessoas.push_back(C3);
}

SGestao::~SGestao()
{
   // cout << "Passei em " << __FUNCTION__ << endl;
}

bool SGestao::Load(const string &N_Ficheiro) 
{
    ifstream Ficheiro;
    Ficheiro.open(N_Ficheiro, ios::in);
    string AUX;
    char Delimitador =';';

    if(Ficheiro.is_open())
    {
        while (getline(Ficheiro,AUX,Delimitador)) 
        {
            //Terminar Quando tiver o ficheiro de dados
        }
        return true;
    }
    else
    {
        MSG("\nErro ao abrir o ficheiro\n");
    }
 
    return false;
}

void SGestao::Mostrar_L_Virus()
{
    list<Virus *>::iterator it = Lista_Virus.begin();
    while(it != Lista_Virus.end())
    {
      
        (*it)->Mostrar_Virus();
        ++it;
    }
}

void SGestao::Mostrar_L_Pessoas()
{
    list<Pessoa *>::iterator it = Lista_Pessoas.begin();
    while (it != Lista_Pessoas.end())
    {

        (*it)->Mostrar_Pessoa();
        ++it;
    }
}
