#pragma once
using namespace std;
#include"Virus.h"
#include"Pessoa.h"
#include "Ponto.h"
#include <vector>
#include <sstream>
#include <list>
<<<<<<< HEAD

=======
>>>>>>> d77f84f31da277bba72a1e314de5106151b68de0
class SGestao
{
	private:
		//----- Atributos -----
		list<Pessoa *> Lista_Pessoas; // Lista de pessoas do sistema
		list<Virus *> Lista_Virus; // Lista de vírus cadastrados
		list<Pessoa*> L_Infetados; // Lista de pessoas infetadas
		list<Pessoa*> L_Quarentena; // Lista de pessoas em quarentena
	
	public:
		//Construtores e destrutores são públicos

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

		bool Gravar_Pessoas(const string& N_Ficheiro_1, const string& N_Ficheiro_2);
		void Mostrar_L_Virus();
		void Mostrar_L_Pessoas();
		void Infectar_Pessoa(Pessoa* pessoa, Virus* virus);
	
};

