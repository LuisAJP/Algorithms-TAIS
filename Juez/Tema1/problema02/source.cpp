#include <iostream>
#include <fstream>
using namespace std;
#include "bintree_eda.h"

/*
Tema:1
Problema 2 ¿Es un arbol AVL?
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

//El coste es lineal O(n), donde n es el numero de nodos, en todos los casos recorre todos los nodos del arbol, en cada recorrido
//comprueba que se cumple la condicion de equilibrio (la diferencia de alturas de sus dos hijos es como mucho 1)
template <class T>
bool esEquilibrado(const bintree<T> &a, int &alt){
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

//El coste en el mejor de los casos es constante O(1) porque si existe algun nodo que no cumple la condicion se sale del bucle y en el peor de los casos si es avl tiene
//que recorrer todo los elementos del vector y seria lineal O(n), el bucle da N vueltas cada una de ellas de coste constante y por tanto el coste está en O(N)
bool esAVL(const bintree<int> & a) {
	if (a.empty()) return true;
	auto v = a.inorder();
	for (int i = 1; i < v.size(); i++) {
		if (v[i] <= v[i - 1]) //si fuera menor o igual si hubiera elementos repetidos en algun caso
			return false;
	}
	return true;
}

void resuelveCaso() {
	bintree<int> a = leerArbol(-1);
	int altura=0;
	if (esEquilibrado(a, altura) && esAVL(a))
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
