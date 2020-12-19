#define _CRT_SECURE_NO_WARNINGS
#include "SGestao.h"
#include "Uteis.h"
#include<windows.h>
#include <conio.h>

SGestao::SGestao()
{
    //Inicia as listas, somente para teste, apagar depois
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
}

SGestao::~SGestao()
{
    // Implemente o destrutor da classe SGestao, que obviamente deve libertar toda a mem�ria ocupada.
   Gravar_Pessoas("Ficheiro_Teste.txt");
}

bool SGestao::Load(const string &N_Ficheiro)
{
    // 1. Carregar os dados de ficheiros, este m�todo � fundamental!

    ifstream Ficheiro_1;
    Ficheiro_1.open(N_Ficheiro, ios::in);

    if(Ficheiro_1.is_open())
    {

        string Linha_Ficheiro, Variavel, Linha_Ficheiro_2;
        char Delimitador = '\t';
        Pessoa* AUX_Pessoa;
        char BI[10];
        int Pos;
        Ponto* P;

        while (getline(Ficheiro_1, Linha_Ficheiro))//Pega a linha do ficheiro
        {

            string Vetor_Variaveis[25];
            istringstream AUX_Linha_Ficheiro(Linha_Ficheiro);
            Pos = 0;

            //Separa a linha do ficheiro
            while (getline(AUX_Linha_Ficheiro, Variavel,Delimitador))
            {

                Vetor_Variaveis[Pos] = Variavel;
                Pos++;

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

            //Cria o BI
            strcpy(BI, Vetor_Variaveis[0].c_str());

            // Cria a pessoa
            AUX_Pessoa = new Pessoa(Vetor_Variaveis[1], BI, Vetor_Variaveis[2], atoi(Vetor_Variaveis[3].c_str()),P);

            if (Pos > 6)
            {
                for (int x = 6; x < Pos;x++)
                {
                    list<Virus*> :: iterator it = Lista_Virus.begin();
                    while (it != Lista_Virus.end())
                    {

                        if (_stricmp(Vetor_Variaveis[x].c_str(),(*it)->Get_Nome_Virus().c_str()) == 0)
                        {
                            AUX_Pessoa->Get_Virus_Contraidos()->push_back(*it);
                            (*it)->Get_LP().push_back(AUX_Pessoa);
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
    list<Pessoa*> ::iterator it;
    int cont = 0;

    for (it = L_Infetados.begin();it != L_Infetados.end();it++)
    {
        // Percorrer a lista de virus infectados e chamar a contar_Virus

        //(*it)->Get_Virus_Contraidos
    }
    return 0;
}

Pessoa* SGestao::PessoaMaisContagios()
{
    // 3. Determinar a pessoa que mais cont�gios provocou.
    return NULL;
}

bool SGestao::PessoaFonteContagio(const string& BI)
{
    // 4. Verificar se uma dada pessoa esteve na base de algum cont�gio;
    return true;
}

int SGestao::Memoria()
{
    // 5. Determinar toda a mem�ria ocupada;
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
    // 7. Determinar qual o tipo de v�rus que est� mais activo;

    Virus* maisActivo = NULL;
    unsigned int maisInfetados = 0;

    for (list<Virus*>::iterator IT = Lista_Virus.begin(); IT != Lista_Virus.end(); ++IT)
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
    // 8. Determinar as pessoas que podem ter mais do que um v�rus;
}

void SGestao::RemoverVirus(Virus* X)
{
    // 9. Pode acontecer que um dado v�rus seja extinto!, ent�o todas as pessoas que t�m esse v�rus devem ficar bem;
}

void SGestao::EscreverXML(const string& fich_xml)
{
    // 10. Gravar para ficheiro em formato XML um dado modelo;

}

string SGestao::CidadeMaisCasos()
{
    // 12. Determinar a cidade que est� a ser mais afetada;

    string CID_CASOS;
    int MAX_CASOS = 0;
    list<Cidade*> ::iterator i;

    for (i = CIDADES.begin(); i != CIDADES.end(); i++)
    {
        if ((*i)->getCont() > MAX_CASOS)
        {
            CID_CASOS = (*i)->getCidade();
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
    // Add uma fun�a� uteis que define escalao da idade
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
    //Ser� que � poss�vel ir de um ponto A a um ponto B sem passar por posi��es onde
    // est�o pessoas infetadas ? Se for poss�vel, deve devolver a lista das posi��es por onde se pode passar;
    return NULL;
}

list<Ponto*>* SGestao::Possivel_Zona_Ir_A_B(Ponto& A, Ponto& B)
{
    //Ser� que � poss�vel ir de um ponto A a um ponto B sem passar por dentro de qualquer
    //zona de cont�gio ? Se for poss�vel, deve devolver a lista das posi��es por onde se pode passar;
    return NULL;
}

//--------M�todos que nao foram pedidas------------------------

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
            Ficheiro_1 << (*it1)->Get_BI() << "\t" << (*it1)->Get_Nome() << "\t" << (*it1)->Get_Cidade() << "\t" << (*it1)->Get_Idade() << "\t" << (*it1)->Get_Coordenada_Atual()->Get_X() << "\t" << (*it1)->Get_Coordenada_Atual()->Get_Y();

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

void SGestao::LancarVirus()
{
    bool notfound = true;
    bool isEqual = false;
    int posPessoa, posVirus;

    while (notfound)
    {
        posPessoa = Uteis::GetPosicaoAleatoria(Lista_Pessoas.size() - 1);
        posVirus = Uteis::GetPosicaoAleatoria(Lista_Virus.size() - 1);

        Pessoa* P = GetPessoa(posPessoa);
        Virus* V = GetVirus(posVirus);

        list<Virus*>* LV = P->Get_Virus_Contraidos();

        for (list<Virus*>::iterator IT = LV->begin(); IT != LV->end(); ++IT)
        {   
            if (V == (*IT))
                isEqual = true;
        }
        if (!isEqual)
        {
            AfectarVirusPessoa(V, P);
            notfound = false;
        }
    }
}

void SGestao::AfectarVirusPessoa(Virus* V, Pessoa* P)
{
    P->Get_Virus_Contraidos();

    V->AfectarPessoa(P);    
    P->FuiInfetado(V);
    L_Infetados.push_back(P);
}

void SGestao::Mostrar_Casos_Cidades()
{
    // Lista as cidades e seus respectivos n�meros de casos

    list<Cidade*> ::iterator it;

    for (it = CIDADES.begin();it != CIDADES.end(); it++)
    {
        cout << "Cidade: " << (*it)->getCidade() << " [ " << (*it)->getCont() << "]" << endl;
    }

}

bool SGestao::Run()
{
    Uteis::MSG("Simulacao a correr....");
    while (true)
    {
        for (list<Pessoa*>::iterator IT = Lista_Pessoas.begin(); IT != Lista_Pessoas.end(); ++IT)
            (*IT)->Run();
        if (_kbhit())
            Menu();
    }
    return true;
}

void SGestao::Menu()
{
    Uteis::MSG("Simulacao pausada...");
    int option = 1;
    while (option != 0)
    {
        Sleep(1000);
        Uteis::MSG("Escolha uma opcao no menu: ");
        Uteis::MSG("1 - Lancar virus aleatoriamente em uma pessoa");
        Uteis::MSG("2 - Mostrar todos os dados do sistema");
        Uteis::MSG("3 - Listar pessoas atualmente contagiadas");
        Uteis::MSG("4 - Qual e o virus mais activo atualmente?");
        Uteis::MSG("0 - Voltar para simulacao");

        cin >> option;

        switch (option)
        {
        case 1:
            LancarVirus();
            Uteis::MSG("Virus lancado.");
            break;
        case 2:
            // Mostrar todos os dados do sistema
            break;
        case 3:
            // Mostrar pessoas atualmente contagiadas
            PessoasContagiadas(L_Infetados);
            break;
        case 4:
            Virus* V = VirusMaisActivo();
            V->Mostrar();
            break;
        }

    }
}