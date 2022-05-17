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

bool resuelveCaso(){
	int numUsuariosGrupo = 0;
	int V, E;
	cin >>V>> E;
	int u, w;
	if (!cin) 
		return false;
	ConjuntosDisjuntos part(V);
	while (E--){
		int tam;
		cin >> tam;
		if (tam > 0){
			int prim, otro;
			cin >> prim;
			--prim;
			for (int i = 1; i < tam; i++){
				cin >> otro;
				--otro;
				part.unir(prim, otro);
			}
		}
	}	
	cout << part.tam(0);
	for (int i = 1; i < V; ++i){
		cout << " " << part.tam(i);
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
