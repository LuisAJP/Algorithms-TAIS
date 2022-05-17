
//BOLDUREANU DANIELA NICOLETA
//USUARIO TAIS14

//USUARIO LAB TAIS19

//LUIS JARAMILLO PULIDO
//USUARIO TAIS36

// comentario sobre la solución, incluyendo el análisis del coste

#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include <functional>


using namespace std;

//Coste O(NlogN) donde N es el numero de usuarios
//Metodo voraz lo hemos aplicado ordenando el vector de menor a mayor . Cogiendo el peso maximo que nos da la entrada le hemos restado el 
//valor del mayor usuario del vector y el resultado lo hemos comparado con el elemento mas pequeño, si el resultado resulta que es mayor o igual
//implica que se puede ocupar la silla doble y esos dos usuarios van a la cima y se suma otro viaje. Si el resultado es menor que el usuario actual mas pequeño entonces va solo en el viaje y se suma uno al numero de viajes.

bool resuelveCaso() {
	
	int peso_maximo, N,sol=0;
	int fin, ini;

	cin >> peso_maximo >> N;
	if (!cin)
		return false;
	vector<int> v(N);


	for (int i = 0; i < N; i++) {

		cin >> v[i];
	}

	//O(NlogN)
	//Ordenamos el vector de menor a mayor por el peso de cada usuario
	sort(v.begin(), v.end());

	fin = N - 1; ini = 0;

	//O(N)
	while (ini <= fin) {
		int pesoAct = peso_maximo - v[fin];
		if (pesoAct >= v[ini]) {
			ini++;
			fin--;
		
		}
		else fin--;
		sol++;
	}

	cout << sol << endl;
	// leer el resto de datos

	// resolver el problema (posiblemente utilizando otras funciones o clases)

	// escribir la respuesta

	return true;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
