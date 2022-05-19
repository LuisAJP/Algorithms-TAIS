
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <functional> // greater
#include <algorithm>    // std::sort
#include <vector>
#include <cmath>
#include "Matriz.h"
using namespace std;


/*
Definimos una función
mochila(i, j) = máximo valor que podemos poner en la mochila de peso máximo j considerando los objetos del 1 al i.


Definición recursiva		
				mochila(i - 1, j) si pi > j
mochila(i, j) =
				máx( mochila(i - 1, j), mochila(i - 1, j - pi) + vi ) si pi <= j

				con 1 <= i <= n y 1 <= j <= M.


Los casos básicos son:
	mochila(0, j) = 0		 0 <= j <= M
	mochila(i, 0) = 0		 0 <= i <= n.

*/

//Coste: O(nM) tanto en tiempo como en espacio adicional.
/*
void mochila_pd(vector<int> const& P, vector<int> const& V, int M, int & valor, vector<bool> & cuales, Matriz<int> &mochila){
	int n = P.size() - 1;
	//Matriz<int> mochila(N + 1, M + 1, 0);
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (P[i] > j)
				mochila[i][j] = mochila[i - 1][j];
			else
				mochila[i][j] = max(mochila[i - 1][j], mochila[i - 1][j - P[i]] + V[i]);
		}
	}
	valor = mochila[n][M];
	// cálculo de los objetos
	int resto = M;
	for (int i = n; i >= 1; --i) {
		if (mochila[i][resto] == mochila[i - 1][resto]) {
			// no cogemos objeto i
			cuales[i] = false;
		}
		else { // sí cogemos objeto i
			cuales[i] = true;
			resto = resto - P[i];
		}
	}
}
*/

void mochila_pd(vector<int> const& P, vector<int> const& V, int M, int & valor, vector<bool> & cuales, Matriz<int> &mochila){
	int n = P.size() - 1;
	//Matriz<int> mochila(N + 1, M + 1, 0);
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (P[i] > j)
				mochila[i][j] = mochila[i - 1][j];
			else
				mochila[i][j] = max(mochila[i - 1][j], mochila[i-1][j - P[i]] + V[i]);
		}
	}
	valor = mochila[n][M];
	// cálculo de los objetos
	int resto = M;
	for (int i = n; i >= 1; --i) {
		if (mochila[i][resto] != mochila[i - 1][resto]) { 
		// sí cogemos objeto i
			cuales[i] = true;
			resto = resto - P[i];
		}
		else {// no cogemos objeto i
			//cuales[i] = false;
		}
	}
}

bool resuelveCaso() {
	int N;//numero objetos
	cin >> N;
	if (!cin) return false;
	vector<int> P(N + 1);
	vector<int> V(N + 1);
	int C,M=0;
	for (int i = 1; i <= N; i++)
		cin >> P[i];
	for (int i = 1; i <=N; i++)
		cin >> V[i];

	cin >> M;
	int valor = 0;
	vector<bool> cuales(N + 1, false);
	Matriz<int> mochila(N + 1, M + 1, 0);
	mochila_pd(P,V,M,valor,cuales,mochila);
	return true;
}


// Menú principal
int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}



