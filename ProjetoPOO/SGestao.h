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
	
	public:	
		//Construtores e destrutores são públicos

		SGestao();
		virtual ~SGestao();

		//----- Métodos Pedidos -----

		bool Load(const string &N_Ficheiro);
		bool Run();
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

		bool Gravar_Pessoas(const string& N_Ficheiro_1);
		void Mostrar_L_Virus();
		void Mostrar_L_Pessoas();
		void Infectar_Pessoa(Pessoa* pessoa, Virus* virus);
		void Mostrar_Casos_Cidades();
	
};

