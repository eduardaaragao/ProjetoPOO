#pragma once
class Ponto
{
	friend class SGestao;
	friend class Pessoa;
	//-----Variaveis-----
	int X, Y;
	//-----Fun��es-----
	Ponto(int x, int y);
	virtual ~Ponto();
};

