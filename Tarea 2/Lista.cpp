#include "pch.h"
#include "Lista.h"
#include<iostream>
using namespace std;


Lista::Celda::Celda( char *Usuario, ListaAmigos lista){
	anterior = 0;
	siguiente = 0;
	this->usuario = Usuario;	
}

Lista::Celda::~Celda(){
	if(siguiente){
	   delete siguiente;	
	}
}

ostream & Lista::Celda::imprimir( ostream & salida){
	salida << elemento << " ";
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
Lista::Lista(int n, const int * elementos){
   primera=0;
   ultima=0;
   for(int i=0; i< n; ++i){
	  this->pushBack( elementos[i] );  	
   }	
} 

Lista::Lista(const Lista & otra){
   primera=0;
   ultima=0;	
   Celda * actual = otra.primera;
   while(actual){
      this->pushBack( actual->elemento);	
	   actual = actual->siguiente;
   }
}
		
Lista::~Lista(){
	if(primera){
		delete primera;
	}
}

Lista & Lista::pushFront(int elemento){
    Celda * nueva = new Celda(elemento);
    nueva->siguiente = primera;
    if(primera){ // SE VA A COLAR ANTES DEL QUE ESTA DE PRIMERO
		primera->anterior = nueva;
	}	
	else { // LISTA ESTA VACIA
		ultima = nueva;
	}
	primera = nueva;
	return *this;
}

Lista & Lista::pushBack(int elemento){
	Celda * nueva = new Celda(elemento);
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

int Lista::getFront(){
   int valor = -1;
   if(primera){
	  valor = primera->elemento; 
   }	
   else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }
	
   return valor;
}

int Lista::getBack(){
   int valor = -1;
   if(ultima){
	  valor = ultima->elemento; 
   }	
   else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }	
   return valor;	
}

int  Lista::popFront(){
   int valor = -1;
   if(primera){ // HAY UNA CELDA DE PRIMERA QUE HAY QUE REMOVER
	  valor = primera->elemento; 
	  Celda * victima = primera;
	  primera = victima->siguiente;
	  if(primera){ // EXISTE UNA CELDA QUE QUEDA COMO LA NUEVE PRIMERA
		 primera->anterior = 0;
	  }
	  else { // SOLO HABIA UNA CELDA
		 ultima = 0; 
	  }
	  victima->siguiente = 0; // DESCONECTA DEL RESTO DE LA LISTA
	  delete victima; // MANDA A DESTRUIR LA CELDA
   }	
   else { // ERROR PORQUE NO HAY NADIE DE PRIMERO
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }
	
   return valor;	
}

int Lista::vacia(){
	return !primera;
}

int Lista::popBack(){
   int valor = -1;
   if(ultima){
	  valor = ultima->elemento; 
	  Celda * victima = ultima;
	  ultima = ultima->anterior;
	  if(ultima){
		 ultima->siguiente = 0;
	  }
	  else {
		 primera = 0;
	  }
	  delete victima;
   }	
   else {
	  cerr << "Advertencia: <<Lista vacía>> Se retorna un valor de -1 por omisión"<<endl; 
   }
   return valor;		
}

int Lista::buscar(int elemento){
	int pos = -1;
	int encontrado = 0;
	Celda * actual = primera;
	if(actual){
	   int i = -1;
	   while(!encontrado && actual){
         ++i;		
		 encontrado = (actual->elemento == elemento);
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

Lista &  Lista::insertar(int pos, int elemento){
	if(pos >= 0){
		if(pos==0){
			pushFront(elemento);
		}
		else { // pos es > 0
			if(!vacia()){ // tiene al menos un elemento y pos > 0
			   Celda * actual = primera;
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
				   Celda * nueva = new Celda(elemento);
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

Lista &  Lista::borrar(int pos){
	if(!vacia()){
		if(pos>=0){
			if(pos==0){
			   popFront();
			}
			else {
			   Celda * victima = 0;
			   Celda * actual = primera;
               int i = 0;
               while(!victima && actual){
				   if(i==pos){
					  victima = actual;   
				   }
				   i++;
				   actual = actual->siguiente;
			   }
               if(victima){
				   if(!(victima->siguiente)){
					   popBack();
				   }   
				   else {
					   victima->anterior->siguiente = victima->siguiente;
					   victima->siguiente->anterior = victima->anterior;
					   victima->siguiente = 0;
					   delete victima;
				   }
			   }			   
			}
		}
	
	}
    return *this;
}

int  Lista::get(int pos){
	int valor = 0;
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
		  valor = actual->elemento; 
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
