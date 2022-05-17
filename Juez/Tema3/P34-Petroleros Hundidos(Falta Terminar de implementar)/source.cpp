#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#include "ConjuntosDisjuntos.h"

/*
Tema:3
Problema34 Petroleros Hundidos
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/
//pantalla completa alt+shift+enter


using Mapa = vector<vector<char>>;
class Manchas{
public:
	//marked(F, vector<bool>(C, false));
	Manchas(const Mapa &M) : F(M.size()), C(M[0].size()), marked(M.size(), vector<bool>(M[0].size(), false)) {
		const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 },{ -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 } };
		for (int i = 0; i < F;i++){
			for (int j = 0; j < C; j++){
				if (M[i][j] == '#' && !marked[i][j]){
					// se recorre una nueva mancha
					++_numero;
					int nuevotam = 0;
					dfs(M, i, j, nuevotam,dirs);
					_maximo = max(_maximo, nuevotam);
				}

			}
		}
	}
	int numero() const { return _numero; }
	int maximo() const { return _maximo; }
	
private:
	vector<vector<bool>> marked;
	int _maximo;
	int _numero;
	int F;
	int C;
	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}
	//const vector<pair<int, int>> dirs; 
	// recorrido en profundidad de la mancha del vértice <i,j>

	void dfs(Mapa const& M, int i, int j, int & tam, const vector<pair<int, int>> dirs) {
		marked[i][j] = true;
		++tam;
		for (auto d : dirs) {
			int ni = i + d.first, nj = j + d.second;
			if (correcta(ni, nj) && M[ni][nj] == '#' && !marked[ni][nj]) {
				dfs(M, ni, nj, tam,dirs);
			}
		}
	}
};


bool resuelveCaso(){
	int K = 0;
	int fil, col;
	int F, C;
	cin >>F>> C;
	if (!cin) 
		return false;

	//Mapa M(F);
	Mapa M(F, vector<char>(C));
	// leemos la imagen
	char c;
	cin.get(c);
	for (int i = 0; i <F; i++) {
		for (int j = 0; j < C; j++) {
			cin.get(M[i][j]);
		}
		cin.get(c);
	}
	//Manchas manchas(M);
	//cout << manchas.maximo() << " ";

	cin >> K;

	vector<pair<int, int>> aux(K);
	for (int i = 0; i < K;i++){
		cin >> fil >> col;
		aux[K].first = fil;
		aux[K].second=col;
		//M[fil-1][col-1] = '#';
		//Manchas manchas(M);
		
		//cout << manchas.maximo() << " ";
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
