#include <iostream>
using namespace std;

extern void MSG(string Mensagem);

using namespace std;
void Menu()
{
	char OP;
	cout << "\t\t\tSGV - Sistema Gerenciador de Vírus" << endl;

	cout << "A - Lancar virus aleatoriamente em uma pessoa" << endl;

	cin >> OP;

	OP = toupper(OP);

	switch (OP)
	{
	case 'A':
		cout << "Opcao A" << endl;
		break;
	case 'V':
		cout << "Opcao V" << endl;
		break;
	case 'F':
		cout << "Opcao F" << endl;
		break;
	case 'Q':
		cout << "Opcao Q" << endl;
		break;
	case 'I':
		cout << "Opcao I" << endl;
		break;
	default:
		cout << "Pressione uma opcao, por favor " << endl;
		break;
	}
}