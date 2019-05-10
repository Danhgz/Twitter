#ifndef _LISTAAMIGOS
#define _LISTAAMIGOS
#include<iostream>
using namespace std;
// ListaAmigos Doblemente enlazada con cantidad de menciones
class ListaAmigos {
   class CeldaAmigo;    // Prototipo

   private:
	friend class Lista;
	CeldaAmigo * primera;
	CeldaAmigo * ultima;
	  
    class CeldaAmigo {
		public:
			string nombre;
		    float menciones;
			float diceResultado;
			CeldaAmigo * anterior;
			CeldaAmigo * siguiente;
			CeldaAmigo();
			CeldaAmigo(string);
			~CeldaAmigo();
			void imprimir();
	}; 

	public:
		ListaAmigos();
		~ListaAmigos();
		ListaAmigos & pushBack(string);
		ListaAmigos::CeldaAmigo & buscar(string); // Recibe elemento retorna pos, o -1 si no esta
		int existe(string); 
		ListaAmigos & getListaAmigos();
		void aumentarMenciones(string); //Recibe nombre y aumenta su numero de menciones devuelve menciones
		void imprimir( int);
		int vacia();
};
#endif