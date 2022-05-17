#include <iostream>
#include <vector>
#include <fstream>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000; // 10^9

//Coste: O(n3) en tiempo y O(1) en espacio adicional.
void Floyd(Matriz<int> const& G, Matriz<int> & C,
	Matriz<int> & camino) {
	int n = G.numfils() - 1;
	// inicialización
	C = G;
	camino = Matriz<int>(n + 1, n + 1, 0);
	// actualizaciones de la matriz
	for (int k = 1; k <= n; ++k)
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j) {
		int temp = C[i][k] + C[k][j];
		if (temp < C[i][j]) { // es mejor pasar por k
			C[i][j] = temp;
			camino[i][j] = k;
		}
	}
}
void imp_camino_int(int i, int j, Matriz<int> const& camino) {
	int k = camino[i][j];
	if (k > 0) {
		imp_camino_int(i, k, camino);
		cout << " " << k;
		imp_camino_int(k, j, camino);
	}
}

void imprimir_caminos(Matriz<int> const& C,
	Matriz<int> const& camino) {
	int n = C.numfils() - 1;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	if (i != j && C[i][j] < INF) {
		cout << "Camino de " << i << " a " << j << "\n";
		cout << " Coste: " << C[i][j] << "\n";
		cout << " " << i;
		imp_camino_int(i, j, camino);
		cout << " " << j << "\n";
	}
}


bool resuelveCaso() {
	int V, E;
	cin >> V >> E;
	if (!cin) return false;
	Matriz<int> grafo(V + 1, V + 1, INF);
	for (int u = 1; u <= V; ++u)
		grafo[u][u] = 0;
	int u, v, coste;
	for (int i = 0; i < E; ++i) { // leer aristas
		cin >> u >> v >> coste;
		grafo[u][v] = coste;
	}
	Matriz<int> C(0, 0); Matriz<int> camino(0, 0);
	Floyd(grafo, C, camino);
	imprimir_caminos(C, camino);
	return true;
}

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
