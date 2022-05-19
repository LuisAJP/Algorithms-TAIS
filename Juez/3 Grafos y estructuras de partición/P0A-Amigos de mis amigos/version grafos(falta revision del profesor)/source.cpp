#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#include "Grafo.h"


class MaximaComponenteConexa{

public:
	//Buscamos la componente conexa mas grande.
	//se va actualizando el maximo despues de cada recorrido de una componente conexa
	//Coste de la dfs es O(V+E)(lineal), 
	//donde V es el numero de amigos y E es el numero de grupos
	MaximaComponenteConexa(const Grafo &G) :marked(G.V(),false),contador(0),maximo(0){
		for (int i = 1; i < G.V(); i++){
			if (!marked[i]){
				dfs(G,i);
			}
			maximo = max(contador, maximo);
			contador = 0;
		}
	}
	int getMaximo(){ return maximo; }

private:
	vector<int> marked;
	int contador;
	int maximo;
	//Coste de la dfs es V+E(lineal), 
	//donde V es el numero de amigos y E es el numero de grupos
	void dfs(const Grafo &G, int v){
		marked[v] = true;
		contador++;
		for (int w: G.ady(v)){
			if (!marked[w])
				dfs(G,w);
		}
	}
};

void resuelveCaso() {
	int V, E;
	cin >> V >> E;
	Grafo G(V+1);
	int v, w;
	for (int i = 0; i < E; ++i) {
		cin >> v >> w;
		G.ponArista(v, w);
	}
	MaximaComponenteConexa mcc(G);
	
	cout  << mcc.getMaximo()<<'\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos = 0;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}


	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
