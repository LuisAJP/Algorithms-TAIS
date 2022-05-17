#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include "GrafoDirigido.h"

using namespace std;

/*
Problema2 Ordenando tareas
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/


//Algoritmo utilizado "Topological Sort"
//	Tiene coste O(V+E) recorre los vertices y aristas, donde V es el numero de vertices
//y E es el numero de aristas
class Tareas{
public:
	Tareas(const GrafoDirigido &G) :marked(G.V(), false), ciclo(G.V(), false), pila(), ciclico(false){

		for (int v = 1; v < G.V(); v++){
			if (!marked[v])
				dfs(G, v);
		}
	}
	bool hayCiclo(){
		return ciclico;
	}
	stack<int> getPila(){
		return pila;
	}
private:
	vector<bool> marked;
	vector<bool> ciclo;
	stack<int>pila;
	bool ciclico;

	//Tiene coste O(V + E)
	void dfs(const GrafoDirigido &G, int v){
		marked[v] = true;
		ciclo[v] = true;
		for (int w : G.ady(v)){
			if (!marked[w]){
				dfs(G, w);
			}
			if (ciclo[w]){//Compruebo si existe ciclo
				ciclico = true;
			}
		}
		ciclo[v] = false;
		pila.push(v);//O(1)
	}
};

bool resuelveCaso(){
	int V, E;
	cin >> V >> E;
	if (!cin) return false;
	int v, w;
	GrafoDirigido G(V + 1);
	for (int i = 0; i < E; i++){
		cin >> v >> w;
		G.ponArista(v, w);
	}
	Tareas tareas(G);

	if (tareas.hayCiclo())
		cout << "Imposible\n";
	else{
		stack<int>pila;
		pila = tareas.getPila();
		while (!pila.empty()){
			int e;
			e = pila.top();pila.pop();
			cout << e << " ";
		}
		cout << "\n";
	}
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