#include "lista.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdlib.h>
#include <locale>
using namespace std;

int main()
{
	Lista lista;
	ifstream archivo;
	string a = "";
	int termino = 0;
	string usuarios[100];
	for (int i = 0; i < 100; i++) {
		usuarios[i] = "";
	}
	string usuario;
	int contadorPalabras = 0;
	int inicio = 0;
	int comas = 0;
	int texto = 0;
	string user = "";
	int consultas=0;
	ofstream file;
	archivo.open("tuitsTareaCI0113.txt");
	if (!archivo) {
		cerr << "No se puede abrir el archivo\n";
		exit(1);   
	}
	else {
		getline(archivo, a);
		while (!archivo.eof()) {
			usuario = "";
			comas = 0;
			contadorPalabras = 0;
			for (int i = 0; i < 100; i++) {
				usuarios[i] = "";
			}
			while (comas < 13 && termino == 0) {
				getline(archivo, a);


				inicio = -1;
				for (int i = 0; i < a.length(); i++) {
					if (a.substr(i, 1) == "\"" && texto == 0) {
						texto = 1;
					}
					else if (a.substr(i, 1) == "\"" && texto == 1) {
						texto = 0;
					}
					if (a.substr(i, 1) == "," && texto == 0) {
						comas++;
					}
					if (a.substr(i, 2) == " @" && inicio == -1) {
						inicio = i;
						i++;
					}
					else if (!(isalnum(a[i]) || a[i] == '_') && inicio != -1) {
						usuarios[contadorPalabras] = usuario;
						inicio = -1;
						usuario = "";
						contadorPalabras++;
					}
					if (inicio != -1) {
							usuario += a.at(i);
							}
				}
				if (comas == 0) {
					termino = 1;
				}
			}
			
			for (int i = 0; usuarios[i]!= ""; i++)
			{
				for (int j = 0; usuarios[j]!= ""; j++)
				{
					lista.agregar(usuarios[i], usuarios[j]);
				}
			}
		}
		lista.calcularDice();
		lista.ordenar();
		cout << "Digite el usuario a consultar:"<<endl;
		cin >> user;
		cout << "Cuantos mejores amigos desea ver?" << endl;
		cin >> consultas;
		lista.imprimir(user, consultas);
	}

	system("pause");

}
