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
			char * nombre;
		    float menciones;
			float diceResultado;
			CeldaAmigo * anterior;
			CeldaAmigo * siguiente;
			CeldaAmigo();
			CeldaAmigo(char*, float);
			~CeldaAmigo();
			ostream & imprimir( ostream &);
	}; 


	public:
		ListaAmigos();
		~ListaAmigos();
		ListaAmigos & pushBack(char*);
		ListaAmigos::CeldaAmigo & buscar(char*); // Recibe elemento retorna pos, o -1 si no esta
		int existe(char*); 
		ListaAmigos & getListaAmigos();
		void aumentarMenciones(char*); //Recibe nombre y aumenta su numero de menciones devuelve menciones
		ostream & imprimir( ostream & );
		int vacia();
};
#endif