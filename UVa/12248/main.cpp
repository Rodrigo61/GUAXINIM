#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
map<int, set<int>> adj;
map<int, int> vis;
int t;

void dfs(int u, int pu, int &comp, bool &cycle) 
{
	vis[u] = t;
	++comp;
	set<int> &s_adj = adj[u];
	for (int v : s_adj)
	{
		if (v == pu) continue;
		if (vis.find(v) == vis.end())
		{
			dfs(v, u, comp, cycle);
		}
		else if (vis[v] == t)
		{
			cycle = true;
			return;
		}
		else
		{
			return;
		}
		
	}
}

int main()
{
	int N, M;
	while (scanf("%d%d", &N, &M), N + M)
	{
		adj.clear();
		vis.clear();
		bool poss = true;
		for (int i = 0; i < M; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].insert(v);
			adj[v].insert(u);
			if ((int)adj[u].size() == 3 || (int)adj[v].size() == 3)
			{
				poss = false;
			}
		}
		
		if (!poss)
		{
			printf("N\n");
			continue;
		}
		
		for (auto p : adj)
		{
			++t;
			if (vis.find(p.fi) == vis.end())
			{
				bool cycle = false;
				int comp = 0;
				dfs(p.fi, 0, comp, cycle);
				if (cycle && comp != N)
				{
					poss = false;
					break;
				}
			}
		}
		
		
		if (!poss)
		{
			printf("N\n");
		}
		else
		{
			printf("Y\n");
		}
		
		
	}
	
	
}
