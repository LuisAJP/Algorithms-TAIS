#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

typedef struct{
	bool repite;
	int ini, fin, intervalo;

}Tarea;

bool operator<(Tarea const &a, Tarea const&b){
	return a.ini < b.ini ;
}

bool resuelveCaso() {
	int N, M,T;
	cin >> N >> M>>T;
	if (!cin) return false;
	PriorityQueue<Tarea> cola;
	Tarea tarea;
	tarea.repite = false;

	for (int i = 0; i < N; i++){
		cin >> tarea.ini >> tarea.fin;
		cola.push(tarea);
	}
	tarea.repite = true;
	for (int i = 0; i < M; i++){
		cin >> tarea.ini >> tarea.fin>>tarea.intervalo;
		cola.push(tarea);
	}
	bool conflicto = false;
	int ocupado = 0;
	
	while (!conflicto && !cola.empty() && cola.size()>0 && cola.top().ini<T){
		Tarea primer = cola.top(); cola.pop();
		if (primer.ini<ocupado)//existe solapamiento
			conflicto = true;
		ocupado = primer.fin;
		if (primer.repite)
			cola.push({ true, primer.ini + primer.intervalo, primer.fin + primer.intervalo,primer.intervalo});
	}
	if (conflicto)
		cout <<"SI"<< "\n";
	else
		cout << "NO" << "\n";
	
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



