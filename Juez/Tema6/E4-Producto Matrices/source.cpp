#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000;

int multiplica_matrices(vector<int> const& D, Matriz<int> & P) {
	int n = D.size() - 1;
	// inicialización
	Matriz<int> matrices(n + 1, n + 1, 0);
	P = Matriz<int>(n + 1, n + 1, 0);
	// recorrido por diagonales
	for (int d = 1; d <= n - 1; ++d) // recorre diagonales
	for (int i = 1; i <= n - d; ++i) { // recorre elementos de diagonal
		int j = i + d;
		// calcular mínimo
		matrices[i][j] = INF;
		for (int k = i; k <= j - 1; ++k) {
			int temp = matrices[i][k] + matrices[k + 1][j] + D[i - 1] * D[k] * D[j];
			if (temp < matrices[i][j]) { // es mejor pasar por k
				matrices[i][j] = temp;
				P[i][j] = k;
			}
		}
	}
	return matrices[1][n];
}

// 1 <= i <= j <= n
void escribir_paren(int i, int j, Matriz<int> const& P) {
	if (i == j) {
		cout << "M" << i;
	}
	else {
		int k = P[i][j];
		if (k > i) {
			cout << "("; escribir_paren(i, k, P); cout << ")";
		}
		else
			cout << "M" << i;
		cout << "*";
		if (k + 1 < j) {
			cout << "("; escribir_paren(k + 1, j, P); cout << ")";
		}
		else
			cout << "M" << j;
	}
}


bool resuelveCaso(){
	int N;//numero de matrices
	cin >> N;
	if (!cin)
		return false;
	vector<int>  D(N+1);
	Matriz<int>P(N + 1, N + 1, 0);
	for (int i = 0; i <= N; i++)
		cin >> D[i];
	int numero =multiplica_matrices(D,P);
	//escribir_paren(1,N,P);
	cout << numero << "\n";
	return true;
}
int main(){
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}