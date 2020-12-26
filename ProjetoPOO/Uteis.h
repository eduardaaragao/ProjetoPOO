class Uteis
{
private:
	Uteis();
public:
	static void MSG(string msg);
	~Uteis();
	static int GetPosicaoAleatoria(int max);
	static bool CompararNomes(const string &n1, const string& n2);
};