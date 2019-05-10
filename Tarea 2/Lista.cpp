#include "Lista.h"
#include "ListaAmigos.h"
#include<iostream>
using namespace std;

Lista::Celda::Celda( string usuario){
	anterior = 0;
	siguiente = 0;
	this->usuario = usuario;
	this->amigos = new ListaAmigos();
}

Lista::Celda::~Celda(){
	this;
	if(siguiente){
	   delete siguiente;
	}
	delete amigos;

}

 void Lista::Celda::imprimir( string otro ,int cantidad){
	 cout << "Usuario: " << usuario.c_str() << endl<< endl;
		amigos->imprimir(cantidad) ;

}
		
Lista::Lista(){
  primera = 0;
  ultima = 0;
}
		
Lista::~Lista(){
	if(primera){
		delete primera;
	}

}
void Lista::agregar(string otro, string amigo) {
	if (!existe(otro)) {
		pushBack(otro);	
    }
	
	if (!buscar(otro).amigos->existe(amigo)) {
		buscar(otro).amigos->pushBack(amigo);
	}
	buscar(otro).amigos->aumentarMenciones(amigo);
}

Lista & Lista::pushBack(string usuario){
	Celda * nueva =new Celda(usuario);
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

int Lista::vacia(){
	return !primera;
}

Lista::Celda & Lista::buscar(string usuario) {
	int encontrado = 0;
	Celda * actual = primera;
	if (actual) {
		while (!encontrado && actual) {
			encontrado = (actual->usuario == usuario);
			if (!encontrado) {
				actual = actual->siguiente;
			}
		}
	}
	return *actual;
}

int Lista::existe(string usuario) {
	int encontrado = 0;
	Celda * actual = primera;
	if (actual) {
		while (!encontrado && actual) {
			encontrado = (actual->usuario == usuario);
			actual = actual->siguiente;
		}
	}
	return encontrado;
}

void Lista::imprimir( string otro, int cantidad){
	if (existe(otro)) {
		buscar(otro).imprimir(otro, cantidad);
	}
	else {
		cout << "No existe el usuario buscado.";
	}
}

float Lista::getMencionesUsuario(string usuario) {
	float valor = 0.00;
	Celda *user=0;
	if (existe(usuario)) {
		user = &buscar(usuario);
		valor=user->amigos->buscar(usuario).menciones;
	}
	return valor;
}

void Lista::calcularDice() {
	float x = 0;
	float y = 0;
	if (primera){
		Celda * actual = primera;
		ListaAmigos::CeldaAmigo * actualAmigo;
		while (actual){
			actualAmigo = actual->amigos->primera;
			while (actualAmigo) {
				x = getMencionesUsuario(actual->usuario);
				y = getMencionesUsuario(actualAmigo->nombre);
				actualAmigo->diceResultado = (2 * actualAmigo->menciones) /( (x + y));
				actualAmigo = actualAmigo->siguiente;
			}
			actual = actual->siguiente;
		}
	}
}

void Lista::ordenar() {
	if (primera) {
		Celda * actual = primera;
		while (actual) {
			burbuja(*actual->amigos);
			actual = actual->siguiente;
		}
	}
}

void Lista::burbuja(ListaAmigos &lista) {
	ListaAmigos::CeldaAmigo *marcador;
	ListaAmigos::CeldaAmigo *comparador;
	marcador = lista.primera;
	comparador = marcador;
	while (marcador->siguiente != 0) {
		while (comparador->siguiente!= 0) {
			if (comparador->diceResultado < comparador->siguiente->diceResultado) {
				swap(comparador, comparador->siguiente);
			}
			comparador = comparador->siguiente;
		}
		comparador = lista.primera;
		marcador = marcador->siguiente;
	}
}

void Lista::swap(ListaAmigos::CeldaAmigo * amigo1, ListaAmigos::CeldaAmigo * amigo2) {
	ListaAmigos::CeldaAmigo aux;
	aux.nombre = amigo1->nombre;
	aux.menciones = amigo1->menciones;
	aux.diceResultado = amigo1->diceResultado;
	amigo1->nombre = amigo2->nombre;
	amigo1->menciones = amigo2->menciones;
	amigo1->diceResultado = amigo2->diceResultado;
	amigo2->nombre = aux.nombre;
	amigo2->menciones = aux.menciones;
	amigo2->diceResultado = aux.diceResultado;
}


