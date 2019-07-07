// Na maratona, em geral é suficiente importar bits/stdc++.h para utilizar qualquer 
// biblioteca/estrutura de dados. A biblioteca bits/stdc++.h já faz vários
// imports automaticamente.
#include <bits/stdc++.h>

// sem essa linha qualquer função/estrutura de dados da biblioteca padrão
// do c++ (STL) teria que ser usada como: std::pair<int, int> invés de só
// pair<int, int>
using namespace std;

// Aqui estou renomeando o tipo `pair<int, int>` para `pii`
#define pii pair<int, int>  

// Nas maratona é bem comum utilizar variáveis globais para economizar
// código e tempo de escrita. Mas isso costuma não ser uma boa prática
// em outros contextos de programação.
int grid[5][5];
int vis[5][5];   // marco se uma posição foi visitada. vis[i][j] = 1 se (i, j) já foi visitado


bool valid(int i, int j)
{
	/*
	 * Função auxiliar que diz se um posição qualquer (i,j) está contida
	 * na matriz e pode ser utilizada (grid[i][j] == 0)
	 * */
	return i >= 0 && i < 5 && j >= 0 && j < 5 && grid[i][j] == 0;
}

vector<pii> adj(pii u)
{
	/*
	 * Função que dado uma posicao qualquer u = (i,j) retorna todos os
	 * vizinhos válidos.
	 * */
	 
	int i = u.first;
	int j = u.second;
	vector<pii> adj_vector;
	
	if (valid(i - 1, j))
	{
		adj_vector.push_back({i - 1, j});
	}
	if (valid(i + 1, j))
	{
		adj_vector.push_back({i + 1, j});
	}
	if (valid(i, j - 1))
	{
		adj_vector.push_back({i, j - 1});
	}
	if (valid(i, j + 1))
	{
		adj_vector.push_back({i, j + 1});
	}
	
	return adj_vector;
}

void dfs(pii u)
{
	/*
	 * DFS para fazer uma busca completa
	 * */
	vis[u.first][u.second] = 1;
	for (pair<int, int> v : adj(u))
	{
		if (!vis[v.first][v.second])
		{
			vis[v.first][v.second] = 1;
			dfs(v);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	
	// Trato os diversos casos de teste
	while (T--)
	{
		
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				vis[i][j] = 0; // como o vis é global, preciso reiniciá-lo com 0
				scanf("%d", &grid[i][j]); // lendo a matriz da entrada
			}
		}
		
		// Faço uma busca completa a partir da posicao (0, 0)
		dfs({0,0});
		
		// Se a posicao final (4,4) é alcançável, ela deve ter sido visitada
		if (vis[4][4])
		{
			printf("COPS\n");
		}
		else
		{
			printf("ROBBERS\n");
		}
	}
	
}
