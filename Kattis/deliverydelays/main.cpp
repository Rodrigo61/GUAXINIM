#include <bits/stdc++.h>
 
using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;  
#define ll long long
#define MAXN 1005
#define MAXK 1005
#define INF 1e18
 
int N, M;
int K;
vector<int> G[MAXN];
vector<ll> W[MAXN];
 
ll S[MAXK], U[MAXK], T[MAXK];
ll dist[MAXN][MAXN];
ll path[MAXN][MAXN];
ll d[MAXN];
ll dp2[MAXN][MAXN];
ll dp[MAXN];
 
void dijkstra(int s)
{
	for (int i = 1; i <= N; i++)
	{
		d[i] = INF;
	}
	d[s] = 0;
 
	priority_queue<pair<ll, int>> pq;
	pq.push({0, s});
 
	while (!pq.empty())
	{
		int u = pq.top().second;
		ll w = -pq.top().first;
		pq.pop();
		
		if (w > d[u])
		{
			continue;
		}
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			int v = G[u][i];
			w = W[u][i];
			
			if (d[u] + w < d[v])
			{
				d[v] = d[u] + w;
				pq.push({-d[v], v});
			}
		}
	}
}
 
void calc_dist()
{
	for (int i = 1; i <= N; i++)
	{
		dijkstra(i);
 
		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = d[j];
		}
	}
}
 
/* DP2[u][v] é a diferença máxima que um vertice do caminho u~v vai ter em relacao a sua distancia
 * acumulada e seu tempo S. Isso diz que para esse caminho, mesmo que comecemos no seu inicio otimo
 * que seria T[u], teremos pelo menos um vértice esperando ao menos DP2[u][v]*/ 
 
void calc_dp2_and_path()
{
	
	for (int i = 1; i <= K; i++)
	{
		ll c_d = 0;
		ll maxi = -INF;
		path[i][i] = 0;
		int last = 1; // começa na pizzaria
		int v;
		
		for (int j = i; j <= K; j++)
		{
			v = U[j];
			c_d += dist[last][v];
			path[i][j] = c_d;
			maxi = max(maxi - T[j - 1] + T[j], c_d + T[j] - S[j]);
			dp2[i][j] = maxi;
			last = v;
		}
	}
}
 
bool can_delivery(int u, int v, ll start, ll M)
{
	if (dp2[u][v] > M)
	{
		return false;
	}
	
	if (start < T[v])
	{
		return true;
	}
	
	return M - dp2[u][v] >= start - T[v];
}
 
bool possible(ll M)
{
	dp[0] = 0;
 
	for (int i = 1; i <= K; i++)
	{
		dp[i] = INF;
 
		for (int k = 0; k < i; k++)
		{
			if (can_delivery(k + 1, i, dp[k], M))
			{
			
				dp[i] = min(dp[i], max(dp[k], T[i])+ path[k + 1][i] + dist[U[i]][1]);
			}
		}
		
	}

	return dp[K] != INF;
}
 
ll solve()
{
	ll hi = 1000000000000000;
	ll lo = 0;
	ll mid, best;
 
	while (lo <= hi)
	{
		mid = lo + (hi - lo)/2;
		
		if (possible(mid))
		{
			best = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
 
 
	return best;
}
 
int main()
{
	scanf("%d%d", &N, &M);
 
	int u, v, u2v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &u, &v, &u2v);
		
		G[u].push_back(v);
		W[u].push_back(u2v);
		G[v].push_back(u);
		W[v].push_back(u2v);
	}
 
	calc_dist();
	
	scanf("%d", &K);
	for (int i = 1; i <= K; i++)
	{
		scanf("%lld%lld%lld", &S[i], &U[i], &T[i]);
	}
	
	
	calc_dp2_and_path();
	
	printf("%lld\n", solve());
 
}
