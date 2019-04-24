#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> piii;

#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 212345
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second.first
#define thr second.second
#define INF 1123456789

int N, M, S, L;
vector<int> G[MAXN], W[MAXN];
int dist[MAXN];

void dijkstra()
{
	fill(dist, dist + N + 1, INF);
	dist[S] = 0;
	priority_queue<pii> q;
	q.push({0, S});
	
	while (!q.empty())
	{
		int u = q.top().second;
		int du = -q.top().first;
		q.pop();
		
		if (dist[u] < du)
		{
			continue;
		}
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			int v = G[u][i];
			int w = W[u][i];
			
			if (du + w < dist[v])
			{
				dist[v] = du + w;
				q.push({-dist[v], v});
			}
		}
	}
	
}

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		G[u].pb(v);
		G[v].pb(u);
		W[u].pb(w);
		W[v].pb(w);
	}
	
	scanf("%d", &L);
	
	dijkstra();
	
	set<piii> new_edges;
	
	int original_N = N;
	for (int u = 1; u <= original_N; u++)
	{
		if (dist[u] < L)
		{
			int to_complete_l = L - dist[u];
			
			for (int j = 0; j < (int)G[u].size(); j++)
			{
				int v = G[u][j];
				int w = W[u][j];
				
				if (v > original_N) // nao considera pontos novos
				{
					break;
				}
				
				if (w > to_complete_l)
				{
					int pos = to_complete_l;
					int inv_pos = w - to_complete_l;
					
					if (new_edges.find({v, {u, inv_pos}}) == new_edges.end())
					{
						new_edges.insert({u, {v, pos}});
						++N;
						G[u].pb(N);
						G[N].pb(u);
						G[v].pb(N);
						G[N].pb(v);
						W[u].pb(pos);
						W[N].pb(pos);
						W[v].pb(inv_pos);
						W[N].pb(inv_pos);
					}
				}
			}
		}
	}
	
	dijkstra();
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == L)
		{
			db(i);
			++total;
		}
	}
	
	printf("%d\n", total);
	return 0;
}
