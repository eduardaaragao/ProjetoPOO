#include "Virus.h"
class Covid : public Virus
{
public:
	//----- M�todos -----
	Covid(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data* data_inicio);
	~Covid();
};

