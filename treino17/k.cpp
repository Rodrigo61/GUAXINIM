#include<bits/stdc++.h>
#define ll long long
#define INF 1001001001001001001LL
using namespace std;

int N, M;

vector<int> G[100001];
vector<ll> W[100001];

int special[100001];

ll dist[100001];
ll dist2[100001][2];

vector<int> policiais;

ll dijkstra(int source, int target)
{
	ll w;
	int u, v;
	priority_queue< pair<ll, int> > pq;
	for(int i = 1; i <= N; i++)
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
			printf("%lld %lld %lld\n", dist[v], dist[u]+w, min(dist2[v][0], dist2[v][1]));
			if((dist[v] > dist[u]+w) && (dist[u]+w < min(dist2[v][0], dist2[v][1])))
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

void dijkstra2(int target)
{
	ll w;
	int a, b, b2, v;
	priority_queue< pair<ll, pair<int, int> > > pq;
	for(int i = 1; i <= N; i++)
		dist2[i][0] = dist2[i][1] = INF;
	for(int i = 0; i < (int)policiais.size(); i++)
	{
		dist2[policiais[i]][0] = 0;
		pq.push({0, {policiais[i], 0}});
	}
	while(!pq.empty())
	{
		w = -pq.top().first;
		a = pq.top().second.first;
		b = pq.top().second.second;
		pq.pop();
		if(w > dist2[a][b])
			continue;
		for(int i = 0; i < (int)G[a].size(); i++)
		{
			v = G[a][i];
			w = W[a][i];
			b2 = b | special[v];
			if(dist2[v][b2] > dist2[a][b]+peso(w, b))
			{
				dist2[v][b2] = dist2[a][b]+peso(w, b);
				pq.push({-dist2[v][b2], {v, b2}});
			}
		}
	}
	for(int i = 1; i <= N; i++)
		printf("%d -> %lld\n", i, min(dist2[i][0], dist2[i][1]));
}

int main()
{
	int u, v, w, a, K, s, t;
	ll x; 
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
	dijkstra2(t);
	x = dijkstra(s, t);
	if(x != INF)
		printf("%lld\n", x/2);
	else
		printf("-1\n");
	return 0;
}
