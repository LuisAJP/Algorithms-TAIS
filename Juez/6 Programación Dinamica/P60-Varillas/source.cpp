#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000;




bool esPosible(const vector<int> &L, const int &T) {

	vector<bool> posible(T + 1, false);
	posible[0] = true;

	for (int i = 1; i < L.size(); ++i) {
		for (int j = T; j >= 1; --j) {
			if (L[i] <= j)
				posible[j] = posible[j] || posible[j - L[i]];
		}
	}
	return posible[T];
}


int numeroTotal(const vector<int> &L, int T){
	vector<int> formas(T + 1, 0);
	int n = L.size();
	formas[0] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = T; j >= 1; --j) {
			if (L[i] <= j)
				formas[j] = formas[j] + formas[j - L[i]];
		}
	}
	return formas[T];

}

//numero minimo de varillas
int minimoVarillas(const vector<int> &L, int T){
	int n = L.size() - 1;
	Matriz<int> varillas(n + 1, T + 1, INF);
	varillas[0][0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		varillas[i][0] = 0;
		for (int j = 1; j <= T; ++j) {
			if (L[i] > j) // no se puede considerar L[i] para obtener varilla j
				varillas[i][j] = varillas[i - 1][j];
			else
				varillas[i][j] = min(varillas[i - 1][j], varillas[i-1][j - L[i]] + 1);
		}
	}
	return varillas[n][T];
}
/*
//tambien es correcto este metodo 
int minimoVarillas(const vector<int> &L, const int &T) {
	std::vector<int> varillas(T + 1, 1e9);

	varillas[0] = 0;

	for (int i = 1; i <= L.size()-1; ++i) {
		for (int j = T; j >= 1; --j) {
		//for (int j = L[i]; j <=T; j++) {//no entiendo pq si sustituyo esta linea por la anterior da wrong answer
		//for (int j = 1; j <=T; j++) {//no entiendo pq si sustituyo esta linea por la anterior da wrong answer
			if (L[i] <= j)
				varillas[j] = std::min(varillas[j], varillas[j - L[i]] + 1);
		}
	}
	return varillas[T];
}
*/


//minimo coste de varillas
int minimoCoste(const vector<int> &L, const vector<int> &C, int T){
	int n = L.size() - 1;
	Matriz<int> varillas(n + 1, T + 1, INF);
	varillas[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		varillas[i][0] = 0;
		for (int j = 1; j <= T; ++j) {
			if (L[i] > j)
				varillas[i][j] = varillas[i - 1][j];
			else
				varillas[i][j] = min(varillas[i - 1][j], varillas[i-1][j - L[i]] + C[i]);
		}
	}
	return varillas[n][T];
}


bool resuelveCaso() {
	int N, T;
	cin >> N >> T;
	if (!cin)return false;
	vector<int> L(N + 1);
	vector<int> C(N + 1);
	for (int i = 1; i < N + 1; i++)
		cin >> L[i] >> C[i];
	bool posible = esPosible(L, T);
	int total = numeroTotal(L, T);
	
	int minNumero = minimoVarillas(L, T);
	int minCoste = minimoCoste(L, C, T);
	if (posible)
		cout << "SI" << " " << total << " " << minNumero << " " << minCoste << "\n";
	else
		cout << "NO" << "\n";
	
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
