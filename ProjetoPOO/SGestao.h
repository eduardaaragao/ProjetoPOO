#pragma once
#include"Virus.h"
#include"Pessoa.h"
#include "Ponto.h"
#include <vector>
#include <sstream>

class SGestao
{
	private:
		//----- Atributos -----
		list<Pessoa *> Lista_Pessoas; // Lista de pessoas do sistema
		list<Virus *> Lista_Virus; // Lista de vírus cadastrados
		list<Pessoa*> L_Infetados; // Lista de pessoas infetadas
		list<Pessoa*> L_Quarentena; // Lista de pessoas em quarentena
		//----- Métodos -----
		int Contar(Virus* X);
		Pessoa* PessoaMaisContagios();
		bool PessoaFonteContagio(const string& BI);
		int Memoria();
		void PessoasContagiadas(list<Pessoa*>&L);
		Virus* VirusMaisActivo();
		void PessoasMaisUmVirus(list<Pessoa*>&L);
		void RemoverVirus(Virus* X);
		void EscreverXML(const string& fich_xml);
		string CidadeMaisCasos();
		bool AlertasAsPessoasProximas(int N, double R);
		int EscalaoIdadeMaisAfectado();
		list<Ponto*>* PossivelIr_A_B(Ponto& A, Ponto& B);
		list<Ponto*>* Possivel_Zona_Ir_A_B(Ponto& A, Ponto& B);

	public:
		bool Load(const string &N_Ficheiro);

		void Mostrar_L_Virus();
		void Mostrar_L_Pessoas();
		//Construtores e destrutores são públicos
		SGestao();
		virtual ~SGestao();
};

