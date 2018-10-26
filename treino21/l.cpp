#include<bits/stdc++.h>

#define db(x) cerr << #x << " = " << x << endl;
using namespace std;

#define MAXN 2001
#define MAXM 5001
#define INF 1e18
#define ll long long

set<pair<int, ll>> adj[MAXN];

struct Edge{
	
	int u, v;	
	ll w;
};

Edge edges[MAXM];
ll d[MAXN];

int N, M;

bool has_neg_cycle()
{
	memset(d, 0, sizeof(d));
	int x;
	
	for (int i = 0; i < N; i++)
	{
		x = -1;
		for (int j = 0; j < M; j++)
		{
			Edge e = edges[j];
			if (d[e.u] + e.w < d[e.v])
			{
				d[e.v] = d[e.u] + e.w;
				x = e.v;
			}
		}
	}
	
	return x != -1;
}

void restart()
{
	for (int i = 0; i < N; i++)
	{
		adj[i].clear();
	}
}


int main()
{
	
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d%d", &N, &M);
		
		restart();
		
		int u, v;
		ll u2v;
		ll min_edge = INF;
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%lld", &u, &v, &u2v);
			
			--u, --v;
			
			auto it = adj[u].upper_bound({v - 1, INF});
			if (it == adj[u].end())
			{
				adj[u].insert({v, u2v});
			}
			else if (it->first != v)
			{
				adj[u].insert({v, u2v});
			}
			else if (it->second > u2v)
			{
				adj[u].erase(it);
				adj[u].insert({v, u2v});
			}
			
			min_edge = min(min_edge, u2v);
			
		}
		
		if (min_edge >= 0)
		{
			printf("%lld\n", min_edge);
			continue;
		}
		
		
		int k = 0;
		for (int i = 0; i < N; i++)
		{
			for (auto a : adj[i])
			{
				Edge e;
				e.u = i;
				e.v = a.first;
				e.w = a.second;
				edges[k] = e;
				++k;
			}
		}
		
		M = k;
		
		if (has_neg_cycle())
		{
			printf("-inf\n");
		}
		else
		{
			printf("%lld\n", *min_element(d, d+N));
		}
		
	}
	
	return 0;
}
