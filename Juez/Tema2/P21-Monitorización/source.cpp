#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;


/*
Tema:2
Problema 21 Unidad Curiosa de Monitorizacion
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


struct registro {
	int momento; // cuándo le toca
	int id; // identificador (se utiliza en caso de empate)
	int periodo; // tiempo entre consultas
};

bool operator<(registro const& a, registro const& b) {
	return a.momento < b.momento ||
		(a.momento == b.momento && a.id < b.id);
}


//O(N log N+K log N), donde N es el número de usuarios y K el número de consultas
//El coste de insertar los registros con la operacion push (O(logN)) es NLog N, 
//donde N es el numero de Nodos
//El coste de ir calculando el momento usamos push y pop(ambos tienen coste logN), 
//es KlogN donde K es el numero de envios y N el numero de nodos
bool resuelveCaso() {
	int N;
	cin >> N; // número de usuarios registrados
	if (N == 0) // no hay más casos
		return false;
	PriorityQueue<registro> cola;
	// leemos los registros
	for (int i = 0; i < N; ++i) {
		int id_usu, periodo;
		cin >> id_usu >> periodo;
		cola.push({ periodo, id_usu, periodo });
	}

	int envios; // número de envíos a mostrar
	cin >> envios;
	while (envios--) {
		registro e = cola.top(); cola.pop();
		cout << e.id << '\n';
		e.momento += e.periodo;
		cola.push(e);
	}
	cout << "---" << '\n';
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
