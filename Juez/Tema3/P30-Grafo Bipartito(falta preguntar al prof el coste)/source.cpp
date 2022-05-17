#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#include "Grafo.h"

/*
Tema:3
Problema30 Grafo Bipartito
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/
//pantalla completa alt+shift+enter

//true es rojo
//false es azul

class GrafoBipartito{
public:
	//constructor 
	GrafoBipartito(const Grafo &G) : 
		//inicializo marked
		marked(G.V(), false), bipartito(true), color(G.V()){
			//recorre todos los vertices del grafo, puede haber componentes no conexas
			//si existiera 2 componentes conexas y la primera no fuera bipartito 
			//automaticamente se saldria del bucle sin evaluar la otra componente
		for (int i = 0; i < G.V() && bipartito;i++){
			if (!marked[i]){
				//pintamos el vertice
				color[i] = true;
				bipartito = dfs(G,i);
			}
		}
	}

	bool esBipartito(){
		return bipartito;
	}
		
private:
	vector<bool>marked;
	vector<bool>color;
	bool bipartito;
	//	Tiene coste O(V+E) recorre los vectices y aristas
	bool dfs(const Grafo &G, int v){
		//marcamos el vertice que vamos a visitar
		marked[v] = true;
		//los adyacentes del vertice v
		for (int i: G.ady(v)){
			if (!marked[i]){
				//marcamos de otro color a los vertices ayacentes de v
				color[i] = !color[v];
				if (!dfs(G, i))
					return false;
			}
			else{
				if (color[i] == color[v])
					return false;
			}	
		}
		return true;
	}
};


bool resuelveCaso(){
	int V, E;
	cin >>V>> E;
	int v, w;
	if (!cin) 
		return false;
	Grafo G(V);
	for (int i = 0; i < E;i++){
		cin >> v >> w;
		G.ponArista(v, w);
	}
	//G.print();
	GrafoBipartito gb(G);
	if (gb.esBipartito())
		cout << "SI";
	else
		cout<<"NO";
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
