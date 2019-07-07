/*
 *  VERSAO DFS
 * 
 *	Para resolver esse problema usaremos do fato de que se ao seguirmos
 *  um caminho nós não conseguimos chegar a borda da matriz então todas
 *  as posições que visitamos durante esse caminho são necessáriamente 
 *  seguras.
 * 
 * 	Para definir se uma posição é segura nós temos a matriz state[N][N]
 *  que é True caso a posicao seja segura e False caso o contrario. 
 * 
 * 	A ideia então do algoritmo é, tentamos fazer um caminho a partir de
 * 	todos as posicoes da matriz. Paramos de seguir no caminho quando alguma
 * 	das seguintes coisas ocorrem:
 * 
 * 		* Chegamos em uma bordar  
 * 			->  Dizemos que todos as posicoes visitadas até então devem
 * 				ter state = False
 * 		* Chegamos em um vértice já visitado
 * 			->  Nesse caso, basta verificar o estado dessa posicao, pois
 * 				se ele for seguro todos as posicoes visitadas até agora no caminho atual
 * 				devem ser seguras. O mesmo é valido para se for nao seguro
 * 				OBS: Repare que a primeira coisa que fazemos quando descobrimos
 * 					 uma nova posição é colocar seu estado como True. Isso
 * 					 nos permite deduzir que se chegarmos novamente naquela
 * 				     posição é por que temos um ciclo e não precisamos 
 * 					 continuar o caminho. E assim mantemos a simplicidade
 * 					 descrita acima de apenas perguntas o estado de uma posicao
 * 					 que ja foi visitada.
 *
 * Como nós definimos o estado de cada vértice apenas uma vez temos:
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
bool state[MAXN][MAXN];

bool dfs(int i, int j)
{
	if (i < 0 || i >= N || j < 0 || j >= N)
	{
		return false;
	}
	
	if (vis[i][j])
	{
		return state[i][j];
	}
	vis[i][j] = 1;
	state[i][j] = true;
	
	int y = i, x = j;
	switch(grid[i][j])
	{
		case '>': x++; break;
		case '<': x--; break;
		case 'V': y++; break;
		case 'A': y--; break;
	}
	
	state[i][j] &= dfs(y, x);
	return state[i][j];
}

int main()
{
	scanf("%d\n", &N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &grid[i][j]);
		}
		scanf("\n");
	}
	
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!vis[i][j])
			{
				dfs(i, j);
			}
			total += (int)state[i][j];
		}
	}
	
	printf("%d\n", total);
}
