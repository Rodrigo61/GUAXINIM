#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 2005
#define MAXM 50005
#define fi first
#define se second

int N, M;

vector<int> G[MAXN];
vector<int> GR[MAXN];

pair<int, int> edges[MAXM];

int vis[MAXN];

int candidates[MAXM];

int removed_edge;

int n_candidates;

int c;

void dfs1(int u)
{
	vis[u] = 1;
	db(G[u].size());
	for (int e : G[u])
	{
		int v = edges[e].se;
		
		db(v);
		if (!vis[v])
		{
			candidates[n_candidates] = e;
			db(edges[e].fi);
			db(edges[e].se);
			++n_candidates;
			dfs1(v);
		}
	}
}

void dfs2(int u)
{
	vis[u] = 1;
	db(u);
	for (int e : GR[u])
	{
		int v = edges[e].fi;
		
		if (!vis[v])
		{
			candidates[n_candidates] = e;
			++n_candidates;
			db(edges[e].fi);
			db(edges[e].se);
			dfs2(v);
		}
	}
}

bool can_reach(int u, int t)
{
	if (u == t)
	{
		return true;
	}
	
	vis[u] = c;
	
	bool ans = 0;
	db(u);
	for (int e : G[u])
	{
		if (e == removed_edge)
		{
			continue;
		}
		
		int v = edges[e].se;
		db(v);
		
		if (vis[v] != c)
		{
			ans |= can_reach(v, t);
		}
	}
	
	return ans;
}


int main()
{
	
	scanf("%d%d", &N , &M);
	
	int u, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		
		G[u].push_back(i);
		GR[v].push_back(i);
		edges[i] = {u,v};
	}
	
	dfs1(1);
	memset(vis, 0, sizeof(vis));
	db(n_candidates);
	dfs2(1);
	
	db(n_candidates);
	
	set<pair<int, int>> ans;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n_candidates; i++)
	{
		int e = candidates[i];
		removed_edge = e;
		db(edges[e].fi);
		db(edges[e].se);
		++c;
		if (!can_reach(edges[e].fi, edges[e].se))
		{
			ans.insert(edges[e]);
		}
	}
	
	printf("%d\n", (int)ans.size());
	for (auto &e : ans)
	{
		printf("%d %d\n", e.fi, e.se);
	}
	
	
	
	return 0;
}
