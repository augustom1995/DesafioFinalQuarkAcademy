#pragma once
#ifndef PRESENTER_H
#define PRESENTER_H
#include <string>
using namespace std;

class IView;
class Vendedor;

class Presenter
{
private:
	IView* m_View = nullptr;

public:
	Presenter(IView* view);
	~Presenter();
	Vendedor* _pVendedor;
	void prendasInfo(int prenda1, int prenda2, int prenda3, int calidad);
	void aCotizar(int& _prenda, int _unidad, double _cotizacion);
	string getDatosTienda() const;
	string verVendedorNombre() const;
	int verCodigoVendedor() const;
	int rStock(int prendaS);
	string cotizacionInfo(int seleccion);
	double verPrecioUnitario();

};

#endif // !PRESENTER_H
