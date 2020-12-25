#define _CRT_SECURE_NO_WARNINGS
#include "SGestao.h"
#include "Uteis.h"
#include<windows.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>

SGestao::SGestao()
{
    //Inicia as listas, somente para teste, apagar depois

    //----- Lista de virus -----

    Data* a;
    Virus* virus;
    a = new Data(10, 04, 2019);
    virus = new Covid("Covid-19", 10, 62, 33, a);
    Lista_Virus.push_back(virus);

    a = new Data(20, 02, 1998);
    virus = new Virus("Ebola",33,52,65,a);
    Lista_Virus.push_back(virus);

    a = new Data(05, 8, 1989);
    virus = new Virus("Paludismo", 63, 12, 8, a);
    Lista_Virus.push_back(virus);

    //----- Lista de Movimentos possiveis -----

    MovimentosPossiveis.push_back(new Ponto(1, 0));
    MovimentosPossiveis.push_back(new Ponto(0, 1));
    MovimentosPossiveis.push_back(new Ponto(1, 1));
    MovimentosPossiveis.push_back(new Ponto(-1, 0));
    MovimentosPossiveis.push_back(new Ponto(0, -1));
    MovimentosPossiveis.push_back(new Ponto(-1, -1));
    for (int i = 0; i < 4; i++)
    {
        MovimentosPossiveis.push_back(new Ponto(0, 0));
    }

}

SGestao::~SGestao()
{   
    // Implemente o destrutor da classe SGestao, que obviamente deve libertar toda a memória ocupada.
    Gravar_Pessoas("Ficheiro_Teste.txt");
    Destruir_L_Cidades();
    Destruir_L_Pessoas();
    Destruir_L_Virus();
    Destruir_L_Movimentos();
    L_Infetados.clear();
    L_Quarentena.clear();
}

bool SGestao::Load(const string &N_Ficheiro)
{
    // 1. Carregar os dados de ficheiros, este método é fundamental!

    ifstream Ficheiro_1;
    Ficheiro_1.open(N_Ficheiro, ios::in);

    if(Ficheiro_1.is_open())
    {

        string Linha_Ficheiro, Variavel, Linha_Ficheiro_2;
        char Delimitador = '\t';
        Pessoa* AUX_Pessoa;
        int Pos;
        Ponto* P;
        Cidade* AUX_C;

        while (getline(Ficheiro_1, Linha_Ficheiro))//Pega a linha do ficheiro
        {

            string Vetor_Variaveis[30];
            istringstream AUX_Linha_Ficheiro(Linha_Ficheiro);
            Pos = 0;

            //Separa a linha do ficheiro
            while (getline(AUX_Linha_Ficheiro, Variavel, Delimitador))
            {

                Vetor_Variaveis[Pos] = Variavel;
                Pos++;

            }
            

            //Cria a cidade

            AUX_C = Conferir_L_Cidade(CIDADES, Vetor_Variaveis[2]);

            if(!AUX_C)
            {
                AUX_C = new Cidade(Vetor_Variaveis[2]);
                CIDADES.push_back(AUX_C);
            }           

            //Cria o ponto
            if (Vetor_Variaveis[4].empty() || Vetor_Variaveis[5].empty())
            {
               P = new Ponto();
            }
            else
            {
              P = new Ponto(atoi(Vetor_Variaveis[4].c_str()), atoi(Vetor_Variaveis[5].c_str()));
            }
            
            // Cria a pessoa
            AUX_Pessoa = new Pessoa(Vetor_Variaveis[1], Vetor_Variaveis[0], AUX_C, atoi(Vetor_Variaveis[3].c_str()),P, atoi(Vetor_Variaveis[6].c_str()), atoi(Vetor_Variaveis[7].c_str()));
            
            //Reinfectar pessoas com os virus
            if (Pos > 8) 
            {
                for (int x = 8; x < Pos;x++)
                {
                    list<Virus*> :: iterator it = Lista_Virus.begin();
                    while (it != Lista_Virus.end())
                    {

                        if (_stricmp(Vetor_Variaveis[x].c_str(),(*it)->Get_Nome_Virus().c_str()) == 0)
                        {
                            AfectarVirusPessoa((*it),AUX_Pessoa);
                        }
                        ++it;
                    }
                }
            }

            Lista_Pessoas.push_back(AUX_Pessoa);
            Vetor_Variaveis->clear();

        }

        Ficheiro_1.close();
        return true;
    }
    else
    {
        Uteis::MSG("\nErro ao abrir o ficheiro\n");
    }

    Ficheiro_1.close();
    return false;
}

int SGestao::Contar(Virus* X)
{
    list<Virus*> ::iterator it;
    int cont = 0;
    it = Lista_Virus.begin();
    while(it != Lista_Virus.end())
    {
        if (_stricmp(X->Get_Nome_Virus().c_str(),(*it)->Get_Nome_Virus().c_str()) == 0)
        {
            return (*it)->Get_LP().size();
        }
        ++it;
    }
    return 0;
}

Pessoa* SGestao::PessoaMaisContagios()
{
    // 3. Determinar a pessoa que mais contágios provocou.
    return NULL;
}

bool SGestao::PessoaFonteContagio(const string& BI)
{
    // 4. Verificar se uma dada pessoa esteve na base de algum contágio;
    return true;
}

int SGestao::Memoria()
{
    // 5. Determinar toda a memória ocupada;
    return 0;
}

void SGestao::PessoasContagiadas(list<Pessoa*>& L)
{
    cout << "Quantidade de infetados: " << L.size() << endl;
    Uteis::MSG("------------ Lista de Infetados ------------");
    for (list<Pessoa*>::iterator IT = L.begin(); IT != L.end(); ++IT)
        (*IT)->Mostrar();
}

Virus* SGestao::VirusMaisActivo()
{
    // 7. Determinar qual o tipo de vírus que está mais activo;
    Virus* maisActivo = NULL;
    int maisInfetados = 0;
    list<Virus*>::iterator IT;
    for (IT = Lista_Virus.begin(); IT != Lista_Virus.end(); ++IT)
    {
        if ((*IT)->Get_LP().size() > maisInfetados)
        {
            maisInfetados = (*IT)->Get_LP().size();
            maisActivo = (*IT);
        }
    }
    return maisActivo;
}

void SGestao::PessoasMaisUmVirus(list<Pessoa*>& L)
    {
        // 8. Determinar as pessoas que podem ter mais do que um vírus;
    }

void SGestao::RemoverVirus(Virus* X)
{
    // 9. Pode acontecer que um dado vírus seja extinto!, então todas as pessoas que têm esse vírus devem ficar bem;
}

void SGestao::EscreverXML(const string& fich_xml)
{
    // 10. Gravar para ficheiro em formato XML um dado modelo;

}

string SGestao::CidadeMaisCasos()
{
    // 12. Determinar a cidade que está a ser mais afetada;
    string CID_CASOS;
    int MAX_CASOS = 0;
    list<Cidade*> ::iterator i;

    for (i = CIDADES.begin(); i != CIDADES.end(); i++)
    {
        if ((*i)->Get_L_Cidade()->size() > MAX_CASOS)
        {
            CID_CASOS = (*i)->getNome();
        }
    }

    return CID_CASOS;
}

bool SGestao::AlertasAsPessoasProximas(int N, double R)
{
    // 13. Se N ou mais pessoas estiverem muito juntas (num raio inferior a R) as pessoas devem
    // ser alertadas;
    return true;
}

int SGestao::EscalaoIdadeMaisAfectado()
{
    // Add uma funçaõ uteis que define escalao da idade
    map<int, int> Escalao;
    int i,escalao,Idade;
    int maxInfetados = 0;
    list<Pessoa*> ::iterator it;
    map<int, int> :: iterator it2;

    for (i = 0; i < 10; i++) // Aloca um escalao de 0 - 9 
    {
        Escalao.emplace(i, 0);
    }

    // conabilizar pessoas infetadas em seu escalao
    for (it = L_Infetados.begin(); it != L_Infetados.end();it++)
    {
        int Idade = (*it)->Get_Idade();
        if (Idade < 10)
            escalao = 0;
        if (Idade >= 10 && Idade < 20)
            escalao =  1;
        if (Idade >= 20 && Idade < 30)
            escalao = 2;
        if (Idade >= 30 && Idade < 40)
            escalao = 3;
        if (Idade >= 40 && Idade < 50)
            escalao = 4;
        if (Idade >= 50 && Idade < 60)
            escalao = 5;
        if (Idade >= 60 && Idade < 70)
            escalao = 6;
        if (Idade >= 70 && Idade < 80)
            escalao =  7;
        if (Idade >= 80 && Idade < 90)
            escalao = 8;
        if (Idade >= 90)
            escalao = 9;

        it2 = Escalao.find(escalao);
        it2->second += 1;
    }

    for (it2 = Escalao.begin(); it2 != Escalao.end(); it2++)
    {
        if (maxInfetados < it2->second)
        {
            maxInfetados = it2->second;
            escalao = it2->first;
        }
    }
    return escalao;
}

list<Ponto*>* SGestao::PossivelIr_A_B(Ponto& A, Ponto& B)
{
    //Será que é possível ir de um ponto A a um ponto B sem passar por posições onde
    // estão pessoas infetadas ? Se for possível, deve devolver a lista das posições por onde se pode passar;
    return NULL;
}

list<Ponto*>* SGestao::Possivel_Zona_Ir_A_B(Ponto& A, Ponto& B)
{
    //Será que é possível ir de um ponto A a um ponto B sem passar por dentro de qualquer
    //zona de contágio ? Se for possível, deve devolver a lista das posições por onde se pode passar;
    return NULL;
}

//-------------Métodos que nao foram pedidas------------------------

bool SGestao::Run(vector<Ponto*>* Movimentos)
{
    Uteis::MSG("Simulacao a correr....");
    bool AUX = true;
    while (AUX)
    {
        for (list<Pessoa*>::iterator IT = Lista_Pessoas.begin(); IT != Lista_Pessoas.end(); ++IT)
            (*IT)->Run(Movimentos);
        if (_kbhit())
            AUX = Menu();
    }
    return true;
}

void SGestao::Mostrar_L_Virus()
{
    list<Virus*>::iterator it = Lista_Virus.begin();
    while (it != Lista_Virus.end())
    {

        (*it)->Mostrar();
        ++it;
    }
}

void SGestao::Mostrar_L_Pessoas()
{
    list<Pessoa*>::iterator it = Lista_Pessoas.begin();
    while (it != Lista_Pessoas.end())
    {
        (*it)->Mostrar();
        ++it;
    }
}

bool SGestao::Gravar_Pessoas(const string& N_Ficheiro_1)
{
    ofstream Ficheiro_1;

    Ficheiro_1.open(N_Ficheiro_1, ios::out);

    if (Ficheiro_1.is_open())
    {
        list<Pessoa*> ::iterator it1 = Lista_Pessoas.begin();
        list<Virus*> ::iterator it2;
        list<Virus*>* Lv;

        while (it1 != Lista_Pessoas.end())
        {
  
            Ficheiro_1 << (*it1)->Get_BI() << "\t" << (*it1)->Get_Nome() << "\t" << (*it1)->Get_Cidade()->getNome() << "\t" << (*it1)->Get_Idade() << "\t" << (*it1)->Get_Coordenada_Atual()->Get_X() << "\t" << (*it1)->Get_Coordenada_Atual()->Get_Y() << "\t" << (*it1)->Get_eBaseContagio() << "\t" << (*it1)->Get_ContagiosProvocados();

          if(!(*it1)->Get_Virus_Contraidos()->empty())
          {
              Lv = (*it1)->Get_Virus_Contraidos();
              it2 = Lv->begin();

               while (it2 != Lv->end())
              {
                  Ficheiro_1 << "\t" <<(*it2)->Get_Nome_Virus();
                  ++it2;
              }
          }
          Ficheiro_1 << "\n";
          ++it1;
        }

        Ficheiro_1.close();
        return true;
    }
    else
    {
        Uteis::MSG("\nErro ao abrir o ficheiro\n");
    }
    
    Ficheiro_1.close();
    return false;
}

Pessoa* SGestao::GetPessoa(int i)
{
    list<Pessoa*>::iterator IT = Lista_Pessoas.begin();

    int j = 0;
    for (IT; j != i; ++IT)
        ++j;
    return *IT;
}

Virus* SGestao::GetVirus(int i)
{
    list<Virus*>::iterator IT = Lista_Virus.begin();
    int j = 0;
    for (IT; j != i; ++IT)
        ++j;
    return *IT;
}

Virus* SGestao::GetVirus(string nome)
{
    list<Virus*>::iterator IT = Lista_Virus.begin();

    while(IT != Lista_Virus.end())
    {
        if(_stricmp((*IT)->Get_Nome_Virus().c_str(), nome.c_str()) == 0)
        {
            return (*IT);
        }
        ++IT;
    }
    return NULL;
}

void SGestao::LancarVirus()
{
    bool notfound = true;
    int posPessoa, posVirus;
    Pessoa* P;
    Virus* V;
    list<Virus*>* LV;

    while (notfound)
    {
        posPessoa = Uteis::GetPosicaoAleatoria(Lista_Pessoas.size());
        posVirus = Uteis::GetPosicaoAleatoria(Lista_Virus.size());

        P = GetPessoa(posPessoa);
        V = GetVirus(posVirus);

        LV = P->Get_Virus_Contraidos();

        notfound = AfectarVirusPessoa(V, P);    
    }
}
    
Pessoa* SGestao::Conferir_L_Pessoas(list<Pessoa*> Lista, Pessoa* Objeto)
{
    if (Lista.empty()) 
        return NULL;

    list<Pessoa*>::iterator it = Lista.begin(); 
    while (it != Lista.end())
    {
        if ((*it) == Objeto)
            return (*it);
        ++it;
    }
    return NULL;
}

Virus* SGestao::Conferir_L_Virus(list<Virus*> Lista, Virus* Objeto)
{
    if (Lista.empty())
        return NULL;

    list<Virus*>::iterator it = Lista.begin();
    while (it != Lista.end())
    {
        if ((*it) == Objeto)
            return (*it);
        ++it;
    }
    return NULL;
}

Cidade* SGestao::Conferir_L_Cidade(list<Cidade*> Lista, string N_Cidade)
{
    if (Lista.empty())
        return NULL;

    list<Cidade*>::iterator it = Lista.begin();
    while (it != Lista.end())
    {
        if (_stricmp((*it)->getNome().c_str(), N_Cidade.c_str()) == 0)
            return (*it);
        ++it;
    }
    return NULL;
}

bool SGestao::AfectarVirusPessoa(Virus* V, Pessoa* P)
{
    if (Conferir_L_Virus(*P->Get_Virus_Contraidos(),V) == NULL)
    {
        V->AfectarPessoa(P);
        P->FuiInfetado(V);
        
        if (P->Get_Virus_Contraidos()->size() == 1)
        {

            P->Get_Cidade()->Get_L_Cidade()->push_back(P);
        }

        if (Conferir_L_Pessoas(L_Infetados, P) == NULL)
        {
            L_Infetados.push_back(P);
        }
        return false;
    }
    return true;
}

/*
void Ver_L_Infectador()
{

}*/

void SGestao::Mostrar_Casos_Cidades()
{
    // Lista as cidades e seus respectivos números de casos

    list<Cidade*> ::iterator it;

    for (it = CIDADES.begin();it != CIDADES.end(); it++)
    {
        (*it)->Mostrar();
    }

}

void SGestao::Numero_De_Virus() 
{
    Mostrar_L_Virus();
    cout << "\nQual o virus que é desejado?\n";
    string N;
    cin >> N;
    Virus* V = GetVirus(N);
    if (V != NULL)
    {
        cout << "\nO virus " << V->Get_Nome_Virus() << " tem " << Contar(V) << " infectados\n" << endl;
    }
    else 
    {
        cout << "Virus não existe" << endl;
    }
}

bool SGestao::Menu()
{
    Uteis::MSG("Simulacao pausada...");
    int option = -1;
    while (option != 1)
    {
        Sleep(1000);
        Uteis::MSG("\nEscolha uma opcao no menu: ");
        Uteis::MSG("1 - Voltar a simulação");
        Uteis::MSG("2 - Lancar virus aleatoriamente em uma pessoa");
        Uteis::MSG("3 - Contar o número de vírus de um dado Tipo");
        Uteis::MSG("4 - Listar pessoas atualmente contagiadas");
        Uteis::MSG("5 - Qual e o virus mais activo atualmente?");
        Uteis::MSG("6 - Cidade que está a ser mais afetada");
        Uteis::MSG("0 - Sair do programa");

        cin >> option;

        Uteis::MSG("");
        Virus* V;
        switch (option)
        {
        case 1:
            system("cls");
            break;
        case 2:
            LancarVirus();
            Uteis::MSG("Virus lancado.");
            break;
        case 3:
            // Contar o número de vírus de um dado Tipo
            Numero_De_Virus();
            break;
        case 4:
            // Mostrar pessoas atualmente contagiadas
            PessoasContagiadas(L_Infetados);
            break;
        case 5:
            V = VirusMaisActivo();
            V->Mostrar();
            break;
        case 6:
            //Cidade que está a ser mais afetada
            cout << "\nA cidade mais afetada é: " << CidadeMaisCasos() << endl;
            break;
        case 0:
            return false;
            break;
        }
        system("pause");
        system("cls");
    }
}



//----------------- Destruir os Dados -----------------

void SGestao::Destruir_L_Cidades()
{
    list<Cidade*> ::iterator IT = CIDADES.begin();
    while (IT != CIDADES.end())
    {
        delete(*IT);
        ++IT;
    }
    CIDADES.clear();
}

void SGestao::Destruir_L_Pessoas()
{
    list<Pessoa*> ::iterator IT = Lista_Pessoas.begin();
    while (IT != Lista_Pessoas.end())
    {
        delete(*IT);
        ++IT;
    }
    Lista_Pessoas.clear();
}

void SGestao::Destruir_L_Virus()
{
    list<Virus*> ::iterator IT = Lista_Virus.begin();
    while (IT != Lista_Virus.end())
    {
        delete(*IT);
        ++IT;
    }
    Lista_Virus.clear();
}

void SGestao::Destruir_L_Movimentos()
{
    
    vector<Ponto*> ::iterator IT = MovimentosPossiveis.begin();
    while (IT != MovimentosPossiveis.end())
    {
        delete(*IT);
        ++IT;
    }
    MovimentosPossiveis.clear();
}


