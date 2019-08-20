#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 5000

int N;
pii votes[MAXN];
int used[MAXN];
int target;

struct edge {
	int v, rev, cap, f;
};

vector<edge> adj[MAXN];
int dist[MAXN], ptr[MAXN];

void add_edge(int u, int v, int cap)
{
	adj[u].push_back((edge){v, (int)adj[v].size(), cap, 0});
	adj[v].push_back((edge){u, (int)adj[u].size() - 1, 0, 0});
}
bool dinic_bfs(int nodes, int source, int sink) 
{
	fill(dist, dist + nodes, -1);
	dist[source] = 0;
	queue<int> q;
	q.push(source);
	while (!q.empty()) 
	{
		int u = q.front();
		q.pop();
		for (int j = 0; j < (int)adj[u].size(); j++) 
		{
			edge &e = adj[u][j];
			if (dist[e.v] < 0 && e.f < e.cap) 
			{
				dist[e.v] = dist[u] + 1;
				q.push(e.v);
			}
		}
	}
	return dist[sink] >= 0;
}

int dinic_dfs(int u, int f, int sink) 
{
	if (u == sink)
		return f;
	for (; ptr[u] < (int)adj[u].size(); ptr[u]++) 
	{
		edge &e = adj[u][ptr[u]];
		if (dist[e.v] == dist[u] + 1 && e.f < e.cap) 
		{
			int flow = dinic_dfs(e.v, min(f, e.cap - e.f), sink);
			if (flow > 0) 
			{
				e.f += flow;
				adj[e.v][e.rev].f -= flow;
				return flow;
			}
		}
	}
	return 0;
}

int dinic(int nodes, int source, int sink) 
{
	int flow, max_flow = 0;
	while (dinic_bfs(nodes, source, sink)) 
	{
		fill(ptr, ptr + nodes, 0);
		while ((flow = dinic_dfs(source, INF, sink)) != 0) 
			max_flow += flow;
	}
	return max_flow;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d", &votes[i].fi, &votes[i].se);
	}
	
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= 2*N+2; k++)
		{	
			adj[k].clear();
		}
		memset(used, 0, sizeof(used));
		target = 0;
		
		for (int k = 1; k <= N; k++)
		{
			if (k == i)
			{
				used[k] = 1;
			}
			else if (votes[k].fi == i || votes[k].se == i)
			{
				used[k] = 1;
				++target;
			}
		}
		
		if (target < 2)
		{
			++res;
			continue;
		}
		
		int cnt_votes = 0;
		for (int k = 1; k <= N; k++)
		{
			if (!used[k])
			{
				cnt_votes++;
				add_edge(0, k, 1);
				add_edge(k, votes[k].fi + N, 1);
				add_edge(k, votes[k].se + N, 1);
			}
							
			if (votes[i].fi == k || votes[i].se == k)
				add_edge(k + N, 2 * N + 1, target - 2);
			else
				add_edge(k + N, 2 * N + 1, target - 1);
		}
		
		if (dinic(2 * N + 2, 0, 2 * N + 1) < cnt_votes)
			++res;
		
	}
	
	printf("%d", res);
	
}
