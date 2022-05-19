#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "GrafoDirigido.h"
using namespace std;

class Arborescencia{
public:
	Arborescencia(const GrafoDirigido &G): marcados(G.V(),false), raiz(-1){
		int nodosVisitados = 0;
		bool salir = false;
		GrafoDirigido inverso = G.inverso();
		for (int i = 1; i < G.V() && !salir; i++){
			if (inverso.ady(i).size() == 0){
				if (raiz == -1){
					nodosVisitados = 1;
					if (dfs(G, i, nodosVisitados) && nodosVisitados == G.V()){
						raiz = i;
						salir = true;
					}
				}
				else
					salir = true;
			}
		}
	}

	int getRaiz(){
		return raiz;
	}

private:
	int raiz;
	vector<bool> marcados;

	bool dfs(GrafoDirigido const& G,int v, int& nodos_visitados) {
		marcados[v] = true;
		for (int w : G.ady(v)) {
			if (!marcados[w]) {
				nodos_visitados++;
				if (!dfs(G, w, nodos_visitados))
					return false;
			}
			else{
				//existe ciclo
				return false;
			}		
		}
		return true;
	}
};



bool resuelveCaso(){

	int V, A, v, w;
	cin >> V >> A;
	if (!cin) return false;
	GrafoDirigido grafo(V+1);

	for (int i = 0; i < A; ++i){
		cin >> v >> w;
		grafo.ponArista(v, w);
	}

	Arborescencia arborescencia(grafo);

	if (arborescencia.getRaiz() >= 0)
		cout << "SI " << arborescencia.getRaiz() << "\n";
	else
		cout << "NO\n";
	return true;
}

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
