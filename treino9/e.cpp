#include<bits/stdc++.h>

using namespace std;
#define db(x) //cerr << #x << " == " << x << endl;	
#define pb push_back

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef vector<int> vi;
typedef vector<pii> vii;

#define MAXN 10001
#define INF 1000000000000000000LL

int N, M, X;

vector<int> G[MAXN], W[MAXN];
ll dist[MAXN];
ll max_dist;


void dijkstra(int s)
{
	int u, v;
	ll w;
	priority_queue<plli> fila;
	
	for (int i = 0; i < N; i++)
	{
		dist[i] = INF;
	}
	dist[s] = 0;
	fila.push({0, s});
	
	while (!fila.empty())
	{
		u = fila.top().second;
		w = -fila.top().first;
		
		db(u);
		db(w);
		
		fila.pop();
		
		if (w > dist[u])
		{
			continue;
		}
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			v = G[u][i];
			w = W[u][i];
			db(v);
			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				fila.push({-dist[v], v});
			}
			
		}
		
	}
	
}

bool possible(int M) {
	
	int u, v;
	ll w;
	priority_queue<plli> fila;
	
	for (int i = 0; i < N; i++)
	{
		dist[i] = INF;
	}
	dist[0] = 0;
	fila.push({0, 0});
	
	while (!fila.empty())
	{
		u = fila.top().second;
		w = -fila.top().first;
		
		fila.pop();
		
		if (w > dist[u])
		{
			continue;
		}
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			v = G[u][i];
			w = W[u][i];
			
			if (w <= M && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				fila.push({-dist[v], v});
			}
			
		}
	}
	
	return dist[N - 1] <= max_dist;
	
}

int solve()
{
	int upper = 1000000000;
	int lower = 1;
	int best;
	
	while (lower <= upper)
	{
		int mid = lower + (upper - lower) / 2;
		
		if (possible(mid))
		{
			best = mid;
			upper = mid - 1;
		}
		else
		{
			lower = mid + 1;
		}
		
	}
	
	return best;
}

int main()
{
	scanf("%d%d%d", &N, &M, &X);
	
	for (int i = 0; i < M; i++)
	{
		int u, v, u2v;
		scanf("%d%d%d", &u, &v, &u2v);
		
		--u, --v;
		G[u].pb(v);
		W[u].pb(u2v);
		
		G[v].pb(u);
		W[v].pb(u2v);
	}
	db("code");
	
	
	dijkstra(0);
	max_dist = (dist[N - 1] * (100LL + X))/100; // floor
	
	db(dist[N - 1]);
	db(max_dist);
	
	printf("%d\n", solve());
	
	
	return 0;
}
