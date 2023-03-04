#include "Presenter.h"
#include "IView.h"
#include "Vendedor.h"

Presenter::Presenter(IView* view) : m_View(view), _pVendedor(new Vendedor())
{
}

Presenter::~Presenter()
{
	delete _pVendedor;
}

void Presenter::aCotizar(int& _prenda, int _unidad, double _cotizacion)
{
	_pVendedor->setCotUnidades(_prenda, _unidad, _cotizacion);
}

void Presenter::prendasInfo(int prenda1, int prenda2, int prenda3, int calidad)
{
	_pVendedor->setPrendaCombSelect(prenda1, prenda2, prenda3, calidad);
}

string Presenter::getDatosTienda() const
{
	return _pVendedor->getVendedorTienda();
}

string Presenter::verVendedorNombre() const
{
	return _pVendedor->getVendedorNomApe();
}

int Presenter::verCodigoVendedor() const
{
	return _pVendedor->getVendedorCod();
}

int Presenter::rStock(int prendaS)
{
	return _pVendedor->getPrendaStockd(prendaS);
}

string Presenter::cotizacionInfo(int seleccion)
{
	return _pVendedor->getCotizacionInfo(seleccion);
}

double Presenter::verPrecioUnitario()
{
	return _pVendedor->getPrecioUnitario();
}
