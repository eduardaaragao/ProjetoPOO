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

class SGestao
{
	private:
		//----- Atributos -----//
		list<Pessoa*> Lista_Pessoas; // Lista de pessoas do sistema
		list<Virus *> Lista_Virus; // Lista de vírus cadastrados
		list<Pessoa*> L_Infetados; // Lista de pessoas infetadas
		list<Pessoa*> L_Quarentena; // Lista de pessoas em quarentena
		list<Cidade*> CIDADES;
		vector<Ponto*> MovimentosPossiveis;
	public:	
		//----- Construtores e destrutores são públicos -----

		SGestao();
		virtual ~SGestao();

		//----- Métodos Pedidos -----

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

		//----- Métodos extras ----- Lembrar de tornar privado antes de entregar 
		bool Run(vector<Ponto*>* Movimentos);
		bool Gravar_Pessoas(const string& N_Ficheiro_1);
		bool Menu();

		void Mostrar_L_Virus();
		void Mostrar_L_Pessoas();

		void LancarVirus();
		bool AfectarVirusPessoa(Virus* V, Pessoa* P);

		Pessoa* Conferir_L_Pessoas(list<Pessoa*> Lista, Pessoa* Objeto);
		Cidade* Conferir_L_Cidade(list<Cidade*> Lista, string Objeto);
		Virus* Conferir_L_Virus(list<Virus*> Lista, Virus* Objeto);
		void Mostrar_Casos_Cidades();

		Pessoa* GetPessoa(int i);
		Virus* GetVirus(int i);
		Virus* GetVirus(string i);
		vector<Ponto*>* GetMovimentosPossiveis() { return &MovimentosPossiveis; }
		
		//----- AUX Menu ------

		void Numero_De_Virus();

		//----- Destuir ------

		void Destruir_L_Pessoas();
		void Destruir_L_Virus();
		void Destruir_L_Movimentos();
		void Destruir_L_Cidades();

		//-----Auxiliares-------
		//int escalaoIdade(int idade);
	
};

