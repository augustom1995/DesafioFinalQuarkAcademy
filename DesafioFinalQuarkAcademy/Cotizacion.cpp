#include "Cotizacion.h"
#include "Vendedor.h"
#include "Presenter.h"
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

Cotizacion::Cotizacion(int& prenda, Vendedor* _vendedor)
{
	codCotizacion++;
	time_t tz = time(0);
	ctime_s(cotTime, sizeof cotTime, &tz);
	codigoVendedor = _vendedor->getVendedorCod();

	if (prenda == 1)
		cotizacionPrenda = "Camisa";
	else
		cotizacionPrenda = "Pantalon";

	cotizado = 0;
	unidadesCotizadas = 0;
}

Cotizacion::~Cotizacion()
{
}

void Cotizacion::preciosCotizacion(int& _unidadesCotizadas, Vendedor* _vendedor)
{
	bool _mangaCorta, _cuelloMao, _chupin, _premium;
	double _precioInicial = 0;
	unidadesCotizadas = _unidadesCotizadas;
	cotizado = 0;

	string cadena = cotizacionPrenda;
	if (cadena.find("Camisa") != string::npos)
	{
		_vendedor->getPrendaCombinacion(_precioInicial, _mangaCorta, _cuelloMao, _premium);

		if (_mangaCorta) // -10%
		{
			_precioInicial = _precioInicial - (_precioInicial * 10) / 100;
			cadena = cadena + " - manga corta - ";
		}
		if (_cuelloMao)
		{
			_precioInicial = _precioInicial + (_precioInicial * 3) / 100; // +3%
			cadena = cadena + "cuello Mao - ";
		}
		if (!_mangaCorta)
			cadena = cadena + " - manga larga - ";
		if (!_cuelloMao)
			cadena = cadena + "sin cuello mao - ";
	}
	else if (cadena.find("Pantalon") != string::npos)
	{
		_vendedor->getPrendaCombinacion(_precioInicial, _chupin, _premium);

		if (_chupin)
		{
			_precioInicial = _precioInicial - (_precioInicial * 12) / 100; // -12% 
			cadena = cadena + " - pantalon chupin - ";
		}
		else if (!_chupin)

			cadena = cadena + " - pantalon no chupin - ";
	}

	cotizado = _precioInicial;

	if (_premium) // Premium
	{
		cotizado = cotizado + (_precioInicial * 30) / 100; //+30% premium
		cadena = cadena + "Premium";
	}
	else // en caso de ser standar no afecta al precio
	{
		cotizado = _precioInicial;
		cadena = cadena + "Standard";
	}

	cotizacionPrenda = cadena;
	cotizado = cotizado * unidadesCotizadas; // cotizado
}

string Cotizacion::parseNum(double x)
{
	ostringstream aux;
	aux << x;
	return aux.str();
}

string Cotizacion::getCotizacion(int x)
{
	if (x == 1)
		return parseNum(codCotizacion);
	else if (x == 2)
		return cotTime;
	else if (x == 3)
		return parseNum(codigoVendedor);
	else if (x == 4)
		return cotizacionPrenda;
	else if (x == 5)
		return parseNum(unidadesCotizadas);
	else if (x == 6)
		return parseNum(cotizado);
}


