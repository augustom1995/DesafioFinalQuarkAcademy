#pragma once
#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <string>
#include <vector>
using namespace std;

class Tienda;
class Cotizacion;

class Vendedor
{
private:

	string nombreVendedor;
	string apellidoVendedor;
	int codigoVendedor;
	Tienda* vendedorTienda;

public:
	Vendedor();
	~Vendedor();
	void cotizaPrenda(int& prenda, int unidad);
	string parseNum(int x);
	void setPrendaCombSelect(int prenda1, int opcion1, int opcion2, int calidad);
	void setCotUnidades(int& prenda, int unidad, double cotizacion);
	string getVendedorTienda()const;
	string getVendedorNomApe() const;
	int getVendedorCod() const;
	void getPrendaCombinacion(double& precioInicial, bool& opcion1, bool& opcion2, bool& calidad); //Camisa
	void getPrendaCombinacion(double& precioInicial, bool& opcion1, bool& calidad); // Pantalon
	int getPrendaStockd(int x);
	string getCotizacionInfo(int x);
	double getPrecioUnitario();
};
#endif // !VENDEDOR_H
