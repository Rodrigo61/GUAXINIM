/*
 *  VERSAO BFS
 * 
 *  Para resolver este problema a minha ideia foi fazer uma abordagem reversa.
 * Reduzi o problema descobrir em quais posições é possível chegar a 
 * partir de uma borda.
 * 
 * Para fazer isso, a primeira coisa q eu faço é preencher as bordas da
 * matriz dada na entrada da seguinte forma:
 *
 *                       VVV  
 * 		>>V             >>>V<
 * 	    AV<    --->     >AV<<
 *      A<>             >A<><
 *                       AAA
 * 
 * Agora, eu faço um BFS um pouco diferente. Invés de apenas um vértice 
 * de início, eu coloco como início todos os meus vértices na borda. Para
 * fazer isso é só adicionar todos na fila antes de começar meu BFS.
 * 
 * No final do BFS, a minha resposta será todos os vértices q eu n conse-
 * gui visitar a partir das bordas.
 * 
 * Complexidade: O(N^2)
 * */



#include <bits/stdc++.h>

using namespace std;

#define MAXN 512
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

int N;
char grid[MAXN][MAXN];
int vis[MAXN][MAXN];

bool valid(int i, int j)
{
	return i >= 0 && i <= N + 1 && j >= 0 && j <= N + 1;
}

vector<pii> get_neigh(pii u)
{
	vector<pii> result;
	
	if (valid(u.fi - 1, u.se) && grid[u.fi - 1][u.se] == 'V')
	{
		result.pb({u.fi - 1, u.se});
	}
	if (valid(u.fi + 1, u.se) && grid[u.fi + 1][u.se] == 'A')
	{
		result.pb({u.fi + 1, u.se});
	}
	if (valid(u.fi, u.se - 1) && grid[u.fi][u.se - 1] == '>')
	{
		result.pb({u.fi, u.se - 1});
	}
	if (valid(u.fi, u.se + 1) && grid[u.fi][u.se + 1] == '<')
	{
		result.pb({u.fi, u.se + 1});
	}
	
	return result;
}

int main()
{
	scanf("%d\n", &N);
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%c", &grid[i][j]);
		}
		scanf("\n");
	}
	
	// Adicionando as bordas
	queue<pii> q;
	for (int i = 0; i <= N + 1; i++)
	{
		grid[0][i] = 'V';
		q.push({0, i});
		vis[0][i] = 1;
		
		grid[N + 1][i] = 'A';
		q.push({N + 1, i});
		vis[N + 1][i] = 1;
		
		grid[i][0] = '>';
		q.push({i, 0});
		vis[i][0] = 1;
		
		grid[i][N + 1] = '<';
		q.push({i, N + 1});
		vis[i][N + 1] = 1;
	}

	// BFS
	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		for (pii v : get_neigh(u))
		{
			if (!vis[v.fi][v.se])
			{
				vis[v.fi][v.se] = 1;
				q.push(v);
			}
		}
	}
	
	// Checando
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			total += !vis[i][j];
		}
	}
	
	printf("%d\n", total);
	
}
