#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;
const int INF = 1000000000;
typedef struct{
	int p;
	int v;
}tInfo;



/*
Definicion de la funcion
cazatesoros(i, j) = máximo valor cofre i(cantidad de oro) que podemos 
subir a la superficio con un tiempo de oxigeno j

Definición recursiva						
					cazatesoros(i - 1, j) si ti > j //ti tiempo que se tarda de subir un cofre
cazatesoros(i, j) =									//a la superficie
					max(cazatesoros(i - 1, j), cazatesoros(i - 1, j - pi) + vi) si ti <= j
con 1 <= i <= n y 1 <= j <= T.

Casos Basicos
Los casos básicos son:
cazatesoros(0, j) = 0	0 <= j <= T
cazatesoros(i, 0) = 0	0 <= i <= n.
		
*/	

/*
void cofresSeleccionados(const vector<int> &t,const Matriz<int> &tesoros, vector<int> &cuales, int T, int n, int &cuantos){
//vector<int> cuales(n + 1, 0);
	int i = n; int j = T;
	while (i > 0){
	if (t[i] <= j && tesoros[i][j] != tesoros[i - 1][j]){
	++cuales[i];
	j = j - t[i];
	cuantos++;
	}
	else
	--i;
}
}*/
void cofresSeleccionados(const vector<int> &t, const Matriz<int> &tesoros, 
vector<int> &cuales, int T, int n, int &cuantos){
	
	int j = T;
	for (int i = n; i >= 1; --i) {
		if (tesoros[i][j] != tesoros[i - 1][j]) {
			cuales[i] ++;
			j = j - t[i];
			++cuantos;
		}
		else {
			cuales[i] = 0;
		}
	}
}

//el Coste es de orden O(nT) en tiempo,  como espacio adicional, donde n es el numero de cofres y 
//T es el tiempo total de la botella de oxigeno
int cazatesoros(const vector<int> &v, const vector<int> &t, int T, int n, Matriz<int> &tesoros){
	//int n = t.size() - 1;
	//Matriz<int> tesoros(n+1, T+1,0);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= T; j++){
			if (t[i] > j)
				tesoros[i][j] = tesoros[i - 1][j];
			else
				tesoros[i][j] = max(tesoros[i - 1][j], tesoros[i - 1][j - t[i]] + v[i]);
		}
	}
	return tesoros[n][T];
}


bool resuelveCaso() {
	int T;//T(Tiempo total de la botella de oxigeno)
	int N;//N(numero de cofres)
	cin >> T >> N;
	if (!cin)return false;
	vector<int> p(N + 1);//profundidad de cada cofre
	vector<int> v(N + 1);//cantidad de oro de cada cofre
	vector<int> t(N + 1);//tiempo total de subir cada cofre a la superficie
	for (int i = 1; i < N + 1; i++){
		cin >> p[i] >> v[i];
		t[i] = p[i] + 2 * p[i];
	}

	Matriz<int> tesoros(N + 1, T + 1, 0);
	vector<int> cuales(N + 1, 0);
	int cuantos = 0;
	int valor = cazatesoros(v, t, T, N, tesoros);
	cofresSeleccionados(t, tesoros, cuales, T, N, cuantos);

	cout << valor << "\n";

	cout << cuantos << "\n";
	for (int i = 0; i <= N; i++){
		if (cuales[i] != 0){
			cout << p[i] << " " << v[i] << "\n";
		}

	}
	cout << "---\n";
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
