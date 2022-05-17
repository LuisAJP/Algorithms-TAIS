#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "PriorityQueue.h"

/*
Tema:2
Problema22 Ordenando a los pacientes en urgencias
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


//El coste es lineal O(n), donde n es el numero de nodos, en todos los casos recorre todos los nodos del arbol, en cada recorrido
//comprueba que se cumple la condicion de equilibrio (la diferencia de alturas de sus dos hijos es como mucho 1)
struct tInfo{
	int orden;
	string nombre;
	int gravedad;
};

bool operator <(tInfo a, tInfo b){
	return a.gravedad > b.gravedad || a.gravedad == b.gravedad && a.orden < b.orden;
}

//El coste es O(N Log N) , donde N es el numero de pacientes,
//En cada iteracion inserta o elimina un paciente, las operaciones de push y pop tiene coste log(N)
bool resuelveCaso() {
	int N;
	char c;
	string nombre;
	int gravedad;
	cin >> N;
	if (N == 0) 
		return false;
	PriorityQueue<tInfo> cola;
	for (int i = 0; i < N;i++){
		cin >> c;
		if (c == 'I'){
			cin >> nombre >> gravedad;
			cola.push({i,nombre,gravedad});
		}
		else if (c == 'A'){
			tInfo info= cola.top();
			cout << info.nombre << "\n";
			cola.pop();
		}
	}
	cout << "---" << "\n";
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
