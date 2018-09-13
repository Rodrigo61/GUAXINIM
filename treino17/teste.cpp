#include<bits/stdc++.h>
#define ll long long
#define INF 1001001001001001001LL
using namespace std;

int N, M;

vector<int> G[100001];
vector<ll> W[100001];

int special[100001];

vector<int> policiais;

ll dijkstra(int source, int target)
{
	ll dist[N+1];
	ll w;
	int u, v;
	priority_queue< pair<ll, int> > pq;
	for(int i = 0; i <= N; i++)
		dist[i] = INF;
	dist[source] = 0;
	pq.push({0, source});
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
				pq.push({-dist[v], v});
			}
		}
	}
	return dist[target];
}

ll peso(ll a, int b)
{
	if(b)
		return a/2;
	return a;
}

ll dijkstra2(int target)
{
	ll dist[N+1][2];
	ll w;
	int a, b, b2, v;
	priority_queue< pair<ll, pair<int, int> > > pq;
	for(int i = 0; i <= N; i++)
		dist[i][0] = dist[i][1] = INF;
	for(int i = 0; i < (int)policiais.size(); i++)
	{
		dist[policiais[i]][0] = 0;
		pq.push({0, {policiais[i], 0}});
	}
	while(!pq.empty())
	{
		w = -pq.top().first;
		a = pq.top().second.first;
		b = pq.top().second.second;
		pq.pop();
		if(w > dist[a][b])
			continue;
		for(int i = 0; i < (int)G[a].size(); i++)
		{
			v = G[a][i];
			w = W[a][i];
			b2 = b | special[v];
			if(dist[v][b2] > dist[a][b]+peso(w, b))
			{
				dist[v][b2] = dist[a][b]+peso(w, b);
				pq.push({-dist[v][b2], {v, b2}});
			}
		}
	}
	//for(int i = 0; i <= N; i++)
		//printf("%d -> %lld\n", i, min(dist[i][0], dist[i][1]));
	return min(dist[target][0], dist[target][1]);
}

int main()
{
	int u, v, w, a, K, s, t;
	ll x, y; 
	scanf("%d %d", &N, &M);
	while(M--)
	{
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(2*w);
		W[v].push_back(2*w);
	}
	scanf("%d", &K);
	while(K--)
	{
		scanf("%d", &a);
		policiais.push_back(a);
	}
	scanf("%d", &K);
	while(K--)
	{
		scanf("%d", &a);
		special[a] = 1;
	}
	scanf("%d %d", &s, &t);
	x = dijkstra(s, t);
	y = dijkstra2(t);
	//printf("%lld %lld\n", x, y);
	if(x < y)
		printf("%lld\n", x/2);
	else
		printf("-1\n");
	return 0;
}
