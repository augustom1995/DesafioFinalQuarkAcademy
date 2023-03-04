#include "View.h"
#include "Presenter.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

#define intCotMax 2147483647  //No se podra cotizar mas alla de este valor
#define SEPARADOR "-------------------------------------------------------------"

View::View()
{
	m_Presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
}

void View::header(string _MainMenu)
{
	system("CLS");
	showTextWithSection("COTIZADOR EXPRESS  - " + _MainMenu);
	if (_MainMenu == "MENU PRINCIPAL")
	{
		showTextWithSection(m_Presenter->getDatosTienda());
		showTextWithSection(m_Presenter->verVendedorNombre() + " | " + parseNum(m_Presenter->verCodigoVendedor()));
	}
	else
	{
		showTextWithSection("Presiona 3 para volver al menu principal");
	}
}

void View::showMainMenu()
{
	header("MENU PRINCIPAL");
	showTextWithSection("\nSELECCIONE UNA OPCION DEL MENU:");
	showText("1) Historial de cotizaciones");
	showText("2) Realizar cotizacion");
	showTextWithSection("3) Salir");

	int seleccion = 0;
	do {
		cin.clear();
		cin >> seleccion;
	} while (seleccion <= 0 || seleccion > 3 || cin.fail());

	if (seleccion == 1)
	{
		system("CLS");

		if (conReg == false) {

			showTextWithSection("COTIZADOR EXPRESS  - HISTORIAL DE COTIZACIONES");
			sinRegistros();
			int input = 0;
			selectOption(input, 3, 3);

		}
		else {

			//verCotizaDOS();////////////////////////////////////////////////
			imprimirColeccion();////////////////////////////////////////////////////////////////
			int input = 0;
			selectOption(input, 3, 3);
		}

	}
	else if (seleccion == 2) {
		cotizacionMenu();
	}

	else if (seleccion == 3) {
		exit(0);
	}
}

void View::sinRegistros() {

	cout << "Aun no se han efectuado cotizaciones" << endl;
	showText(SEPARADOR);
	showTextWithSection("Presiona 3 para volver al menu principal");


}

string View::parseNum(double x) //double a string
{
	ostringstream aux;
	aux << x;
	return aux.str();
}

void View::cotizacionMenu()
{
	errorCant = false;
	header("Cotizacion");
	showTextWithSection("\nPASO 1: Seleccione la prenda a cotizar:");
	showText("1) Camisa");
	showTextWithSection("2) Pantalon");
	int seleccion = 0, opcion1 = 0, opcion2 = 0, calidad = 0;
	selectOption(seleccion, 1, 3);
	header("Cotizacion");

	if (seleccion == 1) // Camisa
	{
		showTextWithOptions("\nPASO 2.a: La camisa a cotizar, ¿Es manga corta?");
		selectOption(opcion1, 1, 3);
		showTextWithOptions("\nPASO 2.b: La camisa a cotizar, ¿Es cuello Mao?");
		selectOption(opcion2, 1, 3);
		cout << "\n" << endl;
	}
	else if (seleccion == 2) // Pantalon
	{
		showTextWithOptions("\nPASO 2: El pantalon a cotizar ¿Es chupin?");
		selectOption(opcion1, 1, 3);
		opcion2 = 0;
		cout << "\n" << endl;
	}

	header("Cotizacion");

	// MENU: STANDARD - PREMIUM
	showTextWithSection("\nPASO 3: Seleccione la calidad de la prenda:");
	showText("1) Standard");
	showText("2) Premium");
	selectOption(calidad, 1, 3);

	m_Presenter->prendasInfo(seleccion, opcion1, opcion2, calidad);

	int stock = m_Presenter->rStock(seleccion);

	header("Cotizacion");
	double cotizacion = 0;
	showTextWithSection("PASO 4: Ingrese el precio unitario de la prenda a cotizar:");
	selectOption(cotizacion, 1, intCotMax);
	header("Cotizacion");
	int unidadesAcotizar = 0;
	showText("INFORMACION\nEXISTEN " + parseNum(stock) + " UNIDADES EN STOCK DE LA PRENDA SELECCIONADA");
	showText("");
	showTextWithSection("PASO 5: Ingrese la cantidad de unidades a cotizar:");
	errorCant = true;
	selectOption(unidadesAcotizar, 1, m_Presenter->rStock(seleccion));

	m_Presenter->aCotizar(seleccion, unidadesAcotizar, cotizacion);
	verCotizaDOS();

	errorCant = false;
	seleccion = 0;
	selectOption(seleccion, 3, 3);//MENU
}

void View::verCotizaDOS()
{
	header("Registro de Cotizacion");
	showText("Numero de identificacion: " + m_Presenter->cotizacionInfo(1));
	showText("Fecha y hora de la cotizacion: " + m_Presenter->cotizacionInfo(2));
	showText("Codigo del vendedor: " + m_Presenter->cotizacionInfo(3));
	showText("Prenda cotizada: " + m_Presenter->cotizacionInfo(4));
	showText("Precio Unitario: $" + parseNum(m_Presenter->verPrecioUnitario()));
	showText("Cantidad de unidades cotizadas: " + m_Presenter->cotizacionInfo(5));
	showText("Precio Final: $" + m_Presenter->cotizacionInfo(6));
	coleccion();
	conReg = true;
	showText(SEPARADOR);
	showTextWithSection("Presione 3 para volver al menu principal");
}

void View::coleccion() {

	colec[base] = "Numero de identificacion: " + m_Presenter->cotizacionInfo(1);
	colec[base + 1] = "Fecha y hora de la cotizacion: " + m_Presenter->cotizacionInfo(2);
	colec[base + 2] = "Codigo del vendedor: " + m_Presenter->cotizacionInfo(3);
	colec[base + 3] = "Prenda cotizada: " + m_Presenter->cotizacionInfo(4);
	colec[base + 4] = "Precio Unitario: $" + parseNum(m_Presenter->verPrecioUnitario());
	colec[base + 5] = "Cantidad de unidades cotizadas: " + m_Presenter->cotizacionInfo(5);
	colec[base + 6] = "Precio Final: $" + m_Presenter->cotizacionInfo(6);
	base = base + 7;

}

void View::imprimirColeccion() {

	header("Registro de Cotizacion");

	for (int i = 1; i < base + 1; i++) {

		showText(colec[i - 1]);

		if (i % 7 == 0) {

			showText(SEPARADOR);
			//cout << "\n" << endl;
		}
	}
	showText(SEPARADOR);
	showTextWithSection("Presione 3 para volver al menu principal");

}



void View::selectOption(int& input, int min, int max)
{
	do
	{
		cin.clear();
		cin.ignore(intCotMax, '\n');
		cin >> input;
		if (input  < min && errorCant || input > max && errorCant)
			showTextWithSection("POR FAVOR, INGRESE UN NUMERO QUE SEA MAYOR A CERO Y MENOR O IGUAL AL STOCK DISPONIBLE.");
	} while (input < min || input > max && max != 0 || cin.fail());

	if (input == 3) {
		showMainMenu();
	}
}

void View::selectOption(double& input, int min, int max)
{
	do
	{
		cin.clear();
		cin.ignore(intCotMax, '\n');
		cin >> input;
	} while (input < min || input > max || cin.fail());

	if (input == 3) {
		showMainMenu();
	}
}

void View::showText(const string& text)
{
	cout << text << endl;
}
void View::showTextWithSection(const string& text)
{
	cout << text << endl;
	cout << SEPARADOR << endl;
}

void View::showTextWithOptions(const string& text)
{
	cout << text << endl;
	cout << SEPARADOR << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl;
	cout << SEPARADOR << endl;
}
