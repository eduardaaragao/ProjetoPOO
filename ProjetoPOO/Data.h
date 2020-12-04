#pragma once
class Data
{
	private:
		//----- Variaveis -----

		short int Dia, Mes, Ano;
	
	public:

		//----- Construtores e Destrutores -----
		Data(short int dia, short int mes, short int ano)
		{
			Dia = dia;
			Mes = mes;
			Ano = ano;
		}
		virtual ~Data();

		//----- Gets -----

		short int Get_Dia() { return Dia; }
		short int Get_Mes() { return Mes; }
		short int Get_Ano() { return Ano; }
};

