#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
#define MAXN 112
 
int vis[MAXN][MAXN];
int N, M;
char grid[MAXN][MAXN];


void dfs(pii u)
{
	if (u.fi < 0 || u.fi >= N || u.se < 0 || u.se >= M || grid[u.fi][u.se] == '#')
		return;
		
	if (vis[u.fi][u.se]) 
		return;
		
	vis[u.fi][u.se] = 1;
	dfs({u.fi - 1, u.se});
	dfs({u.fi + 1, u.se});
	dfs({u.fi, u.se - 1});
	dfs({u.fi, u.se + 1});
}

 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		db(T);
		scanf("%d%d\n", &N, &M);
		db(N);
		db(M);
		vii endpoints;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				char c;
				scanf("%c", &c); 
				grid[i][j] = c;
				
				if ((i == 0 || j == 0 || i == N - 1 || j == M - 1) && c == '.')
				{
					endpoints.pb({i, j});
				}
				
			}
			scanf("\n");
		}
		
		db((int)endpoints.size());
		if ((int)endpoints.size() != 2)
		{
			printf("invalid\n");
			continue;
		}
		
		memset(vis, 0, sizeof(vis));
		dfs(endpoints.back());
		
		if (vis[endpoints[0].fi][endpoints[0].se])
		{
			printf("valid\n");
		}
		else
		{
			printf("invalid\n");
		}
		
	}
	
}
