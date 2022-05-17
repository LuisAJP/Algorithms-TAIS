
// NOMBRE Y APELLIDOS: Luis Alberto JAramillo Pulido
//TAIS15

// comentario sobre la solución, incluyendo el análisis del coste

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#include "Grafo.h"

// esta es la clase que resuelve el problema  COMPLÉTALA

//Coste es =(N +C), donde N es el numero de nodos y C numero de conexiones  
class NodoLejano {
public:
	NodoLejano(const Grafo& G, int o, int ttl) :marked(G.V(), false),alcance(G.V(), false) {
		for (int v = 0; v < G.V(); v++) {
			if (!marked[v]) {
				dfs(G, v, o, ttl);
			}
		}
		cout << "";

	}

   
   int inalcanzables() const {
	   int cont = 0;
	   for (int i = 1; i < alcance.size(); i++) {
		   if (!alcance[i])
			   cont++;
	   }
	   return cont;
   }
private:
   /* atributos */
	vector<int> marked;
	vector<int> alcance;

	//la bfs tiene coste es =(N +C), donde N es el numero de nodos y C numero de conexiones  
	//
	void dfs(const Grafo& G, int v,int o, int ttl) {
		marked[v] = true;
		for (int w : G.ady(v)) {
			if (!marked[w]) {
				if (ttl != 0) {
					alcance[w] = true;
					dfs(G, w, o, ttl - 1);
				}
				else {
					if (ttl != 0) {
						alcance[w] = true;
						dfs(G, w, o, ttl - 1);
					}
					return;
				}
					
					
			}
		}
	}
};

bool resuelveCaso() {
   
   int V, E;
   cin >> V >> E;
   if (!cin)
      return false;
   
   Grafo G(V+1);
   int u,v;
   for (int i = 0; i < E; ++i) {
      cin >> u >> v;
      G.ponArista(u, v);
   }
   
   int K; // número de preguntas
   cin >> K;
   while (K--) {
      int origen, TTL;
      cin >> origen >> TTL;
     
      
      NodoLejano nl(G,origen,TTL );
      cout <<  nl.inalcanzables() << "\n";
   }
   cout << "---\n";
   return true;
   
}
int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   // Resolvemos
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
