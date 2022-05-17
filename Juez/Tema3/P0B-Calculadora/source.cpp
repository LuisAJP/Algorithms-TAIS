#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class MaquinaCalculadora{
public:
	//	COSTE O(N) N = 10000
	MaquinaCalculadora(int inicio, int final):pulsaciones(0),origen(inicio),destino(final){
		// Coste O(n) n=10000
		marked.assign(10000, false);
		distTo.assign(10000, -1);
		pulsaciones = bfs(origen, destino);
	}
	int numPulsaciones(){ return pulsaciones;}

private:
	int pulsaciones;
	int origen;
	int destino;
	vector<bool> marked;
	vector<int> distTo;

	int sumaUno(int n){ return (n + 1) % 10000;}
	int porDos(int n){ return (n * 2) % 10000;}
	int entreTres(int n){ return (n / 3) % 10000;}

	//	Recorrido en anchura para calcular el menor nunero de pasos posibles
	//	En el peor de los casos tiene un coste de O(n) n=10000	
	int bfs(size_t ini, size_t fin) {
		if (ini == fin)
			return 0;
		queue<size_t> q;
		distTo[ini] = 0;
		marked[ini] = true;
		q.push(ini);
		while (!q.empty()) {
			auto v = q.front(); q.pop();
			vector<int> adyacentes(3);
			adyacentes[0] = sumaUno(v);
			adyacentes[1] = porDos(v);
			adyacentes[2] = entreTres(v);
			for (auto w : adyacentes) {
				if (w == fin)
					return distTo[v] + 1;
				if (!marked[w]) {
					// Esto es un contador, que vca acumulnaod uno mas al nodo actual
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}
};


bool resuelveCaso() {
	int A, B;
	cin >> A >> B;
	if (!cin)
		return false;
	MaquinaCalculadora maquinaCalculadora(A,B);
	cout << maquinaCalculadora.numPulsaciones()<<"\n";
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
