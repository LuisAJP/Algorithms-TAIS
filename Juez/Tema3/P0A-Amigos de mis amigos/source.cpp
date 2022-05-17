#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#include "Grafo.h"

/*
Tema:3
Problema0 Los amigos de mis amigos son mis amigos
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/
//pantalla completa alt+shift+enter

class MaximaComponenteConexa {
public:
	MaximaComponenteConexa(Grafo const& G) : marked(G.V(), false),
		_maximo(0) {
		//Coste O(V+E), donde V es el numero de amigos y E es el numero de parejas
		for (int vertice = 1; vertice < G.V(); ++vertice) {
			if (!marked[vertice]) { // se recorre una nueva componente conexa
				int tam = 0;
				dfs(G, vertice, tam);//Depth-first search
				_maximo = max(_maximo, tam);
			}
		}
	}
	// tamaño máximo de una componente conexa
	int maximo() const {
		return _maximo;
	}
private:
	vector<bool> marked; // marked[v] = se ha visitado el vértice v?
	int _maximo;

	//Coste O(V+E), donde V es el numero de amigos y E es el numero de parejas
	void dfs(Grafo const &G, int vertice, int & tam) {
		marked[vertice] = true;
		++tam;
		for (int w : G.ady(vertice)) {//saca del vertice sus vertices adyacentes 
			if (!marked[w]) {//no se ha visitado el vertice adyacente 
				dfs(G, w, tam);
			}
		}
	}
};

void resuelveCaso() {
	int V, E;
	cin >> V >> E;
	Grafo grafo(V+1);
	int v, w;
	for (int i = 0; i < E; ++i) {
		cin >> v >> w;
		grafo.ponArista(v, w);
	}
	MaximaComponenteConexa mcc(grafo);
	cout << mcc.maximo() << '\n';
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
