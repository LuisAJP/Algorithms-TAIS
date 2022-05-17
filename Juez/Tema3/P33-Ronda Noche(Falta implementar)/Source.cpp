#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

using Mapa = vector<vector<char>>;

class RondaNoche {

	

public:

	RondaNoche(const Mapa & M) : F(M.size()), C(M[0].size()), 
		marked(F, vector<bool>(C, false)) {

		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (M[i][j] == '#' && !marked[i][j]) {
					// se recorre una nueva mancha
					
					int nuevotam = 0;
					bfs(M, i, j);
				
				}
			}
		}
	
	
	}

private:
	int F;
	int C;
	vector<vector<bool>> marked; // marked[i][j] = se ha visitado <i,j>
	vector<vector<int>> distTo;

	// ¿Hay camino del origen a v?
	bool hayCamino(int f,int c) const {
		return marked[f][c];
	}
	// número de aristas entre s y v
	int distancia(int f,int c) const {
		return distTo[f][c];
	}

	void bfs(const Mapa & M,int f, int c) {
		/*queue<int> q;
		distTo[f][c] = 0;
		marked[f][c] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : G.ady(v)) {
				if (!marked[w]) {
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}*/
	}
};


void resuelveCaso() {
	int N, fil, col;
	cin >> col >> fil;
	Mapa M(fil, vector<char>(col));
	for (int i = 0; i < fil;i++) {
		for (int j = 0; j < col; j++) {
			cin >> M[i][j];
		}
	}
	RondaNoche ronda(M);
	cout << "";
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos;i++) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
