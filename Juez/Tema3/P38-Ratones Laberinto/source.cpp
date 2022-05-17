#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include"IndexPQ.h"
#include <climits>
#include "GrafoDirigidoValorado.h"
using namespace std;


/*
Tema:3
Problema38 Ratones en un laberinto
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

const int INF = 1000000000;
class Dijkstra{
public:
	Dijkstra(GrafoDirigidoValorado<int> const &G, int s) :distTo(G.V(), INF), pq(G.V()){
		distTo[s] = 0;
		pq.push(s, 0);
		while (!pq.empty()){
			int v = pq.top().elem; pq.pop();
			for (auto e : G.ady(v))
				relax(e);
		}
	}
	bool hayCamino(int v) const{
		return distTo[v] != INF;
	}

	int valor(int v) const{
		return distTo[v];
	}
private:
	vector<int> distTo;
	IndexPQ<int> pq;
	void relax(AristaDirigida<int>e){
		int v = e.from(), w = e.to();
		if (distTo[w] > distTo[v] + e.valor()){
			distTo[w] = distTo[v] + e.valor();
			pq.update(w, distTo[w]);
		}
	}
};


bool resuelveCaso() {
	int N, S, T, P;
	cin >> N >> S >> T >> P;
	if (!cin)
		return false;
	GrafoDirigidoValorado<int> G(N+1);
	int a, b, c;
	
	for (int i = 0; i < P; i++){
		cin >> a >> b >> c;
		G.ponArista({ a, b, c });
	}

	Dijkstra dj(G.inverso(), S);
	int ratones = 0;
	for (int i = 0; i <=N; i++){
		if (i != S && dj.hayCamino(i) && dj.valor(i) <= T)
			ratones++;
	}
	cout << ratones << "\n";
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
