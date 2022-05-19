#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

/*
Problema3 Nos vamos de concierto
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


/*
Definimos una función
grupos(i, j) = máximo numero de grupos para un presupuesto j, 
considerando los tipos de precios de las entradas del 1 al i


Definición recursiva
				grupos(i - 1, j) si Pi > j
grupos(i, j) =
				max(grupos(i - 1, j), grupos(i - 1, j - Pi) + Gi ) si pi <= j

donde 1 <= i <= n y 1 <= j <= T.


Los casos básicos son:
grupos(0, j) = 0	0 <= j <= T
grupos(i, 0) = 0	0 <= i <= n

*/


//Coste: O(nT)en tiempo y O(T)en espacio adicional, donde T es el presupuesto que dispone Sergio
int concierto(const vector<int> &G, const vector<int> &P, const int &T) {
	vector<int> grupos(T + 1, 0);
	int n = G.size() - 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = T; j >= 1; --j) {
			if (P[i] <= j)
				grupos[j] = max(grupos[j], grupos[j - P[i]] + G[i]);
		}
	}
	return grupos[T];
}


bool resuelveCaso(){
	int T;//presupuesto
	int N;//numero de festivales
	cin >> T >> N;
	if (!cin)return false;
	vector<int> G(N+1);//numero de grupos
	vector<int> P(N+1);//precios de las entradas

	for (int i = 1; i <= N; i++)
		cin >> G[i] >> P[i];

	int numero = concierto(G,P,T);//maximo numero de grupos
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