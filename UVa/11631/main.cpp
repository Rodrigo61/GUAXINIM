#include <bits/stdc++.h>

using namespace std;

#define piii pair<int, pair<int, int>>
#define ll long long
#define all(x) x.begin(), x.end()
#define MAXN 212345
#define fi first
#define se second
#define db(x) cerr << #x << " = " << x << endl

int N, M;
vector<piii> edges;
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

void reinit()
{
	edges.clear();
	rep.clear();
	sz.clear();
}

int main()
{
	
	while(scanf("%d%d", &N, &M), N)
	{
		edges.resize(M + 1);
		rep.resize(N + 1);
		sz.resize(N + 1);
		int total_cost = 0;
		for (int i = 0; i < M; i++)
		{
			int u, v;
			ll w;
			
			scanf("%d%d%lld", &u, &v, &w);
			
			++u, ++v;
			edges[i] = {w, {u, v}};
			total_cost += w;
		}
		
		sort(all(edges));
		int total_connections = 0;
		ll cost = 0;
		for (auto i = edges.begin(); i != edges.end() && total_connections != N - 1; i++)
		{
			if (!connected(i->se.fi, i->se.se))
			{
				cost += i->fi;
				connect(i->se.fi, i->se.se);
				++total_connections;
			}
		}
		
		printf("%lld\n", total_cost - cost);
		reinit();
	}
}
