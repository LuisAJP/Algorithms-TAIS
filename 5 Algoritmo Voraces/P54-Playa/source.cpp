#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>//sort
#include<functional>//greater or less
#include<vector>
using namespace std;


/*
Tema:3
Problema54 En primera linea de playa
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

typedef struct{
	int ini;
	int fin;
}tInfo;

bool operator <(tInfo a, tInfo b){
	return a.ini < b.ini;
}
//
//	Tiene un coste O(NLogN + N), N= numero de edificios
//
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)
		return false;
	vector<tInfo>v(N);
	for (int i = 0; i < N;i++){
		cin >> v[i].ini>>v[i].fin;
	}
	// Ordenamos de menor a mayor, tiene coste O(NLogN)
	sort(v.begin(),v.end(), less<>());

	int tuneles=1;
	int final = v[0].fin;
	for (int i = 1; i < N; i++){
		if (v[i].ini < final){//Existe solapamiento 
			if (v[i].fin < final)//nos quedamos con el de menor longitud
				 final = v[i].fin;
		}
		else{
			final= v[i].fin;
			tuneles++;
		}
			
	}

	cout << tuneles << "\n";

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
