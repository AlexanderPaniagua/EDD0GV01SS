/*
Practica 01 : Piedra, papel, tijera, lagarto, spock

Alumnos: Jose Humberto Hernandez
*/

/*#include "stdafx.h"*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

const string centinela = "XXX";

typedef enum { piedra, papel, tijera, lagarto, spock } tElemento;
typedef enum { empate, ganaMaquina, ganaHumano } tResultado;

int menu();
bool localizacionJugador(string nombre);
bool mostrarReglas();
string elementoAstring(tElemento elemento);
tElemento eleccionHumano();
tElemento eleccionMaquina();
tElemento eleccionAelemento(int opcion);
tResultado quienGana(tElemento maquina, tElemento humano);
tResultado juego();


int main()
{
	string nombre;
	bool registro = false, reglas = false;
	int opcionMenu, resultadoJuego;
	int ganadas = 0, perdidas = 0, empates = 0, partidas = 0; //Usadas para contador

	cout << "Introduce tu nombre: ";
	cin >> nombre;
	registro = localizacionJugador(nombre);

	if (registro)
	{
		opcionMenu = menu();
		while (opcionMenu != 0)
		{
			if (opcionMenu == 1)
			{
				resultadoJuego = juego();
				switch (resultadoJuego)
				{
				case empate: empates++; break;
				case ganaMaquina: perdidas++; break;
				case ganaHumano: ganadas++; break;
				}
			}
			if (opcionMenu == 2)
			{
				reglas = mostrarReglas();
				if (!reglas) { cout << "¡No se ha podido abrir el archivo!" << endl; }
			}
			opcionMenu = menu();
		}

		cout << endl << "-----------------" << endl << "Finalizando juego..." << endl << endl;
		partidas = empates + ganadas + perdidas;
		cout << "Has jugado: " << partidas << " partidas" << endl;
		cout << "Empatadas: " << empates << endl << "Ganadas: " << ganadas << endl << "Perdidas: " << perdidas << endl;
	}

	cout << endl << "Pulse cualquier tecla...";
	cin.get();
	cin.get();

	return 0;
}

int menu()
{
	int opcion;

	cout << "1-Jugar una partida" << endl << "2-Ver reglas" << endl << "0-Salir" << endl << "Opcion: ";
	cin >> opcion;

	while (opcion < 0 || opcion > 2)
	{
		if (opcion < 0 || opcion > 2)
		{
			cout << endl << "Opcion no valida" << endl << endl;
		}
		cout << "1-Jugar una partida" << endl << "2-Ver reglas" << endl << "0-Salir" << endl << "Opcion: ";
		cin >> opcion;
	}

	return opcion;
}

bool mostrarReglas()
{
	ifstream reglas;
	string palabra;
	reglas.open("reglas.txt"); //Abrir archivo

	bool abierto = reglas.is_open();
	if (abierto)
	{
		getline(reglas, palabra);
		while (palabra != centinela)
		{
			cout << palabra << endl;
			getline(reglas, palabra);
		}
	}
	reglas.close(); //Cerrar archivo

	return abierto;
}

bool localizacionJugador(string nombre)
{
	ifstream registro;
	string palabra;
	bool nombreCorrecto;

	registro.open("registro.txt");
	if (registro.is_open())
	{
		registro >> palabra;
		while (palabra != centinela && palabra != nombre)
		{
			registro >> palabra;
		}

		if (palabra == nombre)
		{
			cout << endl << "Usuario CORRECTO\n" << endl;
			nombreCorrecto = true;
		}
		else
		{
			cout << endl << "Usuario ERRONEO\n" << endl;
			nombreCorrecto = false;
		}

	}
	else
	{
		cout << "El archivo de registro no se ha podido abrir" << endl;
		nombreCorrecto = false;
	}

	registro.close();

	return (nombreCorrecto);
}

tElemento eleccionHumano()
{
	int opcionNum;
	tElemento eleccion;

	cout << endl << "-----------------" << endl << "Elige una opcion:" << endl << endl;
	cout << "1-Piedra\n2-Papel\n3-Tijera\n4-Lagarto\n5-Spock\n" << endl << "Elemento: ";
	cin >> opcionNum;

	while (opcionNum < 1 || opcionNum > 5)
	{
		cout << endl << "Opcion no valida" << endl;
		cout << endl << "-----------------" << endl << "Elige una opcion:" << endl << endl;
		cout << "1-Piedra\n2-Papel\n3-Tijera\n4-Lagarto\n5-Spock\n" << endl << "Elemento: ";
		cin >> opcionNum;
	}

	opcionNum--;
	eleccion = eleccionAelemento(opcionNum);

	return eleccion;
}

tElemento eleccionMaquina()
{
	int opcionNum;
	tElemento eleccion;

	srand(time(NULL));
	opcionNum = rand() % (5); //De 0 a 4: rand() % (limite superior + 1)

	eleccion = eleccionAelemento(opcionNum);

	return eleccion;
}

string elementoAstring(tElemento elemento)
{
	string stringElemento;

	switch (elemento)
	{
	case piedra: stringElemento = "Piedra"; break;
	case papel: stringElemento = "Papel"; break;
	case tijera: stringElemento = "Tijera"; break;
	case lagarto: stringElemento = "Lagarto"; break;
	case spock: stringElemento = "Spock"; break;
	}

	return stringElemento;
}

tResultado quienGana(tElemento maquina, tElemento humano)
{
	tResultado resultado;
	if (humano == maquina)
	{
		resultado = empate;
	}
	else if ((humano == piedra) && ((maquina == tijera) || (maquina == lagarto)))
	{
		resultado = ganaHumano;
	}
	else if ((humano == papel) && ((maquina == piedra) || (maquina == spock)))
	{
		resultado = ganaHumano;
	}
	else if ((humano == tijera) && ((maquina == papel) || (maquina == lagarto)))
	{
		resultado = ganaHumano;
	}
	else if ((humano == lagarto) && ((maquina == papel) || (maquina == spock)))
	{
		resultado = ganaHumano;
	}
	else if ((humano == spock) && ((maquina == piedra) || (maquina == tijera)))
	{
		resultado = ganaHumano;
	}
	else
	{
		resultado = ganaMaquina;
	}

	return resultado;
}

tResultado juego()
{
	tElemento humano, maquina;
	string stringHumano, stringMaquina;
	tResultado resultado;

	humano = eleccionHumano();
	stringHumano = elementoAstring(humano);

	maquina = eleccionMaquina();
	stringMaquina = elementoAstring(maquina);

	cout << endl << "-----------------" << endl;
	cout << endl << "Has elegido: " << stringHumano << endl << endl << "La maquina ha elegido: " << stringMaquina << endl;
	resultado = quienGana(maquina, humano);

	switch (resultado)
	{
	case empate:
		cout << endl << "Empate" << endl << endl;
		break;
	case ganaMaquina:
		cout << endl << "Has perdido" << endl << endl;
		break;
	case ganaHumano:
		cout << endl << "Has ganado" << endl << endl;
		break;
	}
	cout << "-----------------" << endl;

	return resultado;
}

tElemento eleccionAelemento(int opcion)
{
	tElemento eleccion;
	switch (opcion)
	{
	case 0: eleccion = piedra; break;
	case 1: eleccion = papel; break;
	case 2: eleccion = tijera; break;
	case 3: eleccion = lagarto; break;
	case 4: eleccion = spock; break;
	}

	return eleccion;
}
