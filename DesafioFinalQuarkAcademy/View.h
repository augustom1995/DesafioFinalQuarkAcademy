#pragma once
#ifndef VIEW_H
#define VIEW_H
#include "IView.h"
#include <string>
using namespace std;

class Presenter;

class View : public IView
{
private:
	Presenter* m_Presenter;
	bool conReg, errorCant;
	void header(string _MainMenu);
	void showMainMenu();
	void cotizacionMenu();
	void verCotizaDOS();
	void sinRegistros();


public:
	View();
	~View();
	void showText(const string& text);
	void selectOption(int& input, int min, int max);
	void selectOption(double& input, int min, int max);
	void showTextWithSection(const string& text);
	void showTextWithOptions(const string& text);
	string parseNum(double x);
	string colec[100];
	int base = 0;
	void coleccion();
	void imprimirColeccion();
};
#endif // !VIEW_H
