#define _CRT_SECURE_NO_WARNINGS
#include "SGestao.h"


SGestao::SGestao()
{
    //Inicia as lista, somente para teste, apagar depois
    Data* a;
    Virus* virus;
    a = new Data(10, 04, 2019);
    virus = new Covid("Covid", 10, 62, 33, a);
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
    // Implemente o destrutor da classe SGestao, que obviamente deve libertar toda a memória ocupada.
   Gravar_Pessoas("Ficheiro_Pessoa.txt");
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
        MSG("\nErro ao abrir o ficheiro\n");
    }

    Ficheiro_1.close();
    return false;
}

int SGestao::Contar(Virus* X)
{
    // 2. Contar o número de vírus de um dado Tipo;
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
    // 6. Determinar as pessoas que estão contagiadas.
}

Virus* SGestao::VirusMaisActivo()
{
    // 7. Determinar qual o tipo de vírus que está mais activo;
    return NULL;
}

void SGestao::PessoasMaisUmVirus(list<Pessoa*>& L)
{
    //  8. Determinar as pessoas que podem ter mais do que um vírus;
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
    return NULL;
}

bool SGestao::AlertasAsPessoasProximas(int N, double R)
{
    // 13. Se N ou mais pessoas estiverem muito juntas (num raio inferior a R) as pessoas devem
    // ser alertadas;
    return true;
}

int SGestao::EscalaoIdadeMaisAfectado()
{
    //14. Determinar qual o escalão de idades mais afetada; (Considera Escala 0-[0,9]; 1-
    //[10, 19] ; 2 - [20, 29]; etc
    return 0;
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

//--------Métodos que nao foram pedidas------------------------

void SGestao::Mostrar_L_Virus()
{
    list<Virus*>::iterator it = Lista_Virus.begin();
    while (it != Lista_Virus.end())
    {

        (*it)->Mostrar_Virus();
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
        MSG("\nErro ao abrir o ficheiro\n");
    }

    Ficheiro_1.close();
    return false;
}

void SGestao::Infectar_Pessoa(Pessoa* pessoa,Virus* virus)
{
    pessoa->Get_Virus_Contraidos()->push_back(virus);
    virus->Get_LP().push_back(pessoa);
}