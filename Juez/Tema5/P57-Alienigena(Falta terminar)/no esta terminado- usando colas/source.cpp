#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>//sort
#include<functional>//greater or less
#include "PriorityQueue.h"
using namespace std;

const int INF = 100000000;
/*
Tema:3
Problema57 El alienigena infiltrado
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/
typedef struct{

	int ini;
	int fin;
}tInfo;

bool operator <(tInfo a, tInfo b){
	return a.ini < b.ini || a.ini == b.ini && a.fin < b.fin;
}
//
//	Tiene un coste O(NLogN + N), N= numero de edificios
//
bool resuelveCaso() {
	int c, f, N;
	cin >> c >> f >> N;
	if (c == 0 && f == 0 && N == 0) return false;
	PriorityQueue<tInfo>pq;
	tInfo info;
	for (int i = 0; i < N; i++){
		cin >> info.ini>>info.fin;
		pq.push(info);
	}
	int minimo = INF;
	PriorityQueue<int>salas;
	int ocupado = 0;
	salas.push(ocupado);
	while (pq.size()>0){
		info = pq.top(); pq.pop();
		ocupado = salas.top();
		if (info.ini < ocupado){//existe solapamiento
			salas.push(info.fin);
			if (info.fin == f){
				minimo = min(minimo, salas.size());
				salas.pop();
			}	
		}
		else{
			if (info.ini==ocupado){
				if (info.fin == f)
					minimo = min(minimo, salas.size());//no se si hacer salas pop

				else{
					salas.pop();
					salas.push(info.fin);
				}
			}
			else{
				salas.pop();
				salas.push(info.fin);
			}
		}
	}


	
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
