#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include <climits>
#include "ConjuntosDisjuntos.h"
#include <functional>
using namespace std;


/*
Tema:3
Problema38 Ratones en un laberinto
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

struct Huerta { int benef, plazo, id; };

bool operator>(Huerta const& a, Huerta const& b) {
	return a.benef > b.benef;
}

vector<int> resolver(vector<Huerta> const& huertas) {
	int N = huertas.size();
	vector<int> libre(N + 1);
	vector<int> plan(N + 1); // 0 es que no está usado
	ConjuntosDisjuntos particion(N + 1);
	for (int i = 0; i <= N; ++i) {
		libre[i] = i;
	}
	// recorrer las huertas de mayor a menor beneficio
	for (int i = 0; i < N; ++i) {
		int c1 = particion.buscar(min(N, huertas[i].plazo));
		int m = libre[c1];
		if (m != 0) { // podemos colocar la huerta i
			plan[m] = huertas[i].id;
			int c2 = particion.buscar(m - 1);
			particion.unir(c1, c2);
			libre[c1] = libre[c2];
		}
	}
	// compactamos la solución
	vector<int> sol;
	for (int i = 1; i <= N; ++i) {
		if (plan[i] > 0)
			sol.push_back(plan[i]);
	}
	return sol;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) return false;
	vector<Huerta> huertas(N);
	for (int i = 0; i < N; ++i) {
		cin >> huertas[i].benef >> huertas[i].plazo;
		huertas[i].id = i + 1;
	}
	sort(huertas.begin(), huertas.end(), greater<Huerta>());
	vector<int> seleccion = resolver(huertas);
	for (int i = 0; i < seleccion.size(); ++i)
		cout << (i > 0 ? " " : "") << seleccion[i];
	cout << '\n';
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
