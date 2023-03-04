#include "Pantalon.h"
#include <iostream>

Pantalon::Pantalon()
{
	nombrePrenda = "Pantalon";
	stock = 2000;

}

Pantalon::~Pantalon()
{
}

void Pantalon::setPrendaTipo(int seleccion[])
{
	if (seleccion[0] == 1) {
		chupin = true;
	}
	else {
		chupin = false;
	}
}

int Pantalon::getPrendaTipo()
{
	if (!chupin) {
		return 1;
	}
	else {
		return 2;
	}
}

