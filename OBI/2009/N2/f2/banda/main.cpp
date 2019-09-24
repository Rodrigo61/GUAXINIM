#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()

#define MAXN 112

int mat[MAXN][MAXN];
int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		mat[u][v] = mat[v][u] = w;
	}
	
	int best = -1;
	vi best_sol;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			for (int k = j + 1; k <= N; k++)
			{
				if (mat[i][j] + mat[i][k] + mat[j][k] >= best)
				{
					best = mat[i][j] + mat[i][k] + mat[j][k];
					best_sol = {i, j, k};
				}
			}
		}
	}
	
	for (int i = 0; i < (int)best_sol.size(); i++)
	{
		printf("%d ", best_sol[i]);
		//~ if (i != (int)best_sol.size() - 1)
			//~ printf(" ");
	}
	
		
	
}
