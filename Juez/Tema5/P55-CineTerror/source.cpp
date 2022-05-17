#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>//sort
#include<functional>//greater or less
#include<vector>
using namespace std;


/*
Tema:3
Problema55 Maratón Cine de terror
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

struct Hora {
	int hora;
	int minutos;
	int duracion;
};

struct tInfo {
	Hora ini;
	Hora fin;
};

bool operator<(Hora h1, Hora h2){
	return h1.hora < h2.hora || h1.hora == h2.hora && h1.minutos<h2.minutos;
}
//ordenar por finalización
bool operator<(tInfo a, tInfo b){
	return a.fin < b.fin;
}


bool operator>=(Hora const &a, Hora const &b) {
	if (a.hora == b.hora) return a.minutos >= b.minutos;
	return (a.hora >= b.hora);
}

void calcularHoraFinalizacion(vector<tInfo> &v,int N){
	Hora h;
	for (int i = 0; i < N; i++){
		h = v[i].ini;
		h.minutos += h.duracion + 10;
		while (h.minutos >= 60) {
			h.minutos -= 60;
			++h.hora;
		}
		v[i].fin = h;
	}
}


//N numero de peliculas
bool resuelveCaso(){
	int N;
	cin >> N;
	if (N == 0) return false;
	char c;
	Hora h;
	vector<tInfo> v(N);
	int d;//duracion
	for (int i = 0; i < N; i++){
		cin >> h.hora >> c >> h.minutos >> h.duracion;
		v[i].ini = h;
	}
	calcularHoraFinalizacion(v,N);
	sort(v.begin(), v.end(), less<>());//ordena hora por finalizacion

	int peliculas = 1;
	Hora final = v[0].fin;
	for (int i = 1; i < N; i++){
		if (v[i].ini >= final){//no hay solapamiento
			peliculas++;
			final = v[i].fin;
		}
	}
	cout << peliculas << "\n";
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
