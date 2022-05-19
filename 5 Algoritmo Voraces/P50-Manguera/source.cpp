#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;


/*
Tema:3
Problema50 Agujeros en la manguera
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/



//
//	Tiene un coste O(N), N= numero de agujeros de la manguera.
//
bool resuelveCaso() {
	int N,L;
	cin >> N>>L;
	if (!cin) return false;
	vector<int>v(N);
	for (int i = 0; i < N;i++){
		cin >> v[i];
	}
	int parches = 1;
	int D = 0;
	D = v[0] + L;
	for (int i = 1; i < N; i++){
		if (D < v[i]){
			parches++;
			D = v[i] + L;
		}
	}
	cout << parches<<'\n';
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
