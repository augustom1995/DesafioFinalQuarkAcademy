#include "Tienda.h"
#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include <iostream>
using namespace std;

vector<shared_ptr<Prenda>> listadoPrenda;

Tienda::Tienda()
{
	cout << "Nombre de la tienda: ";
	getline(cin, nombreTienda);
	cout << "Direccion de la tienda: ";
	getline(cin, direccion);

	auto _Camisa = make_shared<Camisa>();
	auto _Pantalon = make_shared<Pantalon>();

	listadoPrenda.push_back(_Camisa);
	listadoPrenda.push_back(_Pantalon);
}

Tienda::~Tienda()
{
}


void Tienda::setPrendaSelect(int prenda1, int prenda2, int prenda3, int calidad)
{
	int opcion[2];

	if (prenda1 == 1)
	{
		if (listadoPrenda.front().get()->nombrePrenda != "Camisa")
		{
			int cont = 0;
			for (auto itr = listadoPrenda.cbegin(); itr != listadoPrenda.cend(); itr++)
			{
				if (listadoPrenda.at(cont).get()->nombrePrenda == "Camisa")
				{
					listadoPrenda.at(cont).swap(listadoPrenda.front());
				}
				cont++;
			}
		}

		opcion[0] = prenda2;
		opcion[1] = prenda3;
	}

	else
	{
		if (listadoPrenda.front().get()->nombrePrenda != "Pantalon")
		{
			int cont = 0;
			for (auto itr = listadoPrenda.cbegin(); itr != listadoPrenda.cend(); itr++)
			{
				if (listadoPrenda.at(cont).get()->nombrePrenda == "Pantalon")
				{
					listadoPrenda.at(cont).swap(listadoPrenda.front());
				}
				cont++;
			}
		}

		opcion[0] = prenda2;
		opcion[1] = prenda3;
	}

	listadoPrenda.front().get()->setPrendaTipo(opcion);

	if (calidad == 1)
		listadoPrenda.front().get()->calidad = 1; // Standard
	else
		listadoPrenda.front().get()->calidad = 2; // Premium
}

void Tienda::setUniCot(int unidad, double cotizacion)
{
	listadoPrenda.front().get()->stock -= unidad;
	listadoPrenda.front().get()->precioUnitario = cotizacion;
}


string Tienda::getTienda() const
{
	return nombreTienda + " | " + direccion;
}

void Tienda::getPrenda()
{
	if (!listadoPrenda.empty())
	{
		for (const auto& prendas : listadoPrenda)
		{
			cout << prendas->nombrePrenda << " - " << prendas->stock << endl;
		}
	}
	else
		cout << "No clothes to sell" << endl;
}

int Tienda::getPrendaStock(int prenda)
{
	return listadoPrenda.front().get()->stock;
}

double Tienda::getPrecioUnitario()
{
	return listadoPrenda.front().get()->precioUnitario;
}

void Tienda::getPrendaCombinacion(bool& opcion1, bool& opcion2, bool& calidad)
{
	int camisaSelect = listadoPrenda.front().get()->getPrendaTipo();

	if (camisaSelect == 4) // Corta + Mao
	{
		opcion1 = true;
		opcion2 = true;
	}
	else if (camisaSelect == 5) // Larga + Mao
	{
		opcion1 = false;
		opcion2 = true;
	}
	else if (camisaSelect == 6) // Corta + no Mao
	{
		opcion1 = true;
		opcion2 = false;
	}
	else if (camisaSelect == 7) // Larga + no Mao
	{
		opcion1 = false;
		opcion2 = false;
	}

	if (listadoPrenda.front().get()->calidad == 1)
		calidad = false; // Standard
	else
		calidad = true; // Premium
}
void Tienda::getPrendaCombinacion(bool& opcion1, bool& calidad) // OVERLOAD/SOBRECARGA
{
	int pantalonSelect = listadoPrenda.front().get()->getPrendaTipo();

	if (pantalonSelect == 1) // No chupin
		opcion1 = false;
	else
		opcion1 = true;

	if (listadoPrenda.front().get()->calidad == 1)
		calidad = false; // Standard
	else
		calidad = true; // Premium
}
