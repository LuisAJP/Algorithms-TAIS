
// NOMBRE Y APELLIDOS

// comentario sobre la solución, incluyendo la recurrencia y
// el análisis del coste tanto en tiempo como en espacio adicional

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Matriz.h"
using namespace std;
const int asci = 97;

void palindromo_prep(Matriz<int> izq, Matriz<int> der, string sol) {
	vector<int> iguales(sol.size());
	for (int i = 0; i < sol.size(); i++) {
		for (int j = i-1; j >=0; j--) {
			der[i][sol[j]-asci]++;
		}
		for (int j = i + 1; j < sol.size(); j++) {
			izq[i][sol[j] - asci]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < sol.size(); i++) {
		for (int j = 0; j < 25; j++) {
			sum += min(izq[i][j], der[i][j]);
		}
		iguales[i] = sum;
		sum = 0;
	}

}
bool resuelveCaso() {
   
  
   string palabra;
   cin >> palabra;
   if (!cin)
	   return false;
   Matriz<int> izq(palabra.size(), 25, 0);
   Matriz<int> der(palabra.size(), 25, 0);
   palindromo_prep(izq, der, palabra);
   
   return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());
   
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
