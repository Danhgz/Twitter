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
		  Celda(char*, ListaAmigos*);
		  ~Celda();
		  ostream & imprimir(ostream &);
	  };

	public:
		Lista();
		~Lista();
		Lista & pushBack(char*);
		int getMencionesUsuario(char*); // Retorna primer elemento sin borrar
		Celda & buscar(char*); // Recibe usuario retorna Celda de dado usuario
		int existe(char*); 
		ostream & imprimir( ostream & );
		void ordenar();
		void burbuja(ListaAmigos&);
		void swap(ListaAmigos::CeldaAmigo*, ListaAmigos::CeldaAmigo*);
		void calcularDice();
		int vacia();
};
#endif