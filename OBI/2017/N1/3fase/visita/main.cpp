#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 11234

vector<int> vizinhos[MAXN], pesos[MAXN];
int distancia[MAXN];

void dfs(int u, int pai_u, int distancia_atual)
{
	// atualiza o no com a distancia acumulada atual
	distancia[u] = distancia_atual;
	
	// continua o caminho pelos vizinhos
	for (int i = 0; i < (int)vizinhos[u].size(); ++i)
	{
		int v = vizinhos[u][i];
		int w = pesos[u][i];
		
		if (v != pai_u)
			dfs(v, u, distancia_atual + w); // soh vai para o vizinho que n foi visitado (n eh pai) e acumula a distancia
	}
}

int main()
{
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	
	for (int i = 0; i < N - 1; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		
		// monta o grafo
		vizinhos[u].push_back(v);
		pesos[u].push_back(w);
		vizinhos[v].push_back(u);
		pesos[v].push_back(w);
	}
	
	// atualiz a distancia de todos os Nos, usando o A como referencia
	dfs(A, 0, 0);
	
	printf("%d\n", distancia[B]);
}
