#ifndef _LISTAAMIGOS
#define _LISTAAMIGOS
#include<iostream>
using namespace std;
// ListaAmigos Doblemente enlazada con cantidad de menciones
class ListaAmigos {
   class CeldaAmigo;    // Prototipo
   private:
      CeldaAmigo * primera;
	  CeldaAmigo * ultima;
	  //void ordenar();

	  friend class Lista;

      class CeldaAmigo {
	     public:
			char * nombre;
		    int menciones;
			int diceResultado;
			CeldaAmigo * anterior;
			CeldaAmigo * siguiente;
			CeldaAmigo(char*, int);
			~CeldaAmigo();
			ostream & imprimir( ostream &);
			void ordenar();
	  }; 


	public:
		ListaAmigos();
		~ListaAmigos();
		ListaAmigos & pushBack(char*);
		char* getFront(); // Retorna primer elemento sin borrar
		char* getBack();
		char* buscar(char*); // Recibe elemento retorna pos, o -1 si no esta
		ListaAmigos & insertar(char*, int, int); // Recibe elemento y menciones
		ListaAmigos & buscarAumentar(char*); //Recibe nombre y aumenta su numero de menciones devuelve menciones
		char* get(int); // Recibe pos y retorna elemento -1 si no esta
		ostream & imprimir( ostream & );
		int vacia();
};
#endif