#include "ListaAmigos.h"
#include<iostream>
using namespace std;

ListaAmigos::CeldaAmigo::CeldaAmigo() {
	anterior = 0;
	siguiente = 0;
	this->nombre = "";
	this->menciones = 0;
	this->diceResultado = 0;
}

ListaAmigos::CeldaAmigo::CeldaAmigo( string nombre){
	anterior = 0;
	siguiente = 0;
	this->nombre = nombre;	
	this->menciones = 0.0;
	this->diceResultado = 0.0;
}

ListaAmigos::CeldaAmigo::~CeldaAmigo(){
	if(siguiente){
	   delete siguiente;	
	}
}

void ListaAmigos::CeldaAmigo::imprimir() {
	cout << "Amigo: "<<'\t'<< nombre.c_str() << endl <<" Dice: " << '\t' <<diceResultado<<endl << endl;
}

ListaAmigos::ListaAmigos(){
  primera = 0;
  ultima = 0;
}
		
ListaAmigos::~ListaAmigos(){
	if(primera){
		delete primera;
	}
}

ListaAmigos & ListaAmigos::pushBack(string nombre){
	CeldaAmigo * nueva= new CeldaAmigo(nombre);
	nueva ->anterior = ultima;
	if(ultima){
	   ultima->siguiente = nueva;	
	}
	else {
		primera = nueva;
	}
	ultima = nueva;
	return *this;
}

int ListaAmigos::vacia(){
	return !primera;
}

int ListaAmigos::existe(string nombre) {
	int encontrado = 0;
	if (primera) {
		CeldaAmigo * actual = primera;
		if (actual) {
			while (!encontrado && actual) {
				encontrado = (actual->nombre == nombre);
				actual = actual->siguiente;
			}
		}
	}
	return encontrado;
}

ListaAmigos::CeldaAmigo & ListaAmigos::buscar(string nombre){ 
	int encontrado = 0;
	CeldaAmigo * actual= primera;
	if(actual){
	   while(!encontrado && actual){	
		 encontrado = (actual->nombre == nombre);
		 if (!encontrado) {
			 actual = actual->siguiente;
		 }
	   }
	}
	return *actual;
}

ListaAmigos & ListaAmigos::getListaAmigos(){
	return *this;
}

void ListaAmigos::aumentarMenciones(string nombre) {	
	buscar(nombre).menciones++ ;
}

 void ListaAmigos::imprimir( int cantidad) {
	 CeldaAmigo* amigo = primera;
	 for (int i = 0; i < cantidad; i++) {
		 if (amigo != 0) {
			 amigo->imprimir();
		 }
		 if (!amigo->siguiente) {
			 i = cantidad;
		 }
		 amigo = amigo->siguiente;	 
	}
}
