#ifndef _LISTA
#define _LISTA
#include<iostream>
#include "ListaAmigos.h"
using namespace std;
// Lista doblemente enlazada con valores de tipo Usuario
class Lista {
   class Celda;    // Prototipo.
   
   private:
      Celda * primera;
	  Celda * ultima;
	  class Celda {

	  public:
		  Celda * anterior;
		  Celda * siguiente;
		  char * usuario;
		  ListaAmigos * amigos;
		  Celda(char*, ListaAmigos);
		  ~Celda();
		  ostream & imprimir(ostream &);
	  };


	public:
		Lista();
		Lista(int, char *); // Recibe un entero con la cantidad de elementos y un vector
		Lista(const Lista &);
		~Lista();
		//Lista & pushFront(char*);
		Lista & pushBack(char*);
		char* getFront(); // Retorna primer elemento sin borrar
		char* getBack();
		char* get(int);
		char* buscar(char*); // Recibe usuario retorna pos , o -1 si no esta
		ostream & imprimir( ostream & );
		int vacia();
};
#endif