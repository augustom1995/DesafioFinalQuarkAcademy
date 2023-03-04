#include "Vendedor.h"
#include "Cotizacion.h"
#include "Tienda.h"
#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

vector<shared_ptr<Cotizacion>> cotizacionRegis;
int Cotizacion::codCotizacion = 000;

Vendedor::Vendedor()
{
	cout << "Nombre del vendedor: ";
	getline(cin, nombreVendedor);
	cout << "Apellido del vendedor: ";
	getline(cin, apellidoVendedor);
	cout << "Codigo del vendedor: ";
	cin >> codigoVendedor;
	cin.get();

	while (cin.fail()) {
		cin.clear();
		cin.ignore(999999999999999, '\n');
		cout << "El codigo de vendedor debe de ser numerico: ";
		cin >> codigoVendedor;
		cin.get();
	}

	vendedorTienda = new Tienda();
}

Vendedor::~Vendedor()
{
	delete vendedorTienda;
}

string Vendedor::parseNum(int x)
{
	ostringstream aux;
	aux << x;
	return aux.str();
}

void Vendedor::cotizaPrenda(int& prenda, int unidad)
{
	auto coti = make_shared<Cotizacion>(prenda, this);

	coti->preciosCotizacion(unidad, this);
	cotizacionRegis.push_back(coti);
}


void Vendedor::setPrendaCombSelect(int prenda1, int opcion1, int opcion2, int calidad)
{
	vendedorTienda->setPrendaSelect(prenda1, opcion1, opcion2, calidad);
}

void Vendedor::setCotUnidades(int& prenda, int unidad, double cotizacion)
{
	vendedorTienda->setUniCot(unidad, cotizacion);
	cotizaPrenda(prenda, unidad);
}


string Vendedor::getVendedorTienda()const
{
	return vendedorTienda->getTienda();
}

string Vendedor::getVendedorNomApe()const
{
	return nombreVendedor + " " + apellidoVendedor;
}

int Vendedor::getVendedorCod() const
{
	return codigoVendedor;
}

void Vendedor::getPrendaCombinacion(double& precioInicial, bool& opcion1, bool& opcion2, bool& calidad)
{
	precioInicial = vendedorTienda->getPrecioUnitario();
	vendedorTienda->getPrendaCombinacion(opcion1, opcion2, calidad);
}
void Vendedor::getPrendaCombinacion(double& precioInicial, bool& opcion1, bool& calidad)
{
	precioInicial = vendedorTienda->getPrecioUnitario();
	vendedorTienda->getPrendaCombinacion(opcion1, calidad);
}

int Vendedor::getPrendaStockd(int x)
{
	return vendedorTienda->getPrendaStock(x);
}

string Vendedor::getCotizacionInfo(int seleccion)
{
	return cotizacionRegis.back()->getCotizacion(seleccion);
}

double Vendedor::getPrecioUnitario()
{
	return vendedorTienda->getPrecioUnitario();
}

