
// NOMBRE Y APELLIDOS Luis Jaramillo Pulido
//TAIS15

// comentario sobre la solución, incluyendo el análisis del coste

#include <iostream>
#include <fstream>
#include <algorithm>
//#include "IndexPQ.h"
#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

using namespace std;
int INF = 100000000;

typedef struct {
	int u;
	int w;
	int c;
}tInfo;

bool operator < (tInfo const& a, tInfo const& b) {
	return a.c < b.c ;
}

//Coste es de orden O(V+logE)
//Donde V es el numero de intersecciones y E es el numero de calles

//Algoritmo de kruskal
class Pavimentar {


public:
	Pavimentar(const GrafoValorado<int>& G) :marked(G.V(), false), distTo(G.V(),INF) ,uf(G.V()){

		Arista<int> A=G.ady(1).at(0);//la arista inicial
		pq.push(A);
		while (!pq.empty()) {
			A= pq.top(),pq.pop();
			int v = A.uno();
			int w = A.otro(v);
			if (!uf.unidos(v, w)) {
				uf.unir(v, w);

				A = G.ady(w).at(0);
				
				pq.push();
		
			}
		}
	}

private:
	vector<bool>marked;
	vector<int> distTo;
	PriorityQueue<Arista<int>>pq;
	ConjuntosDisjuntos uf;


};

bool resuelveCaso() {
   
   int V, E;
   cin >> V >> E;
   if (!cin)
      return false;
   
   // leer grafo
   int u, w,c;
   
   GrafoValorado<int> G(V+1);
   for (int i = 0; i < E;i++) {
	   cin>> u>>w>>c;
	  // Arista<int> A(u,w,c);
	   G.ponArista({u,w,c});
   }
   
   // resolver el problema (utilizando otras funciones o clases)
   Pavimentar pavimentar(G);
   // escribir la respuesta
   
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
