#pragma once
#include"Virus.h"
#include"Pessoa.h"

class SGestao
{
	private:
		//-----Variaveis-----
		list<Pessoa *> Lista_Pessoas;
		list<Virus *> Lista_Virus;
		//-----Funcoes-----
		
	public:
		bool Load(const string &N_Ficheiro);
		//Colocar Privada Depois
		SGestao();
		virtual ~SGestao();
		void Mostrar_L_Virus();
		void Mostrar_L_Pessoas();
};

