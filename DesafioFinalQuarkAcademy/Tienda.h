#pragma once
#ifndef TIENDA_H
#define TIENDA_H
#include <string>
#include <vector>
using namespace std;

class Prenda;

class Tienda
{
private:
	string nombreTienda;
	string direccion;

public:
	Tienda();
	~Tienda();
	void setPrendaSelect(int prenda1, int prenda2, int prenda3, int calidad);
	void setUniCot(int unidad, double cotizacion);
	string getTienda() const;
	void getPrenda();
	int getPrendaStock(int Prenda);
	void getPrendaCombinacion(bool& opcion1, bool& opcion2, bool& calidad); //Camisa
	void getPrendaCombinacion(bool& opcion1, bool& calidad); //Pantalon
	double getPrecioUnitario();

};

#endif // !TIENDA_H
