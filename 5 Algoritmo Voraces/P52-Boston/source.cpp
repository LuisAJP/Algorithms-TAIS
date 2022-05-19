#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>//sort
#include<functional>//greater
#include<vector>
using namespace std;


/*
Tema:3
Problema52 Los Broncos de Boston
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/



//
//	Tiene un coste O(NLogN + N), N= numero de puntuaciones
//
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0) return false;

	vector<int>R(N);
	vector<int>B(N);
	for (int i = 0; i < N;i++){
		cin >> R[i];
	}
	for (int i = 0; i < N; i++){
		cin >> B[i];
	}
	// Ordenamos de menor a mayor, tiene coste O(NLogN)
	sort(R.begin(), R.end(), less<unsigned>());
	sort(B.begin(), B.end(), greater<unsigned>());

	//tiene coste O(N) 
	int acumulador = 0;
	for (int i = 0; i < N; i++){
		if (B[i]>R[i])
			acumulador +=abs(R[i]-B[i]);
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
