#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000;

int ebanisto(const vector<int> &v, const int &N) {
	Matriz<int> E(N + 2, N + 2);
	Matriz<int> C(N + 2, N + 2);

	for (int d = 2; d <= N + 1; ++d) {
		for (int i = 0; i <= N - d + 1; ++i) {
			int mejor = INF;
			int aux = 0;
			int j = i + d;
			for (int k = i + 1; k <= j-1; ++k) {
				aux = E[i][k] + E[k][j];
				if (aux < mejor) {
					mejor = aux;
					C[i][j] = k;
				}
			}
			mejor += 2 * (v[j] - v[i]);
			E[i][j] = mejor;
		}
	}
	return E[0][N + 1];
}

bool resuelveCaso() {
	int L;//longitud del tablon
	int N;//numero de cortes
	cin >> L >> N;
	if (L == 0 && N == 0) return false;
	vector<int> v(N + 2);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];
	v[0] = 0;
	v[N + 1] = L;
	cout << ebanisto(v, N) << "\n";

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
