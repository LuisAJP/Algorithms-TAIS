#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#include "Grafo.h"

/*
Tema:3
Problema31 Colocar a los guardias
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


class Guardias{
public:
	//constructor 
	Guardias(const Grafo &G) :
		//inicializo marked
		marked(G.V(), false), bipartito(true), color(G.V()), minimo(0){
		for (int v = 1; v < G.V() && bipartito; v++){
			if (!marked[v]){
				int a = 0, b = 0;//a y b son contadores si se pintan de un color u otro
				//pintamos el vertice
				color[v] = true;
				a++;
				bipartito = dfs(G, v, a, b);
				if (bipartito){
					int aux = min(a, b);
					minimo = aux + minimo;
				}
			}
		}
	}

	bool esBipartito(){
		return bipartito;
	}

	int elMinimo(){
		return minimo;
	}

private:
	vector<bool>marked;
	vector<bool>color;
	bool bipartito;
	int minimo;

	//El coste es O(V+E), donde V es el numero de cruces y E es el numero de calles
	//el coste es O(V+E), porque por cada cruce que visitemos tendremos que visitar sus adyacentes,
	//por lo que el coste de cada cruce dependera del numero de calles/aristas que tenga que visitar.
	bool dfs(const Grafo &G, int v, int &a, int &b){
		//marcamos el vertice que vamos a visitar
		marked[v] = true;
		//los adyacentes del vertice v
		for (int i : G.ady(v)){
			if (!marked[i]){
				//marcamos de otro color a los vertices ayacentes de v
				color[i] = !color[v];
				if (color[i])	a++;
				else b++;
				if (!dfs(G, i, a, b))
					return false;
			}
			else{
				if (color[i] == color[v]) {
					return false;
				}
			}
		}
		return true;
	}
};


bool resuelveCaso(){
	int V, E;
	cin >> V >> E;
	int v, w;
	if (!cin)
		return false;
	Grafo G(V+1);
	for (int i = 0; i < E; i++){
		cin >> v >> w;
		G.ponArista(v, w );
	}
	Guardias gb(G);
	if (gb.esBipartito())
		cout << gb.elMinimo();
	else
		cout << "IMPOSIBLE";
	cout << "\n";
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
