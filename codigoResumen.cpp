Grafos no dirigidos

Si el grafo usa una  matriz de adyacencia v^2
	for (int v = 0; v < G.V(); v++)
		for (int w : G.adj(v))
		StdOut.println(v + "-" + w);

Si el grafo usa una lista de adyacencia el coste es E+V
	for (int v = 0; v < G.V(); v++)
		for (int w : G.adj(v))
		StdOut.println(v + "-" + w);
		
		
tipos de busqueda

Busqueda en profundidad buscar todos los vertices conectados a un vertice principal dado



private void dfs(Graph G, int v)
{
	marked[v] = true;
	for (int w : G.adj(v))
		if (!marked[w])
		{
			dfs(G, w);
		}
}

---------------------------------------------------------------------------------
Busqueda en anchura -> Se usa para hallar el camino minimo, desde un vertice a los demas


class BusquedaAnchura {
public:
	BusquedaAnchura(Grafo const􀀦 G, int s): marked(G.V(), false), distTo(G.V()) {
		bfs(G, s);
	}
	// ¿Hay camino del origen a v?
	bool hayCamino(int v) const {
		return marked[v];
	}
	// número de aristas entre s y v
	int distancia(int v) const {
		return distTo[v];
	}



private:
	vector<bool> marked; // marked[v] = ¿hay camino de s a v?
	vector<int> distTo; // distTo[v] = aristas en el camino s-v más corto
	void bfs(Grafo const􀀦 G, int s) {
		queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
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
		}
	}
};
􀟝􀟜