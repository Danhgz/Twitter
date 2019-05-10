#include "pch.h"
#include "Lista.h"
#include "ListaAmigos.h"
#include<iostream>
using namespace std;


Lista::Celda::Celda( char *usuario, ListaAmigos *lista){
	anterior = 0;
	siguiente = 0;
	this->usuario = usuario;
	this->amigos = lista;
}

Lista::Celda::~Celda(){
	if(siguiente){
	   delete siguiente;	
	}
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
ostream & Lista::Celda::imprimir( ostream & salida){
	salida << usuario << endl;
	if(siguiente){
		siguiente->imprimir(salida);
	}
	return salida;
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
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
Lista & Lista::pushBack(char * usuario){
	Celda * nueva = new Celda(usuario, 0);
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
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
int Lista::vacia(){
	return !primera;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
Lista::Celda & Lista::buscar(char* usuario) {
	int encontrado = 0;
	Celda * actual = primera;
	if (actual) {
		while (!encontrado && actual) {
			encontrado = (actual->usuario == usuario);
			actual = actual->siguiente;
		}
		actual = actual->anterior;
	}
	else {
		cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión" << endl;
	}
	return *actual;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
int Lista::existe(char* usuario) {
	int encontrado = 0;
	Celda * actual = primera;
	if (actual) {
		while (!encontrado && actual) {
			encontrado = (actual->usuario == usuario);
			actual = actual->siguiente;
		}
	}
	else {
		cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión" << endl;
	}
	return encontrado;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
ostream & Lista::imprimir( ostream & salida){
	salida << "{ ";
	if(primera){
	   primera->imprimir(salida);
	}
	salida << " }";
	return salida;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
int Lista::getMencionesUsuario(char* usuario) {
	float valor = 0.00;
	if (existe(usuario)) {
		valor = buscar(usuario).amigos->primera->menciones;
	}
	else {
		cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión" << endl;
	}
	return valor;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
void Lista::calcularDice() {
	if (primera){
		Celda * actual = primera;
		ListaAmigos::CeldaAmigo * actualAmigo;
		while (actual){
			actualAmigo = actual->amigos->primera;
			while (actualAmigo) {
				actualAmigo->diceResultado = (2 * actualAmigo->menciones) / (getMencionesUsuario(actual->usuario) + getMencionesUsuario(actualAmigo->nombre));
				actualAmigo = actualAmigo->siguiente;
			}
			actual = actual->siguiente;
		}
	}
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
void Lista::ordenar() {
	if (primera) {
		Celda * actual = primera;
		while (actual) {
			burbuja(*actual->amigos);
			actual = actual->siguiente;
		}
	}
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
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
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
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


