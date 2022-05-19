#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>//sort
#include<functional>//greater or less
#include<vector>
using namespace std;


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
	int C, F, N;
	cin >> C >> F >> N;
	if (C == 0 && F == 0 && N == 0) return false;
	vector<tInfo>v(N);
	
	for (int i = 0; i < N; i++)
		cin >> v[i].ini >> v[i].fin;
	sort(v.begin(),v.end(),less<>());


	if (v[0].ini>C){
		cout << "Imposible" << "\n";
		return true;
	}
		

	int i = 1;
	bool ok=false;
	int inicial, final;
	inicial = v[0].ini;
	final = v[0].fin;
	int cont = 1;
	bool posible = true;
	tInfo info;
	info.ini = 0;
	info.fin = 0;
	while (i < N && !ok && posible){
		//existe solapamiento
		if (final > v[i].ini){
			if (v[i].ini == inicial && v[i].fin >final)// me voy quedando con el de mayor longitud
				final = v[i].fin;
			else{
				if (info.fin < v[i].fin)//si el segmento es mas largo me voy quedando con el mas largo
					info = v[i];
			}
		}
		//No existe solapamiento
		else{// si final<v[i].ini  || final==v[i].ini 
			if (v[i].ini==final &&v[i].fin > info.fin){
				info = v[i];
				cont++;
				final = v[i].fin;
			}
			else{
				final = info.fin;
				cont++;
				info = v[i];
			}
			
			
		}
		//comprobar si se ha ocupado todo
		if (final >= F)
			ok = true;
		i++;
	}
	
	if (posible)
		cout<<cont << "\n";
	else
		cout << "Imposible" << "\n";
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
