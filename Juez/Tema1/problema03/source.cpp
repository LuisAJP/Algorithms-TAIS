#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//#include "bintree_eda.h"
#include "TreeMap_AVL.h"
/*
Tema:1
Problema 3 Rango de claves en un arbol binario de busqueda

Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

template <class Clave, class Valor, class Comparador = std::less<Clave>>
class map_ext : public map< Clave, Valor, Comparador > {
	using Link = typename map<Clave, Valor, Comparador >::Link;

public:
	void rangoClaves( int k1,int k2,vector<int> &v){
		rangoClaves(this->raiz,k1,k2, v);
	}
private:
	/*
	COSTE: O(log n), donde n es el numero de nodos, no recorre todos los nodos del arbol, en cada recorrido selecciona ir por la izquierda o por la derecha, eso hace
	que el coste sea logaritmico
	*/
	void rangoClaves(Link r, int k1, int k2, vector<int> &v){
		if (r == nullptr) 
			return;
		int clave = r->cv.clave;
		if (k1 <= clave){
			rangoClaves(r->iz, k1, k2, v);
			if (clave >= k1 && clave <= k2)
				v.push_back(clave);
			if (k2 >clave)
				rangoClaves(r->dr, k1, k2, v);
		}
		else{
			rangoClaves(r->dr, k1, k2, v);
		}
	}
};

bool resuelveCaso() {
	map_ext <int, int> mapa;
	int n, c;
	cin >> n;
	if (n == 0) return false;
	for (int i = 0; i < n; i++){
		cin >> c;
		if (mapa.count(c) == 0)//si la clave no existe
			mapa.insert(c);
	}
	int k1, k2;
	cin >> k1 >> k2;
	vector<int> v;
	mapa.rangoClaves(k1,k2,v);
	for (int i : v)
		cout <<i<<" ";
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
