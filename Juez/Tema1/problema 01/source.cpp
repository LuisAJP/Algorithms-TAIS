#include <iostream>
#include <fstream>
using namespace std;
#include "bintree_eda.h"

/*
Tema:1
Problema 1 ¿Esta el arbol equilibrado?
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

//El coste es lineal O(n), donde n es el numero de nodos, en todos los casos recorre todos los nodos del arbol, en cada recorrido
//comprueba que se cumple la condicion de equilibrio (la diferencia de alturas de sus dos hijos es como mucho 1)

bool esEquilibrado(const bintree<char> &a, int &alt){
	//Caso base
	if (a.empty()){
		alt = 0;
		return true;
	}
	bool iz, dr, r = false;
	int altIz=0,altDr=0;
	//Caso Recursivo
	iz = esEquilibrado(a.left(),altIz);
	dr = esEquilibrado(a.right(),altDr);
	r =abs(altIz-altDr)<=1;
	alt = 1 + max(altIz, altDr);
	return r*iz*dr;
}

void resuelveCaso() {
	bintree<char> a = leerArbol('.');
	int altura=0;
	if (esEquilibrado(a,altura))
		cout << "SI";
	else
		cout << "NO";
	cout << "\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
