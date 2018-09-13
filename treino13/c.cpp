#include<bits/stdc++.h>

using namespace std;

vector<int> G[300001];

int valor[300001];
int vis[300001];
vector<pair<int, int> > vet;

int dfs(int x)
{
	int y;
	if(vis[x])
		return 0;
	vis[x] = 1;
	int r = valor[x];
	for(int i = 0; i < (int)G[x].size(); i++)
	{
		if(!vis[G[x][i]])
		{
			y = dfs(G[x][i]);
			if(y == 1)
			{
				vet.push_back({x, G[x][i]});
				r ^= 1;
			}
		}
	}
	return r;
}

int main()
{
	int N, M, K, u, v, ans = 0;
	scanf("%d %d %d", &N, &M, &K);
	while(M--)
	{
		scanf("%d %d", &u, &v);
		valor[u] ^= 1;
		valor[v] ^= 1;
	}
	//for(int i = 1; i <= N; i++)
		//printf("%d\n", valor[i]);
	while(K--)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= N; i++)
		if(!vis[i])
			ans |= dfs(i);
	if(ans)
		printf("NO\n");
	else
	{
		printf("YES\n%d\n", (int)vet.size());
		for(int i = 0; i < (int)vet.size(); i++)
			printf("%d %d\n", vet[i].first, vet[i].second);
	}
	return 0;
}
