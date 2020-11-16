#define _CRT_SECURE_NO_WARNINGS
#include "SGestao.h"


SGestao::SGestao()
{

    //Inicia as lista, somente para teste, apagar depois
    Data B;
    B.Dia = 20;
    B.Mes = 05;
    B.Ano = 2020;

    Virus *A1 = new Virus("Vid-56", 10, 20, 30,B);

    Lista_Virus.push_back(A1);
    Virus* A2 = new Virus("co-63", 65, 20, 57, B);
    Lista_Virus.push_back(A2);
    Virus* A3 = new Virus("hs-66", 28, 30, 50, B);
    Lista_Virus.push_back(A3);

    char* BI = (char*)malloc(9 * sizeof(char));
    strcpy(BI,"12345678");

    Ponto* P = new Ponto(10,20);

    Pessoa *C1 = new Pessoa("Carlos", BI, "Mangualde", 30);
    Lista_Pessoas.push_back(C1);

    Pessoa* C2 = new Pessoa("Rafael", BI, "Viseu", 24);
    Lista_Pessoas.push_back(C2);

    Pessoa* C3 = new Pessoa("Ricardo", BI, "Porto", 55);
    Lista_Pessoas.push_back(C3); 
}

SGestao::~SGestao()
{
    // Implemente o destrutor da classe SGestao, que obviamente deve libertar toda a memória ocupada.

}

bool SGestao::Load(const string &N_Ficheiro)
{
    // 1. Carregar os dados de ficheiros, este método é fundamental!
    // ESSA FUNÇÃO ESTÁ ERRADA, mas vou consertar
    ifstream Ficheiro;
    Ficheiro.open(N_Ficheiro, ios::in);

    string Linha_Ficheiro, Variavel;
    char Delimitador = '\t';

    string Lista_Variaveis[4];
    int Pos;
    Pessoa* AUX_Pessoa;

    if(Ficheiro.is_open())
    {

        while (getline(Ficheiro, Linha_Ficheiro))
        {
            istringstream AUX_Linha_Ficheiro(Linha_Ficheiro);
            Pos = 0;
            while (getline(AUX_Linha_Ficheiro, Variavel,Delimitador))
            {
                Lista_Variaveis[Pos] = Variavel;
                ++Pos;
            }
            cout << Lista_Variaveis[0] << "\n" << Lista_Variaveis[1] << "\n" << Lista_Variaveis[2] << "\n" << Lista_Variaveis[3] << "\n\n";
           // string nome, char* bi, string cidade, unsigned short int idade, Ponto* coordenada_atual, Virus* virus_infectado
            Ponto* P = new Ponto(10, 20);
            char* BI = (char*)malloc(9 * sizeof(char));
            strcpy(BI, "12345678");
            AUX_Pessoa = new Pessoa(Lista_Variaveis[1], BI, Lista_Variaveis[2],10);
            Lista_Pessoas.push_back(AUX_Pessoa);

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

        (*it)->Mostrar();
        ++it;
    }
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

