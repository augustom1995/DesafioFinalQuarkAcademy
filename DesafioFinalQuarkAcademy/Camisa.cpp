#include "Camisa.h"
#include <iostream>

Camisa::Camisa()
{
	nombrePrenda = "Camisa";
	stock = 1000;
}

Camisa::~Camisa()
{
}

void Camisa::setPrendaTipo(int eleccion[])
{
	if (eleccion[0] == 1) {
		mangaCorta = true;
	}
	else {
		mangaCorta = false;
	}

	if (eleccion[1] == 1) {
		cuelloMao = true;
	}
	else {
		cuelloMao = false;
	}
}

int Camisa::getPrendaTipo()
{
	int camisaElegida = 0, _corta = 1, _larga = 2, mao = 3, normal = 5;

	if (mangaCorta) {
		camisaElegida = camisaElegida + _corta;
	}
	else {
		camisaElegida = camisaElegida + _larga;
	}

	if (cuelloMao) {
		camisaElegida = camisaElegida + mao;
	}
	else {
		camisaElegida = camisaElegida + normal;
	}

	return camisaElegida;
}


