#include <iostream>
#include <fstream>
#include <queue>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
using namespace std;

//Algoritmo de Lazy Prim aplicado en este problema
class LazyPrimMST{
public:
	LazyPrimMST(const GrafoValorado<int> &G) :marked(G.V(), false), mst(), pq(){
		visit(G, 0);
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
		
	}
	queue<Arista<int>> arbol(){
		return mst;
	}
private:
	vector<bool> marked;
	//MST vertices (mst->minimun spanning trees)
	queue<Arista<int>> mst; // MST edges
	PriorityQueue<Arista<int>> pq; // PQ of edges

	void visit(const GrafoValorado<int> &G, int v)
	{
		marked[v] = true;
		for (Arista<int> e : G.ady(v)){
			if (!marked[e.otro(v)])
				pq.push(e);
		}
	}
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
	for (int i = 1; i <= E; ++i) {
		cin >> a>> b >> c;
		Arista<int> arista(a, b, c);
		G.ponArista(arista);
	}
	LazyPrimMST lazyPrimMST(G);
	queue<Arista<int>> arbol = lazyPrimMST.arbol();
	imprimir(arbol);
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
