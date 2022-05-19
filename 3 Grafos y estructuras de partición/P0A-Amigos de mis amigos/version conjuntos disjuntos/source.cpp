#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#include "ConjuntosDisjuntos.h"


//El coste es O(E), donde E es el numero de parejas
void resuelveCaso() {
	int V, E;
	cin >> V >> E;
	int maximo = 0;
	ConjuntosDisjuntos G(V + 1);
	int v, w;
	//Coste es O(E), donde E es el numero de parejas
	for (int i = 0; i < E; ++i) {
		cin >> v >> w;
		G.unir(v, w);	// La union tiene un coste de O(1);
		maximo = max(G.tam(v), maximo);	// averiguar el tam tiene un coste de O(1);
	}
	cout<<maximo <<'\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos = 0;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}


	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
