#include "Covid.h"

Covid::Covid(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data* data_inicio)
 :Virus(nome, raio_contagio, taxa_contagio, perigosidade, data_inicio)
{
}

Covid::~Covid()
{

}

int Covid::Contar_Virus(Virus* X) 
{
	if (Get_Nome_Virus() == X->Get_Nome_Virus())
		return 1;
	return 0;

}