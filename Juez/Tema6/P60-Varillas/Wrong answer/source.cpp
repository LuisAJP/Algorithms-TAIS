#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000;

typedef struct {
	int l;
	int c;

}tInfo;

bool operator < (tInfo a, tInfo b){
	return a.l < b.l;
}

bool esPosible(const vector<tInfo> &v, const int &L) {

	vector<bool> posible(L + 1, false);
	posible[0] = true;

	for (int i = 1; i < v.size(); ++i) {
		for (int j = L; j >= 1; --j) {
			if (v[i ].l <= j)
				posible[j] = posible[j] || posible[j - v[i].l];
		}
	}
	return posible[L];
}


int numeroTotal(const vector<tInfo> &v, int L){
	vector<int> formas(L + 1, 0);
	int n = v.size();
	formas[0] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = L; j >= 1; --j) {
			if (v[i].l <= j)
				formas[j] = formas[j] + formas[j - v[i].l];
		}
	}
	return formas[L];

}
//numero minimo de varillas
int minimoVarillas(const vector<tInfo> &v, int L){
	int n = v.size();
	vector<int>varillas(L+1,INF);
	varillas[0] = 0;
	for (int i = 1; i < n; i++){
		for (int j = v[i].l; j <= L; ++j) {
			varillas[j] = min(varillas[j], varillas[j - v[i].l] + 1);
		}
	}
	return varillas[L];
}

//numero minimo de varillas
int minimoCoste(const vector<tInfo> &v, int L){
	int n = v.size();
	vector<int>varillas(L + 1, INF);
	varillas[0] = 0;
	for (int i = 1; i < n; i++){
		for (int j = v[i].l; j <= L; ++j) {
			varillas[j] = min(varillas[j], varillas[j - v[i].l] + v[i].c);
		}
	}
	return varillas[L];
}



bool resuelveCaso() {
	int N, L;
	cin >> N >> L;
	if (!cin)return false;
	vector<tInfo> v(N+1);
	for (int i = 1; i < N+1; i++)
		cin >> v[i].l>>v[i].c;
	bool posible = esPosible(v,L);
	int total=	numeroTotal(v,L);
	int minNumero=minimoVarillas(v,L);
	int minCoste=minimoCoste(v, L);
	if (posible)
		cout << "SI"<<" "<< total << " " << minNumero << " " << minCoste << "\n";
	else
		cout<<"NO" << "\n";
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
