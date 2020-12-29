
class T;
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
	static Cidade* Conferir_L_Cidade(list<Cidade*> Lista, string N_Cidade);
	static Virus* Conferir_L_Virus(list<Virus*> Lista, Virus* Objeto);
	static Pessoa* Conferir_L_Pessoas(list<Pessoa*> Lista, Pessoa* Objeto);
	//T* Conferir_Lista(list<T*> Lista, T* Objeto);
};