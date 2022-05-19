#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;



long long int esfuerzoTotal(PriorityQueue<long long int>cola, int N){
	long long int t = 0;
	int e1,e2;
	while (cola.size() > 1){
		e1 = cola.top(); cola.pop();
		e2 = cola.top(); cola.pop();
		t += e1+e2;
		cola.push(e1+e2);
	}
	return t;
}
bool resuelveCaso(){
	int N;
	cin >> N;
	if (N==0) return false;
	PriorityQueue<long long int>cola;
	long long int e;//elemento
	long long int t;//esfuerzo total
	for (int i = 0; i < N; i++){
		cin >> e;
		cola.push(e);
	}
	t = esfuerzoTotal(cola,N);
	cout << t << "\n";
	return true;

}


int main(){

#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto buf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());
#ifndef DOMJUDGE
	cin.rdbuf(buf);
	system("PAUSE");
#endif
	return 0;
}