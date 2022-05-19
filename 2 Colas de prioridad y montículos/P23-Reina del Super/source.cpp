#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#include "PriorityQueue.h"

/*
Tema:2
Problema23 La Reina del super
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


struct tInfo{
	int tiempo;
	int caja;
};

bool operator <(tInfo a, tInfo b){
	if (a.tiempo < b.tiempo)
		return true;
	else if (a.tiempo == b.tiempo && a.caja < b.caja)
		return true;
	else
		return false;
}

//El coste es O(n Log n)donde n es el numero de clientes esperando en la cola 
//Tiene que hacer n vueltas, y el coste de insertar(push) y eliminar(pop) un cliente en la cola es logn, 
//no se tiene en cuenta el pop de la queue porque es constante
int supermercado(PriorityQueue<tInfo> &cola, queue<tInfo> &v, int cajas){
	tInfo info;
	if (cola.size()<cajas){
		return cola.size() + 1;
	}
	while (v.size()>0){
			info = cola.top();
			cola.pop();
			info.tiempo += v.front().tiempo;
			cola.push(info);
			v.pop();
	}
	return cola.top().caja;
}


bool resuelveCaso() {
	int cajas, clientes;
	cin >> cajas >> clientes;
	if (cajas == 0 && clientes==0) return false;
	PriorityQueue<tInfo> cola;
	queue<tInfo> v;
	tInfo info;
	for (int i = 0; i < clientes; i++){
		if (i + 1 <= cajas){
			cin >> info.tiempo;
			info.caja = i + 1;
			cola.push(info);
		}
		else{
			cin >> info.tiempo;
			info.caja =-1;
			v.push(info);
		}
	}
	int caja = supermercado(cola,v,cajas);
	cout << caja << "\n";
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
