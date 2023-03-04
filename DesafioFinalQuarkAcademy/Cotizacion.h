#pragma once
#ifndef COTIZACION_H
#define COTIZACION_H
#include <string>
#include <vector>
using namespace std;

class Vendedor;

class Cotizacion
{
private:
	static int codCotizacion;
	int codigoVendedor, unidadesCotizadas;
	string cotizacionPrenda;
	double cotizado;
	char cotTime[40];

public:
	Cotizacion(int& prenda, Vendedor* codigo);
	~Cotizacion();
	void preciosCotizacion(int& _unidadesCotizadas, Vendedor* _vendedor);
	string getCotizacion(int x);
	string parseNum(double x);
};

#endif // !COTIZACION_H
