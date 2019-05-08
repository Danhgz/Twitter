// Tarea 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdlib.h>
#include <locale>
using namespace std;

int main()
{
	ifstream archivo;
	string a = "";
	int termino = 0;
	long contador = 0;
	string usuarios[100];
	for (int i = 0; i < 100; i++) {
		usuarios[i] = "";
	}
	string usuario;//[100];
	int contadorPalabras = 0;
	int inicio = 0;
	int final = 0;
	int comas = 0;
	int texto = 0;
	ofstream file;
	file.open("archivo.txt");
	archivo.open("a.txt");
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
			if (usuarios[0] != "") {
				contador++;		//cout << comas <<endl;		
				cout << "Tweet#: " << contador << " ";

				for (int i = 0; i < 100 && usuarios[i] != ""; i++)
				{
					file << usuarios[i];
					file << "\n";
					cout << usuarios[i] << " ";
				}
				cout << endl;
			}

		}
	}
	//system("pause");

}
