#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;


/*
Tema:2
Problema 20 Lo que cuesta sumar
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


//O(NlogN ) donde N es el numero de nodos del monticulo
//Cuando leemos los elementos y usamos la operacion push para insertar los elementos en el monticulo, el coste es NLogN, el coste del push es logN y N es el numero de nodos
//luego para calcular el esfuerzo el coste tambien es Nlog N,donde N es el numero de nodos, tanto la operacion push y pop tienen coste logN
//sumando los costes, el coste total queda O(NlogN ) 

bool resuelveCaso() {
	int N;
	long long int elem, esfuerzo=0,a,b;

	cin >> N; // número de elementos
	if (N == 0) // no hay más casos
		return false;
	PriorityQueue<long long int> cola;
	// leemos los registros
	for (int i = 0; i < N; ++i) {
		cin >> elem;
		cola.push(elem);
	}
	while (cola.size() != 1){
		a = cola.top();
		cola.pop();
		b = cola.top();
		cola.pop();
		esfuerzo = esfuerzo + a + b;
		cola.push(a + b);
	}
	cout <<esfuerzo<< "\n";
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
