#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

/*
Tema:3
Problema56 Semana Informática
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

using namespace std;

struct tInfo {
	int id;
	int ini;
	int fin;

	bool operator<(tInfo const &c) const{
		return ini < c.ini || (ini == c.ini && fin < c.fin);
	}

	bool operator>(tInfo const &c) const {
		return c.fin> fin || (fin == c.fin && c.ini > ini);
	}
};

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0)
		return false;
	tInfo info;
	vector<tInfo> v;

	for (int i = 0; i < N; ++i) {
		cin >> info.ini >> info.fin;
		v.push_back(info);
	}
	sort(v.begin(), v.end());

	PriorityQueue<tInfo, greater<tInfo>> cola;
	int classmate = 0;
	
	for (int i = 0; i < v.size(); ++i) {
		if (cola.empty())
			cola.push({ classmate, v[i].ini, v[i].fin });

		 else if (cola.top().fin> v[i].ini) {//Si existe solapamiento
			 classmate++;
			cola.push({ classmate, v[i].ini, v[i].fin });
		}
		else if (cola.top().fin <= v[i].ini) {
			int id = cola.top().id;
			cola.pop();
			cola.push({ id, v[i].ini, v[i].fin });
		}
		
	}
	cout << classmate << "\n";
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
