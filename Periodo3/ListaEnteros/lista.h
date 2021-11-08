#ifndef LISTA_H
#define LISTA_H
#include <iostream>

class ListaEnteros {
	private:
		int cuenta;
		int capacidad;
		int *items;
		void agrandar();
	public:
		ListaEnteros(int capacidad);
		ListaEnteros();
		ListaEnteros(const ListaEnteros &otraLista);
		~ListaEnteros();
		bool estaVacia();
		int tamanio();
		void insertar(int indice, int item);
		void adjuntar(int item);
		int obtener(int indice);
		bool contiene(int item);
		void imprimirlista();
		
};

ListaEnteros::ListaEnteros(int capacidad) {
	this->cuenta = 0;
	this->capacidad = capacidad;
	this->items = new int[capacidad];
}

ListaEnteros::~ListaEnteros() {
	delete[] items;
}

bool ListaEnteros::estaVacia() {
	return this->cuenta == 0;
}

int ListaEnteros::tamanio() {
	return this->cuenta;
}

int ListaEnteros::obtener(int indice) {
	if(indice < 0  || indice >= this->cuenta) {
		throw "Indice fuera de rango";
	}
	if(this->estaVacia()) {
		throw "No se puede recuperar elementos de una lista vacia";
	}
	return this->items[indice];
}

void ListaEnteros::insertar(int indice, int item) {
	if(indice < 0 || indice > this->cuenta) {
		throw "Indice fuera de rango";
	}
	if(this->cuenta >= this->capacidad) {
		this->agrandar();
	}
	
	for(int i = cuenta - 1; i >= indice; i--) {
		this->items[i+1] = this->items[i];
	}
	
	this->items[indice] = item;
	this->cuenta++;
	
}

















