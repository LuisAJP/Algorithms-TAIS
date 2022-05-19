#include<iostream>
#include<fstream>
#include<vector>
#include "GrafoValorado.h"
#include "IndexPQ.h"
using namespace std;
const int INF = 1000000000;

typedef struct{
	int o;//origen
	int d;//destino
}tInfo;

class Dijkstra{
public:
	Dijkstra(const GrafoValorado<int> &G, int s) :distTo(G.V(), INF), pq(G.V()), edgeTo(G.V()) {
		distTo[s] = 0;
		pq.push(s, 0);
		while (!pq.empty())
		{
			int v = pq.top().elem;pq.pop();//pq del minimo
			for (Arista<int> e : G.ady(v))
				relax(e);
		}
	}

private:
	vector<int> distTo;
	IndexPQ<int> pq;
	vector<Arista<int>>edgeTo;

	void relax(Arista<int>  e)
	{
		int v = e.uno(), w = e.otro(v);
		if (distTo[w] > distTo[v] + e.valor()){
			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			pq.update(w, distTo[w]);
		}
	}
};
bool resuelveCaso(){
	int N;//numero intersecciones(vertices) 1-8
	int E;//numero de calles(aristas)
	cin >> N >> E;
	if (!cin) return false;
	GrafoValorado<int> G(N);
	
	int o,d,c;
	for (int i = 0; i < E;i++){
		cin >> o >> d>>c;
		Arista <int> A(o,d,c);
		G.ponArista(A);
	}
	Dijkstra camino(G, 0);
	return true;
}
int main(){
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}