#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include<algorithm>
//#include "GrafoValorado.h"
#include "Grafo.h"
using namespace std;

class BusquedaAnchura {
public:
	BusquedaAnchura(const Grafo &G, int s) : marked(G.V(), false), distTo(G.V()), edgeTo(G.V(),-1) {
		bfs(G, s);
	}
	// ¿Hay camino del origen a v?
	bool hayCamino(int v) const {
		return marked[v];
	}
	// número de aristas entre s y v
	int distancia(int v) const {
		return distTo[v];
	}
private:
	vector<bool>marked; // marked[v] = ¿hay camino de s a v?
	vector<int> distTo; // distTo[v] = aristas en el camino s-v más corto
	vector<int> edgeTo;
	void bfs(Grafo const& G, int s) {
		queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : G.ady(v)) {
				if (!marked[w]) {
					edgeTo[w]=v;
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}
};

bool resuelveCaso() {
	//V num-intersecciones, E num-calles, K num-Consultas
	int V, E;
	cin >> V >> E;
	if (!cin) return false;
	int v, w;
	Grafo G(V);
	for (int i = 0; i < E; i++){
		cin >> v >> w;
		G.ponArista(v,w);
	}
	int s;
	s = 7;
	BusquedaAnchura BF(G,0);
	
	BF.hayCamino(s);
	BF.distancia(s);
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