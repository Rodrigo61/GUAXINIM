/*
    Funcao para manter o fecho transitivo de um grafo. 
    Consulta O(1)
    Update O(n^2/64)
*/

bitset<MAXN> graph[MAXN];

void add_edge(int a, int b)
{
	if (graph[a][b])
		return;
	
	graph[a][b] = 1;
	graph[a] |= graph[b];
 
	for (int i = 1; i <= n; i++)
		if (graph[i][a])
			graph[i] |= graph[a];
}