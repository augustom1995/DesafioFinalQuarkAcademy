#pragma once
#ifndef PANTALON_H
#define PANTALON_H
#include "Prenda.h"

class Pantalon : public Prenda
{
private:
	bool chupin;

public:
	Pantalon();
	~Pantalon() override;
	void setPrendaTipo(int seleccion[]) override;
	int getPrendaTipo() override;

};

#endif // !PANTALON_H
