#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000;



//
//bool esPosible(const vector<tInfo> &v, const int &L) {
//
//	vector<bool> posible(L + 1, false);
//	posible[0] = true;
//
//	for (int i = 1; i < v.size(); ++i) {
//		for (int j = L; j >= 1; --j) {
//			if (v[i].l <= j)
//				posible[j] = posible[j] || posible[j - v[i].l];
//		}
//	}
//	return posible[L];
//}
//
//
//int numeroTotal(const vector<tInfo> &v, int L){
//	vector<int> formas(L + 1, 0);
//	int n = v.size();
//	formas[0] = 1;
//
//	for (int i = 1; i < n; ++i) {
//		for (int j = L; j >= 1; --j) {
//			if (v[i].l <= j)
//				formas[j] = formas[j] + formas[j - v[i].l];
//		}
//	}
//	return formas[L];
//
//}

//numero minimo de varillas
int minimoVarillas(const vector<int> &L, int T){
	/*
	int n = L.size();
	vector<int>varillas(T + 1, INF);
	varillas[0] = 0;
	for (int i = 1; i < n; i++){
		for (int j = L[i]; j <= T; ++j) {
			varillas[j] = min(varillas[j], varillas[j - L[i]] + 1);
		}
	}
	return varillas[T];*/
	int n = L.size() - 1;
	Matriz<int> varillas(n + 1, T + 1, INF);
	varillas[0][0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		varillas[i][0] = 0;
		for (int j = 1; j <= T; ++j) {
			if (L[i] > j) // no se puede considerar M[i] para pagar j
				varillas[i][j] = varillas[i - 1][j];
			else
				varillas[i][j] = min(varillas[i - 1][j], varillas[i-1][j - L[i]] + 1);
		}
	}


	vector<int> cuantas(n + 1, 0); // 1-based
	int i = n; int j = T;
	while (j > 0) { // no se ha pagado todo
		if (L[i] <= j && varillas[i][j] != varillas[i - 1][j]) {
			// tomamos una moneda de tipo i
			++cuantas[i];
			j = j - L[i];
		}
		else // no tomamos más monedas de tipo i
			--i;
	}
	//vector<bool> cuales(n+ 1, false);
	//int resto = T;
	//for (int i = n; i >= 1; --i) {
	//	if (varillas[i][resto] != varillas[i - 1][resto]) {
	//		// sí cogemos objeto i
	//		cuales[i] = true;
	//		resto = resto - L[i];
	//	}
	//	else {// no cogemos objeto i
	//		cuales[i] = false;
	//	}
	//}

	return varillas[n][T];
}



//minimo coste de varillas
int minimoCoste(const vector<int> &L, const vector<int> &C, int T){
	int n = L.size() - 1;
	Matriz<int> varillas(n + 1, T + 1, INF);
	varillas[0][0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		varillas[i][0] = 0;
		for (int j = 1; j <= T; ++j) {
			if (L[i] > j) // no se puede considerar M[i] para pagar j
				varillas[i][j] = varillas[i - 1][j];
			else
				varillas[i][j] = min(varillas[i - 1][j], varillas[i-1][j - L[i]] + C[i]);
		}
	}
	vector<int> cuantas(n + 1, 0); // 1-based
	int i = n; int j = T;
	while (j > 0) { // no se ha pagado todo
		if (L[i] <= j && varillas[i][j] != varillas[i - 1][j]) {
			// tomamos una moneda de tipo i
			++cuantas[i];
			j = j - L[i];
		}
		else // no tomamos más monedas de tipo i
			--i;
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

	int minNumero = minimoVarillas(L, T);
	int minCoste = minimoCoste(L,C,T);

	/*bool posible = esPosible(v, L);
	int total = numeroTotal(v, L);
	
	int minCoste = minimoCoste(v, L);
	if (posible)
		cout << "SI" << " " << total << " " << minNumero << " " << minCoste << "\n";
	else
		cout << "NO" << "\n";
	*/
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
