#pragma once
using namespace std;
#include <vector>
#include <sstream>
#include <list>

//----- Classes -----
#include "Pessoa.h"
#include "Virus.h"
#include "Covid.h"
#include "Ponto.h"
#include "Cidade.h"
#include <map>


/*POR FAVOR, CHEQUEM ESSES COMENTÁRIOS E ANALISEM SE ESSAS FUNÇÕES COMENTADAS SÃO NECESSÁRIAS OU NÃO!*/
class SGestao
{
	private:
		/* ATRIBUTOS DA CLASSE GESTÃO */
		list<Pessoa*> Lista_Pessoas; 
		list<Virus *> Lista_Virus; 
		list<Pessoa*> L_Infetados; 
		list<Pessoa*> L_Quarentena; 
		list<Pessoa*> L_Falecidos;
		list<Cidade*> CIDADES;
		vector<Ponto*> MovimentosPossiveis;
	public:	
		/*CONSTRUTORES E DESTRUTORES*/

		SGestao();
		virtual ~SGestao();

		/*MÉTODOS PEDIDOS NO ENUNCIADO*/

		bool Load(const string &N_Ficheiro);
		int Contar(Virus* X);
		Pessoa* PessoaMaisContagios();
		bool PessoaFonteContagio(const string& BI);
		int Memoria();
		void PessoasContagiadas(list<Pessoa*>& L);
		Virus* VirusMaisActivo();
		void PessoasMaisUmVirus(list<Pessoa*>& L);
		void RemoverVirus(Virus* X);
		void EscreverXML(const string& fich_xml);
		string CidadeMaisCasos();
		bool AlertasAsPessoasProximas(int N, double R);
		int EscalaoIdadeMaisAfectado();
		list<Ponto*>* PossivelIr_A_B(Ponto& A, Ponto& B);
		list<Ponto*>* Possivel_Zona_Ir_A_B(Ponto& A, Ponto& B);

protected:
		/*MÉTODOS EXTRAS*/
		bool Run();

		bool Load_Falecidos(const string& N_Ficheiro);
		bool Gravar_Pessoas(list<Pessoa*>* Lista, const string& N_Ficheiro_1);
		bool Menu();
		void PrintarSistema();

		void Mostrar_L_Virus();
		void Mostrar_L_Pessoas();

		void LancarVirus();
		bool InfetarVirusPessoa(Virus* V, Pessoa* P);
		void PassarVirus(Virus* V);

		void Mostrar_Casos_Cidades();

		Pessoa* GetPessoa(int i);
		Virus* GetVirus(int i);
		Virus* GetVirus(string i);
		vector<Ponto*>* GetMovimentosPossiveis() { return &MovimentosPossiveis; }

		bool HaInfetadoPosicao(Ponto* P);
		bool HaInfetadoZona(Ponto* P);
		int ZonaVirus(Pessoa* P);
		/* MENUS AUXILIARES */
		void MenuContarVirus();
		void MenuFonteContagio();
		void MenuEliminarVirus();
		void Menu_Virus_Mais_Ativo();
		void Menu_Andar_Entre_Pontos();
		void Menu_Mostrar_Dados();
		void MenuEscalao();
		void Menu_Alerta();
		void Menu_Possivel_Ir_Zona();
};

