#include<bits/stdc++.h>
#define ll long long
#define INF 1001001001001001LL

using namespace std;

int N, M, X, T;
ll dist[2001][2001];
int custo[2001];
int tempo[2001];
vector<int> G[2001];

void dijkstra()
{
	int a, b, c, t, v;
	ll w;
	priority_queue< pair<ll, pair<int, int> > > pq;
	for(int i = 1; i <= N; i++)
		for(int j = 0; j <= X; j++)
			dist[i][j] = INF;
	if(tempo[1] > T)
		return;
	for(t = tempo[1], c = custo[1]; t <= X; t += tempo[1], c += custo[1])
	{
		dist[1][t] = c;
		pq.push({-dist[1][t], {1, t}});
	}
	while(!pq.empty())
	{
		w = -pq.top().first;
		a = (pq.top().second).first;
		b = (pq.top().second).second;
		pq.pop();
		if(w > dist[a][b])
			continue;
		for(int i = 0; i < (int)G[a].size(); i++)
		{
			v = G[a][i];
			t = b+t+tempo[v];
			if(dist[v][t] > dist[a][b] + custo[v])
			{
				dist[v][t] = dist[a][b] + custo[v];
				pq.push({-dist[v][t], {v, t}});
			}
		}
	}
}

int main()
{
	int u, v;
	scanf("%d", &X);
	scanf("%d %d %d", &N, &M, &T);
	while(M--)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &tempo[i], &custo[i]);
	dijkstra();
	if(dist[1][X] != INF)
		printf("%lld\n", dist[1][X]);
	else
		printf("It is a trap.\n");
	return 0;
}
