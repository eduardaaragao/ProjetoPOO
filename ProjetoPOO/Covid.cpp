#include "Covid.h"

Covid::Covid(string nome, short int raio_contagio, short int taxa_contagio, short int perigosidade, Data* data_inicio)
 :Virus(nome, raio_contagio, taxa_contagio, perigosidade, data_inicio)
{
}

Covid::~Covid()
{

}