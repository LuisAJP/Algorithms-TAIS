#include <fstream>
#include <iostream>
#include <vector>

#include "PriorityQueue.h"
using namespace std;


struct tInfo{
	unsigned int m;//musico
	unsigned int p;//partitura
};

bool operator > (const tInfo &a, const tInfo &b) {
	unsigned int musicos1, musicos2;

	musicos1 = a.m / a.p;
	if (a.m % a.p != 0)
		musicos1++;

	musicos2 = b.m / b.p;
	if (b.m % b.p != 0)
		musicos2++;

	return musicos1 > musicos2;
}

//Coste O(n), siendo n el nĂºmero de partituras.
bool resuelveCaso(){
	unsigned int p, n, r;
	cin >> p;
	if (!cin)  return false;
	cin >> n;
	PriorityQueue<tInfo,greater<tInfo>> pq;
	tInfo info;
	info.p = 1;

	//coste NlogN
	for (unsigned int i = 0; i < n; ++i){
		cin >> info.m;
		pq.push(info);//logN
	}
	p = p - pq.size();

	while (p > 0){
		info = pq.top(); pq.pop();//logN
		info.p++;
		pq.push(info);//logN
		p--;
	}
	//Saca el elemento con mayor numero de musicos de la cola
	info = pq.top();//constante
	r = info.m / info.p;

	if (info.m % info.p != 0) 
		r++;
	cout << r << '\n';

	return true;
}

int main() {// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
