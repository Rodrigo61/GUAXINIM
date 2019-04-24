#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112345
#define MAXM 212345
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<ll, ll>
#define se second
#define fi first
#define pb push_back


ll N, M;
ll S, T;
vector<ll> G[MAXN];
vector<ll> W[MAXN];
ll dist[MAXN][2];
ll tmp[MAXN];
ll in_degree[MAXN];

int solve()
{
	priority_queue<pii> q;
	q.push({0, T});
	q.push({0, -T});
	
	for (int i = 1; i <= N; i++)
	{
		dist[i][1] = 0;
		dist[i][0] = INF;
	}
	
	dist[T][0] = dist[T][1] = 0;
	
	while (!q.empty())
	{
		ll u = q.top().se;
		int type = u < 0 ? 0:1;
		u = abs(u);
		ll du = -q.top().fi;
		q.pop();
		
		if (dist[u][type] != du)
		{
			continue;
		}
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			ll v = G[u][i];
			ll w = W[u][i];
			
			if (type == 0)
			{
				in_degree[v]--;
				tmp[v] = max(tmp[v], du + w);
				if (in_degree[v] == 0)
				{
					dist[v][1] = tmp[v];
					q.push({-dist[v][1], v});
				}
			}
			else
			{
				
				if (du + w < dist[v][0])
				{
					dist[v][0] = du + w;
					q.push({-dist[v][0], -v});
				}
			}
		}
	}
	
	return dist[S][1];
}

int main()
{
	scanf("%lld%lld%lld%lld", &N, &M, &S, &T);
	++S;
	++T;
	
	if (S == T)
	{
		return !printf("0\n");
	}
	
	
	ll u,v;
	ll w;
	for (int i = 0; i < M; i++)
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		++u, ++v;
		G[v].pb(u);
		W[v].pb(w);
		in_degree[u]++;
	}
	
	ll res = solve();
	
	if (res == 0)
	{
		printf("infinity\n");
	}
	else
	{
		printf("%lld\n", res);
	}
	
	
	
	return 0;
}
