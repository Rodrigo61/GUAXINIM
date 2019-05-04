#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x <<  " = " << x << endl;
#define MAXN 112
#define pb push_back
#define se second
#define fi first
#define INF 1123456789

int N, M;
vector<int> G[MAXN];
vector<int> W[MAXN];
int dist[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	
	int u, v, c;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		G[u].pb(v);
		G[v].pb(u);
		W[u].pb(c);
		W[v].pb(c);
	}
	
	priority_queue<pair<int, int>> q;
	q.push({0, 1});
	fill(dist, dist + N + 1, INF);
	dist[1] = 0;
	
	while (!q.empty())
	{
		int u = q.top().se;
		int d = -q.top().fi;
		q.pop();
		
		if (dist[u] < d)
		{
			continue;
		}
		
		if (u == N)
		{
			break;
		}
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			if (dist[u] + W[u][i] < dist[G[u][i]])
			{
				dist[G[u][i]] = dist[u] + W[u][i];
				q.push({-dist[G[u][i]], G[u][i]});
			}
		}
	}
	
	printf("%d\n", dist[N]);
	
	return 0;
}
