#include <iostream>
#include <fstream>
#include <queue>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
using namespace std;

//Algoritmo de Lazy Prim aplicado en este problema
class KruskalMST{
public:
	KruskalMST(const GrafoValorado<int> &G, PriorityQueue<Arista<int>> cola) : mst(), pq(), uf(G.V()){
		pq = cola;
		while (!pq.empty() && mst.size() < G.V() - 1){
			Arista<int> e = pq.top(); pq.pop();
			int v = e.uno(), w = e.otro(v);
			if (!uf.unidos(v, w)){
				uf.unir(v, w);
				mst.push(e);
			}
		}
	}
	queue<Arista<int>> arbol(){
		return mst;
	}
private:
	//MST vertices (mst->minimun spanning trees)
	queue<Arista<int>> mst; // MST edges
	ConjuntosDisjuntos uf;
	PriorityQueue<Arista<int>> pq; // PQ of edges

};

void imprimir(queue<Arista<int>> arbol){
	
	int tam = arbol.size();
	for (int i = 0; i < tam; i++){
		Arista<int> arista = arbol.front();
		int a = arista.uno();
		int b = arista.otro(a);
		cout << a << "-" << b << "  ";
		

		arbol.pop();
	}
}

bool resuelveCaso() {
	int V, E;
	cin >> V >> E;
	if (!cin)return false;
	GrafoValorado<int> G(V + 1);
	int a, b, c;
	PriorityQueue<Arista<int>> pq;
	for (int i = 1; i <= E; ++i) {
		cin >> a>> b >> c;
		Arista<int> arista(a, b, c);
		pq.push(arista);
		G.ponArista(arista);
	}
	KruskalMST kruskalMST(G,pq);
	//queue<Arista<int>> arbol = lazyPrimMST.arbol();
	//imprimir(arbol);
	cout << "\n";
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
