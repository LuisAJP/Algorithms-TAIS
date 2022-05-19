#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//#include "bintree_eda.h"
#include "TreeMap_AVL.h"
/*
Tema:1
Problema 4 Encontrar el k-esimo elemento en un arbol AVL
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


template <class Clave, class Valor, class Comparador = std::less<Clave>>
class TreeMapAVL_ext : public map< Clave,  Valor,  Comparador > {
	using Link = typename map<Clave, Valor, Comparador >::Link;

public:
	int tam_i;
	void kesimo(const vector<int> &v){
		kesimo(this->raiz, v);
	}
private:
	void kesimo(Link r, const vector<int> &v){
		cout << "hola";
	}
	
};


bool resuelveCaso() {
	TreeMapAVL_ext <int, int> mapa;
	int n, c;
	cin >> n;
	int p = 1;
	if (n == 0) return false;
	for (int i = 0; i < n; i++){
		cin >> c;
		if (mapa.count(c) == 0){//si la clave no existe
			mapa.insert({ c, p });
			mapa.tam_i = p;
			p++;
		}
	}
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> c;
		v[i] = c;
	}
	mapa.kesimo(v);
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
