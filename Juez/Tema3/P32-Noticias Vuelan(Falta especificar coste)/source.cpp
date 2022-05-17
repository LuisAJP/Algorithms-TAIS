#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#include "ConjuntosDisjuntos.h"

/*
Tema:3
Problema32 Las noticias vuelan
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/
//pantalla completa alt+shift+enter


//COSTE TOTAL: O(N + M*G) N= numero de usuarios y M=numero de grupos
bool resuelveCaso(){
	int numUsuariosGrupo = 0;
	int V, E;
	cin >>V>> E;
	int u, w;
	if (!cin) 
		return false;
	ConjuntosDisjuntos part(V+1);
	while (E--){
		int tam;
		cin >> tam;
		if (tam > 0){
			int prim, otro;
			cin >> prim;
			// Esto tiene un coste de O(G) G=numero de usuarios del grupo
			for (int i = 1; i < tam; i++){
				cin >> otro;
				part.unir(prim, otro);// La union tiene un coste de O(1);
			}
		}
	}	
	for (int i = 1; i < V+1; ++i){//Se va imprimiendo el resto de tamaños
		cout << " " << part.tam(i);// Averiguar el tañamo de un conjunto O(1)
	}
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
