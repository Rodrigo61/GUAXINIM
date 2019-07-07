#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl
#define MAXN 2123
#define vi vector<int>
#define pb push_back
#define INF 0x3f3f3f3f

int N, M;
vi adj[MAXN];
vi dist;

void bfs(int u, int limit)
{
	dist[u] = 0;
	queue<int> q;
	q.push(u);
	
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		
		if (dist[u] == limit) continue;
		
		for (int v : adj[u])
		{
			if (dist[v] == INF)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	
}

bool connected(int u, int limit)
{
	dist.clear();
	dist.resize(N + 1, INF);
	bfs(u, limit);
	return count(dist.begin(), dist.end(), INF) == 1;
}

bool possible(int M)
{
	for (int i = 1; i <= N; i++)
	{
		if (!connected(i, M))
		{
			return false;
		}
	}
	
	return true;
}

int main() 
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	if (!connected(1, INF))
	{
		return !printf("=[\n");
	}
	
	int up = N;
	int lo = 1;
	int best;
	
	while (lo <= up)
	{
		int mid = lo + (up - lo) / 2;
		db(mid);
		if (possible(mid))
		{
			best = mid;
			db(best);
			up = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	
	printf("=] %d\n", best);
}
