#include <bits/stdc++.h>

using namespace std;

#define piii pair<int, pair<int, int>>
#define ll long long
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define db(x) //cerr << #x << " = " << x << endl
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 212
#define pii pair<int, int>

struct Edge{
	int u, v;
	ll g, s;
	
	Edge(int a, int b, ll c, ll d) 
	{
		u = a;
		v = b;
		g = c;
		s = d;
	}
	
	bool operator<(const Edge &o) const
	{
		if (this->g != o.g)
		{
			return this->g < o.g;
		}
		return this->s < o.s;
	}
};


int N, M;
ll G, S;
vector<Edge> edges;
vector<int> rep;
vector<int> sz;
set<pair<int, ll>> adj[MAXN];
int p[MAXN];
int dist_p[MAXN];
int vis[MAXN];

int get_rep(int u)
{
	if (rep[u])
	{
		return rep[u] = get_rep(rep[u]);
	}
	return u;
}

bool connected(int u, int v)
{
	return get_rep(u) == get_rep(v);
}

void connect(int u, int v)
{
	int ru = get_rep(u);
	int rv = get_rep(v);
	
	if (ru == rv) return;
	
	if (sz[ru] < sz[rv])
	{
		rep[ru] = rv;
		sz[rv] += sz[ru] + 1;
	} 
	else
	{
		rep[rv] = ru;
		sz[ru] += sz[rv] + 1;
	}
}


void clear_dsu()
{
	rep.clear();
	rep.resize(N + 1);
	sz.clear();
	sz.resize(N + 1);
	
}

int find_cycle(int u)
{
	vis[u] = 1;
	for (auto pv : adj[u])
	{
		if (pv.fi == p[u])
		{
			continue;
		}
		
		if (vis[pv.fi])
		{
			dist_p[pv.fi] = pv.se;
			p[pv.fi] = u;
			return pv.fi;
		}
		
		dist_p[pv.fi] = pv.se;
		p[pv.fi] = u;
		int res = find_cycle(pv.fi);
		if (res) return res;
			
	}
	return 0;
}


int main()
{
	scanf("%d%d", &N, &M);
	scanf("%lld%lld", &G, &S);
	
	for (int i = 0; i < M; i++)
	{
		int u, v;
		ll g, s;
		scanf("%d%d%lld%lld", &u, &v, &g, &s);
		edges.pb({u, v, g, s});
	}
	
	sort(all(edges));
	clear_dsu();
	int total_connections = 0;
	ll gold = 0, silver = 0;
	ll res = INF;
	for (auto it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->u;
		int v = it->v;
		auto itu = adj[u].lower_bound({v, 0});
		
		if (u == v)
		{
			continue;
		}
		
		
		if (!connected(u, v))
		{
			adj[u].insert({v, it->s});
			adj[v].insert({u, it->s});
			connect(u, v);
			++total_connections;
		}
		else if (itu != adj[u].end() && itu->fi == v)
		{
			if (itu->se > it->s)
			{
				adj[u].erase(itu);
				adj[v].erase(adj[v].lower_bound({u, 0}));
				adj[u].insert({v, it->s});
				adj[v].insert({u, it->s});		
			}
		}
		else
		{	
			adj[u].insert({v, it->s});
			adj[v].insert({u, it->s});		
			memset(vis, 0, sizeof(vis));
			memset(dist_p, 0, sizeof(dist_p));
			p[u] = -1;
			int start = find_cycle(u);
			int curr = start;
			int max_edge = 0;
			pii pair_edge;
			do {
				db(dist_p[curr]);
				if (max_edge < dist_p[curr])
				{
					max_edge = dist_p[curr];
					pair_edge = {curr, p[curr]};
				}
				
				curr = p[curr];
				db(curr);
			} while (curr != start);
			
			adj[pair_edge.fi].erase(adj[pair_edge.fi].lower_bound({pair_edge.se, 0}));
			adj[pair_edge.se].erase(adj[pair_edge.se].lower_bound({pair_edge.fi, 0}));
			
		}
	
		if (total_connections == N - 1)
		{
			gold = it->g;
			silver = 0;
			for (int i = 1; i <= N; i++)
			{
				for (auto pv : adj[i])
					silver = max(silver, pv.se);
			}
			
			res = min(res, gold * G + silver * S);
		}
	}
	
	if (total_connections != N - 1)
	{
		return !printf("-1\n");
	}
	
	printf("%lld\n", res);
}
