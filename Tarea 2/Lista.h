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

	  void burbuja(ListaAmigos&);
	  void swap(ListaAmigos::CeldaAmigo*, ListaAmigos::CeldaAmigo*);
	  class Celda {

	  public:
		  Celda * anterior;
		  Celda * siguiente;
		  string  usuario;
		  ListaAmigos * amigos;
		  Celda(string);
		  ~Celda();
		  void imprimir(string, int);
	  };

	public:
		Lista();
		~Lista();
		Lista & pushBack(string);
		float getMencionesUsuario(string); // Retorna primer elemento sin borrar
		Celda & buscar(string); // Recibe usuario retorna Celda de dado usuario
		int existe(string); 
		void ordenar();
		void imprimir( string ,int );
		void calcularDice();
		void agregar(string,string );
		int vacia();
};
#endif