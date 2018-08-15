#include<bits/stdc++.h>
#define MAXN 100000
#define INF 1001001001
using namespace std;

int N, M;
vector<int> G[MAXN+1], W[MAXN+1];

int dist[MAXN+1][3];

void dijkstra()
{
	int u, v, r, r2, w;
	priority_queue< pair<int, pair<int, int> > > pq;
	for(int i = 1; i <= N; i++)
		dist[i][0] = dist[i][1] = dist[i][2] = INF;
	dist[1][0] = 0;
	pq.push({0, {1, 0}});
	while(!pq.empty())
	{
		w = -pq.top().first;
		u = pq.top().second.first;
		r = pq.top().second.second;
		pq.pop();
		if(w > dist[u][r] || u == N)
			continue;
		
		//printf("%d %d %d\n", w, u, r);
		r2 = r+1;
		if(r2 >= 3)
			r2 -= 3;
		for(int i = 0; i < (int)G[u].size(); i++)
		{
			v = G[u][i];
			w = W[u][i];
			if(dist[v][r2] > dist[u][r] + w)
			{
				dist[v][r2] = dist[u][r]+w;
				pq.push({-dist[v][r2], {v, r2}});
			}
		}
	}
}

vector< pair<int, int> > vet;

int main()
{
	int u, v, w;
	scanf("%d %d", &N, &M);
	while(M--)
	{
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	dijkstra();
	for(int i = 0; i < 3; i++)
	{
		vet.push_back(make_pair(dist[N][i], i));
		//printf("%d\n", dist[N][i]);
	}
	sort(vet.begin(), vet.end());
	for(int i = 0; i < 3; i++)
	{
		if(vet[i].second == 0)
			printf("me\n");
		else if(vet[i].second == 1)
			printf("Gon\n");
		else
			printf("Killua\n");
	}
	return 0;
}
