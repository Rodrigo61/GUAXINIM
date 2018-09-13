#include<bits/stdc++.h>
#define MAXN 100001
#define INF 1001001001

using namespace std;

vector<int> G[MAXN], W[MAXN];

set<int> arestas[MAXN];

int pai[MAXN];
int dist2[MAXN][2];

int N, M;

void dijkstra(int s, int t)
{
	int u, v, w;
	vector<int> dist(N+1);
	priority_queue< pair<int, int> > pq;
	for(int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[s] = 0;
	pq.push({0, s});
	while(!pq.empty())
	{
		w = -pq.top().first;
		u = pq.top().second;
		pq.pop();
		if(w > dist[u])
			continue;
		for(int i = 0; i < (int)G[u].size(); i++)
		{
			v = G[u][i];
			w = W[u][i];
			if(dist[v] > dist[u]+w)
			{
				dist[v] = dist[u]+w;
				pai[v] = u;
				pq.push({-dist[v], v});
			}
		}
	}
	/*v = t;
	while(v != s)
	{
		arestas[v].insert(pai[v]);
		arestas[pai[v]].insert(v);
		v = pai[v];
	}*/
}

int dijkstra2(int s, int t)
{
	int u, v, w, b, ans = -1;
	priority_queue< pair<int, pair<int, int> > > pq;
	for(int i = 1; i <= N; i++)
		dist2[i][0] = dist2[i][1] = INF;
	dist2[s][0] = 0;
	pq.push({0, {s, 0}});
	while(!pq.empty())
	{
		w = -pq.top().first;
		u = pq.top().second.first;
		b = pq.top().second.second;
		pq.pop();
		if(w > dist2[u][b])
			continue;
		for(int i = 0; i < (int)G[u].size(); i++)
		{
			v = G[u][i];
			w = W[u][i];
			if(b)
			{
				if(v == t)
				{
					//if(dist2[v][b] > w + dist2[u][b])
						ans = max(ans, dist2[u][b]+w);
				}
				else
				{
					if(dist2[v][b] > w + dist2[u][b])
					{
						dist2[v][b] = w+dist2[u][b];
						pq.push({-dist2[v][b], {v, b}});
					}
				}
			}
			else
			{
				if((v == pai[u]) || (u == pai[v]))
				{
					if(dist2[v][b] > w + dist2[u][b])
					{
						dist2[v][b] = w+dist2[u][b];
						pq.push({-dist2[v][b], {v, b}});
					}
				}
				else
				{
					if(dist2[v][1] > w + dist2[u][b])
					{
						dist2[v][1] = w+dist2[u][b];
						pq.push({-dist2[v][1], {v, 1}});
					}
				}
			}
		}
	}
	return ans;
	/*v = t;
	while(v != s)
	{
		arestas[v].insert(pai[v]);
		arestas[pai[v]].insert(v);
		v = pai[v];
	}*/
}

int main()
{
	int s, t, u, v, w, ans;
	scanf("%d %d %d %d", &N, &M, &s, &t);
	while(M--)
	{
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	dijkstra(s, t);
	ans = dijkstra2(s, t);
	printf("%d\n", ans);
	return 0;
}
