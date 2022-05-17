#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000;
/*
Tema:6
Problema 
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

/*
Definición recursiva:
							monedas(i - 1, j) si mi > j
monedas(i, j) =
						
							mín( monedas(i - 1, j), monedas(i, j - mi) + 1 ) si mi ⩽ j
*/



int devolver_cambio1(vector<int> const& M, int C,Matriz<int> &monedas) { // M es 1-based
	int n = M.size() - 1;
	//Matriz<int> monedas(n + 1, C + 1, INF);
	monedas[0][0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		monedas[i][0] = 0;
		for (int j = 1; j <= C; ++j) {
			if (M[i] > j) // no se puede considerar M[i] para pagar j, mejor dicho si el valor de moneda es mayor que la cantidad
				monedas[i][j] = monedas[i - 1][j];// obtendra el numero de monedas de la anterior  moneda
			else
				monedas[i][j] = min(monedas[i - 1][j], monedas[i][j - M[i]] + 1); //minimo(num monedas anterior moneda, num monedas que corresponde al resto + 1  ) donde 1 corresponde a la moneda actual 
		}
	}
	return monedas[n][C];
}

int devolver_cambio2(vector<int> const& M, int C, vector<int> &monedas) {
	int n = M.size() - 1;
	//vector<int> monedas(C + 1, INF);
	monedas[0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = M[i]; j <= C; ++j) {
			monedas[j] = min(monedas[j], monedas[j - M[i]] + 1);
		}
	}
	return monedas[C];
}

// monedas[n][C] != INF
vector<int> calcular_monedas1(vector<int> const& M, int C, Matriz<int> const& monedas) {
	int n = M.size() - 1;
	vector<int> cuantas(n + 1, 0); // 1-based
	int i = n; int j = C;
	while (j > 0) { // no se ha pagado todo
		if (M[i] <= j && monedas[i][j] != monedas[i - 1][j]) {
			// tomamos una moneda de tipo i
			++cuantas[i];
			j = j - M[i];
		}
		else // no tomamos más monedas de tipo i
			--i;
	}
	return cuantas;
}

vector<int> calcular_monedas2(vector<int> const& M, int C,vector<int> const& monedas) {
	int n = M.size() - 1;
	vector<int> cuantas(n + 1, 0);
	int i = n; int j = C;
	while (j > 0) { // no se ha pagado todo
		if (M[i] <= j && monedas[j] == monedas[j - M[i]] + 1) {
			// tomamos una moneda de tipo i
			++cuantas[i];
			j = j - M[i];
		}
		else // no tomamos más monedas de tipo i
			--i;
	}
	return cuantas;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;
	vector<int>M(N+1);
	int C;
	for (int i = 1; i <N+1;i++){
		cin >> M[i];
	}
	cin >> C;
	vector<int>  monedas(C+1 , INF);
	Matriz<int> matrizMonedas(N+1 , C + 1, INF);
	int d1 = devolver_cambio1(M, C, matrizMonedas);
	int d2 = devolver_cambio2(M,C,monedas);
	vector<int> w1 = calcular_monedas1(M, C, matrizMonedas);
	vector<int> w2 = calcular_monedas2( M, C,monedas);
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
