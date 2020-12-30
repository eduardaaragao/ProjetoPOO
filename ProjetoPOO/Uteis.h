#include <vector>

class Virus;
class Uteis
{
private:
	Uteis();
public:
	static void MSG(string msg);
	~Uteis();
	static int GetPosicaoAleatoria(int max);
	static bool CompararNomes(const string &n1, const string& n2);
	static bool Probabilidade(double Taxa);
	static Cidade* Conferir_L_Cidade(list<Cidade*>* Lista, string N_Cidade);
	static Virus* Conferir_L_Virus(list<Virus*>* Lista, Virus* Objeto);
	static Pessoa* Conferir_L_Pessoas(list<Pessoa*>* Lista, Pessoa* Objeto);
	//int Contar_Memoria(list<T*>* Lista);
	
	//------------ Libera a Memoria ------------

	template <class T>
	static void Liberar_Memoria(list<T*>* Lista)
	{
		auto IT = Lista->begin();
		while (IT != Lista->end())
		{
			delete(*IT);
			++IT;
		}
		Lista->clear();
	}

	template <class T>
	static void Liberar_Memoria(vector<T*>* Lista)
	{
		auto IT = Lista->begin();
		while (IT != Lista->end())
		{
			delete(*IT);
			++IT;
		}
		Lista->clear();
	}

	//------------ Conta a Memoria ------------

	template <class T>
	static int Contar_Memoria(list<T*>* Lista)
	{
		auto IT = Lista->begin();
		int Cont = 0;
		while (IT != Lista->end())
		{
			Cont += sizeof(*IT);
			Cont += (*IT)->Memoria();
			++IT;
		}
		return Cont;
	}

	template <class T>
	static int Contar_Memoria(vector<T*>* Lista)
	{
		auto IT = Lista->begin();
		int Cont = 0;
		while (IT != Lista->end())
		{
			Cont += sizeof(*IT);
			Cont += (*IT)->Memoria();
			++IT;
		}
		return Cont;
	}

	template <class T>
	static int Contar_Memoria_SL(list<T*>* Lista)
	{
		auto IT = Lista->begin();
		int Cont = 0;
		while (IT != Lista->end())
		{
			Cont += sizeof((*IT));
			++IT;
		}
		return Cont;
	}
};




