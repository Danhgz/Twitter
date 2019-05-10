#include "pch.h"
#include "ListaAmigos.h"
#include<iostream>
using namespace std;

ListaAmigos::CeldaAmigo::CeldaAmigo() {
	anterior = 0;
	siguiente = 0;
	this->nombre = 0;
	this->menciones = 0;
	this->diceResultado = 0;
}

ListaAmigos::CeldaAmigo::CeldaAmigo( char *nombre, float menciones){
	anterior = 0;
	siguiente = 0;
	this->nombre = nombre;	
	this->menciones = menciones;
	this->diceResultado = 0;
}

ListaAmigos::CeldaAmigo::~CeldaAmigo(){
	if(siguiente){
	   delete siguiente;	
	}
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
ostream & ListaAmigos::CeldaAmigo::imprimir( ostream & salida){
	salida << nombre << ": " << menciones << endl;
	if(siguiente){
		siguiente->imprimir(salida);
	}
	return salida;
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
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
ListaAmigos & ListaAmigos::pushBack(char* nombre){
	CeldaAmigo * nueva = new CeldaAmigo(nombre, 1);
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
int ListaAmigos::vacia(){
	return !primera;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
int ListaAmigos::existe(char* nombre) {
	int encontrado = 0;
	CeldaAmigo * actual = primera;
	if (actual) {
		while (!encontrado && actual) {
			encontrado = (actual->nombre == nombre);
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
ListaAmigos::CeldaAmigo & ListaAmigos::buscar(char* nombre){ 
	int encontrado = 0;
	CeldaAmigo * actual= primera;
	if(actual){
	   while(!encontrado && actual){	
		 encontrado = (actual->nombre == nombre);
         actual= actual->siguiente;		 
	   }
		actual = actual->anterior;
	}
	else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 		
	}
	return *actual;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
ListaAmigos & ListaAmigos::getListaAmigos(){
	return *this;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
void ListaAmigos::aumentarMenciones(char* nombre) {
	this->buscar(nombre).menciones++ ;
}
/*
*@Descripcion:
*@Param salida:
*@Return:
*/
ostream & ListaAmigos::imprimir( ostream & salida){
	salida << "{ ";
	if(primera){
	   primera->imprimir(salida);
	}
	salida << " }";
	return salida;
}
