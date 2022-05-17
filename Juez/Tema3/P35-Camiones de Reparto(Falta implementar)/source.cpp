#include <iostream>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
using namespace std;


typedef struct{
	int o;
	int d;
	int coste;
}tInfo;

class Camion{
public:
	Camion(const GrafoValorado<int> &G, tInfo informacion) :info(informacion), marked(G.V(),false),recorrido(false){
		marked[info.o] = true;
		int v = info.o;
		dfs(G,v);
	}
	bool hayRecorrido(){
		return recorrido;
	}

private:
	tInfo info;
	vector<bool> marked;
	bool recorrido;

	void dfs(const GrafoValorado<int> &G,int v){
		marked[v] = true;
		for (Arista<int> e : G.ady(v)){
			if (e.valor() >= info.coste) {
				int otro = e.otro(v);
				if (otro == info.d){
					recorrido = true;
					return;
				}
				if (!marked[otro])
					dfs(G, otro);
			}
		}
	}
};

bool resuelveCaso() {
	int V, E, k;
	cin >> V >> E;
	if (!cin) return false;
	GrafoValorado<int> G(V + 1);
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		Arista<int> arista(a, b, c);
		G.ponArista(arista);
	}
	cin >> k;//lee las consultas
	tInfo info;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;
		info = {a, b, c};
		Camion camion(G,info);
		if (camion.hayRecorrido())
			cout << "SI\n";
		else
			cout << "NO\n";
	}
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
