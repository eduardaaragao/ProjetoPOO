#include "Virus.h"
class Covid : public Virus
{
public:
	//----- Métodos -----
	Covid(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, short int taxa_cura, Data* data_inicio);
	~Covid();

	//------------------

};

