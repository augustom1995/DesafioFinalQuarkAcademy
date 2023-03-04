#pragma once
#ifndef CAMISA_H
#define CAMISA_H
#include "Prenda.h"

class Camisa : public Prenda
{
private:
	bool mangaCorta, cuelloMao;

public:
	Camisa();
	~Camisa() override;
	void setPrendaTipo(int eleccion[]) override;
	int getPrendaTipo() override;
};

#endif // !CAMISA_H
