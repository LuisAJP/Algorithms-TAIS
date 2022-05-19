#include<iostream>
#include<fstream>
#include"PriorityQueue.h"
using namespace std;



typedef struct {
	int ini;
	int fin;
}tInfo;

bool operator<(const tInfo& a, const tInfo& b) {
	return a.ini < b.ini ;
}
// COSTE: O(N) Siendo N el num de conferencias.
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) return false;
	tInfo info;
	PriorityQueue<tInfo> pq;
	// Leemos las conferencias
	for (int i = 0; i < N; i++) {
		cin >> info.ini >> info.fin;
		pq.push(info);
	}
	PriorityQueue<int> salas;
	int ocupado = 0;
	salas.push(ocupado);

	for (int i = 0; i < N; i++) {
		tInfo info = pq.top(); pq.pop();
		ocupado = salas.top();
		if (info.ini < ocupado)//existe solapamiento
			salas.push(info.fin);
		else {
			salas.pop();
			salas.push(info.fin);
		}	
	}
	cout << salas.size() << "\n";
	return true;
}


int main() {
	// Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	
	while (resuelveCaso());
	
	// Para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}