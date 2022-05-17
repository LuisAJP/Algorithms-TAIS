#include <iostream>
#include <fstream>
#include <queue>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
using namespace std;
/*
COSTE: )
COSTE: O(N) siendo n el numero de vertices del grafo
O(n) porque recorremos todos los vertices para sumar el coste de cada uno
O(n) recorremos cada vertice y sus adyacentes
*/
//Algoritmo de Lazy Prim aplicado en este problema
class Archipielago{
public:
	Archipielago(const GrafoValorado<int> &G) :marked(G.V(), false), mst(), pq(){
		visit(G, 1);
		while (!pq.empty() && mst.size() <G.V())
		{
			Arista<int> e = pq.top(); pq.pop(); //pq.delMin()
			int v = e.uno(), w = e.otro(v);
			if (marked[v] && marked[w]) continue;
			mst.push(e);
			if (!marked[v])
				visit(G, v);
			if (!marked[w])
				visit(G, w);
		}
		conexo = (mst.size() == G.V() - 2);
	}

	int sumaCosteMinimo() {
		int resultado = 0;
		int tam = mst.size();
		for (int i = 0; i <tam; ++i) {
			resultado = resultado + mst.front().valor();
			mst.pop();
		}
		return resultado;
	}

	bool esConexo() {
		return conexo;
	}
private:
	vector<bool> marked;
	//MST vertices (mst->minimun spanning trees)
	queue<Arista<int>> mst; // MST edges
	PriorityQueue<Arista<int>> pq; // PQ of edges
	bool conexo;

	void visit(const GrafoValorado<int> &G, int v)
	{
		marked[v] = true;
		for (Arista<int> e : G.ady(v)){
			if (!marked[e.otro(v)])
				pq.push(e);
		}

	}
};

bool resuelveCaso() {
	int V, E;
	cin >> V >> E;
	if (!cin)return false;
	GrafoValorado<int> G(V + 1);
	for (int i = 0; i < E; ++i) {
		int A, B, coste;
		cin >> A >> B >> coste;
		Arista<int> temp(A, B, coste);
		G.ponArista(temp);
	}
	Archipielago archipielago(G);
	if (!archipielago.esConexo())
		cout << "No hay puentes suficientes\n";
	else
		cout << archipielago.sumaCosteMinimo() << "\n";
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
