#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>//sort
#include<functional>//greater
#include<vector>
using namespace std;


/*
Tema:3
Problema51 Esquiando en Alaska
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/



//
//	Tiene un coste O(NLogN + N), N= numero de esquiadores
//
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0) return false;

	vector<int>A(N);
	vector<int>E(N);
	for (int i = 0; i < N;i++){
		cin >> A[i];
	}
	for (int i = 0; i < N; i++){
		cin >> E[i];
	}
	// Ordenamos de menor a mayor, tiene coste O(NLogN)
	sort(A.begin(), A.end(), less<unsigned>());
	sort(E.begin(), E.end(), less<unsigned>());

	//tiene coste O(N) 
	int acumulador = 0;
	for (int i = 0; i < N; i++){
		acumulador +=abs(A[i]-E[i]);
	}

	cout<<acumulador<<'\n';
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
