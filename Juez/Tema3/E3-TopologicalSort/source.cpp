#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include "GrafoDirigido.h"

using namespace std;

/*
Problema1 Ordenando tareas
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/



class TopologicalSort{
public:
	TopologicalSort(const GrafoDirigido &G) :marked(G.V(), false), pila(){
		for (int v = 0; v < G.V(); v++){
			if (!marked[v])
				dfs(G, v);
		}
		
	}
	stack<int> getPila(){
		return pila;
	}
private:
	vector<bool> marked;
	vector<bool> aux;
	stack<int>pila;
	void dfs(const GrafoDirigido &G,int v){
		marked[v] = true;
		for (int w : G.ady(v)){
			if (!marked[w])
				dfs(G, w);
		}
		pila.push(v);
	}
};

bool resuelveCaso(){
	int V, E;
	cin >> V >> E;
	if (!cin) return false;
	int v, w;
	GrafoDirigido G(V);
	for (int i = 0; i < E;i++){
		cin >> v >> w;
		G.ponArista(v,w);
	}
	TopologicalSort topologicalSort(G);
	stack<int>pila; 
	pila = topologicalSort.getPila();
	while (!pila.empty()){
		int a;
		a = pila.top();
		pila.pop();
		cout <<a<< " ";
	}
	cout << "\n";
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