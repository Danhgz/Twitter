#include "pch.h"
#include "Lista.h"
#include<iostream>
using namespace std;


Lista::Celda::Celda( char *usuario, ListaAmigos lista){
	anterior = 0;
	siguiente = 0;
	this->usuario = usuario;	
}

Lista::Celda::~Celda(){
	if(siguiente){
	   delete siguiente;	
	}
}

ostream & Lista::Celda::imprimir( ostream & salida){
	salida << *usuario << " ";
	if(siguiente){
		siguiente->imprimir(salida);
	}
	return salida;
}
		
Lista::Lista(){
  primera = 0;
  ultima = 0;
}
/**
Descripcion: Construye una lista a partir de un vector con n elementos
Requiere: Que exista el metodo pushBack
@param n Cantidad de elementos
@param elementos Puntero al inicio del vector con los n elementos
**/
Lista::Lista(int n, char * elementos){
   primera=0;
   ultima=0;
   for(int i=0; i< n; ++i){
	   elementos = new char[i];
	  this->pushBack( elementos );  	
   }	
} 

Lista::Lista(const Lista & otra){
   primera=0;
   ultima=0;	
   Celda * actual = otra.primera;
   while(actual){
      this->pushBack( actual->usuario);	
	   actual = actual->siguiente;
   }
}
		
Lista::~Lista(){
	if(primera){
		delete primera;
	}
}


Lista & Lista::pushBack(char * usuario){
	Celda * nueva = new Celda(usuario, ListaAmigos());
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

char* Lista::getFront(){
   char * valor = 0;
   if(primera){
	  valor = primera->usuario; 
   }	
   else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }
	
   return valor;
}

char * Lista::getBack(){
   char* valor = 0;
   if(ultima){
	  valor = ultima->usuario; 
   }	
   else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }	
   return valor;	
}


int Lista::vacia(){
	return !primera;
}



char * Lista::buscar(char* usuario){
	char * valor = 0;
	int encontrado = 0;
	Celda * actual = primera;
	if(actual){
	   int i = -1;
	   while(!encontrado && actual){
         ++i;		
		 encontrado = (actual->usuario == usuario);
         actual= actual->siguiente;		 
	   }
	   if(encontrado){
		   valor = actual->usuario;
	   }
	}
	else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 		
	}
	return valor;
}

char*  Lista::get(int pos){
	char* valor = 0;
	if(pos >=0){
       Celda * actual = primera;
       int i = 0;
       while(actual && i<pos){
		   ++i;
		   actual = actual->siguiente;
	   }	   
	   if(!actual){
		  cerr << "Advertencia: Se retorna un 0 por omisión posición invalida"<<endl; 				 
	   }
	   else {
		  valor = actual->usuario; 
	   }
	}
	else {
	  cerr << "Advertencia: Se retorna un 0 por omisión posición invalida"<<endl; 				
	}
	
	return valor;
}

ostream & Lista::imprimir( ostream & salida){
	salida << "{ ";
	if(primera){
	   primera->imprimir(salida);
	}
	salida << " }";
	return salida;
}
