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
		
ListaAmigos::ListaAmigos(){
  primera = 0;
  ultima = 0;
}
		
ListaAmigos::~ListaAmigos(){
	if(primera){
		delete primera;
	}
}

//ListaAmigos & ListaAmigos::pushFront(char* usuario){
//    CeldaAmigo * nueva = new CeldaAmigo(elemento);
//    nueva->siguiente = primera;
//    if(primera){ // SE VA A COLAR ANTES DEL QUE ESTA DE PRIMERO
//		primera->anterior = nueva;
//	}	
//	else { // LISTA ESTA VACIA
//		ultima = nueva;
//	}
//	primera = nueva;
//	return *this;
//}

//ListaAmigos & ListaAmigos::pushBack(int elemento){
//	CeldaAmigo * nueva = new CeldaAmigo(elemento);
//	nueva ->anterior = ultima;
//	if(ultima){
//	   ultima->siguiente = nueva;	
//	}
//	else {
//		primera = nueva;
//	}
//	ultima = nueva;
//	return *this;
//}

char* ListaAmigos::getFront(){
   char* valor = "-1";
   if(primera){
	  valor = primera->nombre +' '+ primera->menciones; 
   }	
   else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }
	
   return valor;
}

char* ListaAmigos::getBack() {
	char* valor = "-1";
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
	int pos = -1;
	int encontrado = 0;
	CeldaAmigo * actual = primera;
	if(actual){
	   int i = -1;
	   while(!encontrado && actual){
         ++i;		
		 encontrado = (actual->nombre == nombre);
         actual= actual->siguiente;		 
	   }
	   if(encontrado){
		  pos = i;
	   }
	}
	else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 		
	}
	return pos;
}

ListaAmigos &  ListaAmigos::insertar(int pos, int elemento){
	if(pos >= 0){
		if(pos==0){
			pushFront(elemento);
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
					pushBack(elemento);  
				  } 
			   }
			   else {
				   CeldaAmigo * nueva = new CeldaAmigo(elemento);
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

ostream & ListaAmigos::imprimir( ostream & salida){
	salida << "{ ";
	if(primera){
	   primera->imprimir(salida);
	}
	salida << " }";
	return salida;
}
