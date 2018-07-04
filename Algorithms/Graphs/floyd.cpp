/*
 * O(V^3)
 *
 * Setar V e adj_matrix.
 *
 * Adj_matrix com custo de i -> i = 0 e vertices sem aresta com custo INF
 *
 */

#define INF 1000000000

int V;
vector<vi> adj_matrix;

void floyd () {

	for (int k = 0; k < V; k++) 
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
        		adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
}
