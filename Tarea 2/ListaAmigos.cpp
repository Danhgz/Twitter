#include "pch.h"
#include "ListaAmigos.h"
#include<iostream>
using namespace std;

ListaAmigos::CeldaAmigo::CeldaAmigo( char *nombre, int menciones){
	anterior = 0;
	siguiente = 0;
	this->nombre = nombre;	
	this->menciones = menciones;
}

ListaAmigos::CeldaAmigo::~CeldaAmigo(){
	if(siguiente){
	   delete siguiente;	
	}
}

ostream & ListaAmigos::CeldaAmigo::imprimir( ostream & salida){
	salida << nombre << ": " << menciones << endl;
	if(siguiente){
		siguiente->imprimir(salida);
	}
	return salida;
}
void ListaAmigos::CeldaAmigo::ordenar() {

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

ListaAmigos & ListaAmigos::pushBack(char* nombre){
	CeldaAmigo * nueva = new CeldaAmigo(nombre, 0);
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

char* ListaAmigos::getFront(){
   char* valor =0;
   if(primera){
	  valor = primera->nombre +','+ primera->menciones; 
   }	
   else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }
	
   return valor;
}

char* ListaAmigos::getBack() {
	char* valor = (char*)"-";
	if (primera) {
		valor = ultima->nombre + ' ' + ultima->menciones;
	}
	else {
		cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión" << endl;
	}

	return valor;
}


int ListaAmigos::vacia(){
	return !primera;
}

char* ListaAmigos::buscar(char* nombre){
	//int pos = -1;
	char * valor = 0;
	int encontrado = 0;
	CeldaAmigo * actual= primera;
	if(actual){
	   int i = -1;
	   while(!encontrado && actual){
         ++i;		
		 encontrado = (actual->nombre == nombre);
         actual= actual->siguiente;		 
	   }
	   if(encontrado){
		   valor = actual->nombre;
	   }
	}
	else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 		
	}
	return valor;
}

ListaAmigos &  ListaAmigos::insertar(char* nombre, int menciones, int pos){
	if(pos >= 0){
		if(pos==0){
			pushBack(nombre);
		}
		else { // pos es > 0
			if(!vacia()){ // tiene al menos un elemento y pos > 0
			   CeldaAmigo * actual = primera;
			   int i = 0;
			   while(actual && i < pos){
				  ++i;
				  actual = actual->siguiente;
			   }
               if(!actual){
				  if(i==pos){
					pushBack(nombre);  
				  } 
			   }
			   else {
				   CeldaAmigo * nueva = new CeldaAmigo(nombre, menciones);
				   nueva->siguiente = actual;
				   nueva->anterior = actual->anterior;
				   actual->anterior = nueva;
				   nueva->anterior->siguiente = nueva;
			   }
			}
		}		
	}	
	return *this;
}


char*  ListaAmigos::get(int pos){
	char* valor = 0;
	if(pos >=0){
       CeldaAmigo * actual = primera;
       int i = 0;
       while(actual && i<pos){
		   ++i;
		   actual = actual->siguiente;
	   }	   
	   if(!actual){
		  cerr << "Advertencia: Se retorna un 0 por omisión posición invalida"<<endl; 				 
	   }
	   else {
		  valor = actual->nombre; 
	   }
	}
	else {
	  cerr << "Advertencia: Se retorna un 0 por omisión posición invalida"<<endl; 				
	}
	
	return valor;
}

ListaAmigos & ListaAmigos::buscarAumentar(char* nombre) {
	char * valor = 0;
	int encontrado = 0;
	CeldaAmigo * actual = primera;
	if (actual) {
		int i = -1;
		while (!encontrado && actual) {
			++i;
			encontrado = (actual->nombre == nombre);
			actual = actual->siguiente;
		}
		if (encontrado) {
			valor = actual->nombre;
			++actual->menciones;
		}
	}
	else {
		cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión" << endl;
	}
	return *this;
}

ostream & ListaAmigos::imprimir( ostream & salida){
	salida << "{ ";
	if(primera){
	   primera->imprimir(salida);
	}
	salida << " }";
	return salida;
}
