#pragma once
#ifndef PRENDA_H
#define PRENDA_H
#include <string>
using namespace std;

class Prenda
{

public:
	string nombrePrenda;
	double precioUnitario;
	int calidad;
	int stock;
	Prenda();
	virtual ~Prenda();
	virtual void setPrendaTipo(int eleccion[]) = 0;
	virtual int getPrendaTipo() = 0;
};
#endif // !PRENDA_H
