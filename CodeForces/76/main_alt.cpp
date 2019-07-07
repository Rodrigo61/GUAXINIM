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
	
};

bool compGold(Edge &a, Edge &b)
{
	return a.g < b.g;
}

bool compSilver(Edge &a, Edge &b)
{
	return a.s < b.s;
}

int N, M;
ll G, S;
vector<Edge> edges;
vector<int> rep;
vector<int> sz;

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


int main()
{
	scanf("%d%d", &N, &M);
	scanf("%lld%lld", &G, &S);
	
	set<ll> values_gold;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		ll g, s;
		scanf("%d%d%lld%lld", &u, &v, &g, &s);
		edges.pb({u, v, g, s});
		values_gold.insert(g);
	}
	
	sort(all(edges), compSilver);
	ll min_cost = INF;
	for (ll limit : values_gold)
	{
		clear_dsu();
		int total_connections = 0;
		ll gold = 0, silver = 0;
		for (auto i = edges.begin(); i != edges.end() && total_connections != N - 1; i++)
		{
			if (!connected(i->u, i->v) && i->g <= limit)
			{
				connect(i->u, i->v);
				++total_connections;
				gold = max(gold, i->g);
				silver = max(silver, i->s);
			}
		}
		
		if (total_connections == N - 1)
		{
			min_cost = min(min_cost, gold * G + silver * S);
		}
	}
	
	if (min_cost == INF)
	{
		min_cost = -1;
	}
	
	printf("%lld\n", min_cost);
}
