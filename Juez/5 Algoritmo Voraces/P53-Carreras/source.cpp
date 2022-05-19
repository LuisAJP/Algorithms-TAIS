#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>//sort
#include<functional>//greater or less
#include<vector>
using namespace std;


/*
Tema:3
Problema54 Carreras de coches
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/




//Tiene un coste O(NLogN + N), N= numero de pilas
void resuelveCaso() {
	int N, C;
	cin >> N >> C;
	vector<int>v(N);
	for (int i = 0; i < N; i++){
		cin >> v[i];
	}
	// Ordenamos de menor a mayor, tiene coste O(NLogN)
	sort(v.begin(), v.end(), less<>());
	int coches = 0;
	int j = N-1;
	//Coste O(N)
	for (int i = 0; i<j; i++){
		if (v[i] + v[j] >= C) {
			j--;
			++coches;
		}
	}
	cout << coches << "\n";
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (unsigned i = 0; i < numCasos; i++){
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
