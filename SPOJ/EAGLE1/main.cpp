#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 112345

int N;
vi G[MAXN];
vll W[MAXN];
ll dist_from_diameter[MAXN];

void clear()
{
	for (int i = 1; i <= N; i++)
	{
		G[i].clear();
		W[i].clear();
		dist_from_diameter[i] = 0;
	}
	
}

void dfs(int u, int pu, ll deep, ll &most_deep, int &most_deep_vertex)
{
	if (deep > most_deep)
	{
		most_deep = deep;
		most_deep_vertex = u;
	}
	
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int v = G[u][i];
		ll w = W[u][i];
		if (v != pu)
		{
			dfs(v, u, deep + w, most_deep, most_deep_vertex);
		}
	}
}

void dfs_dist(int u, int pu, ll dist)
{
	dist_from_diameter[u] = max(dist_from_diameter[u], dist);
	for (int i = 0; i < (int)G[u].size(); ++i)
	{
		int v = G[u][i];
		ll w = W[u][i];
		if (v != pu)
		{
			dfs_dist(v, u, dist + w);
		}
	}
}

void calc_diameter()
{
	ll most_deep = 0;
	int most_deep_vertex1 = 0;
	dfs(1, 0, 0, most_deep, most_deep_vertex1);
	
	most_deep = 0;
	int most_deep_vertex2 = 0;
	dfs(most_deep_vertex1, 0, 0, most_deep, most_deep_vertex2);
	
	dfs_dist(most_deep_vertex1, 0, 0);
	dfs_dist(most_deep_vertex2, 0, 0);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N - 1; i++)
		{
			int u, v;
			ll w;
			scanf("%d%d%lld", &u, &v, &w);
			G[u].pb(v);
			G[v].pb(u);
			W[u].pb(w);
			W[v].pb(w);
		}
		
		calc_diameter();
		
		for (int i = 1; i <= N; i++)
		{
			printf("%lld ", dist_from_diameter[i]);
		} 
		printf("\n");
		
		
		clear();
	}
	
}
