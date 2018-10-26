#include<bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;

#define SS 208001
#define ST 208000
#define MAXN 1005
#define TOTAL 308002
#define INF 0x3f3f3f3f

struct aresta{
	int v, p, t;
};

struct edge {
	int v, rev, cap, f;
};

vector<edge> adj[TOTAL];
int dist[TOTAL], ptr[TOTAL];

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

int N, M;
int I, G, S;
int n_targets;
int is_target[MAXN];
int u, v;
int p, t;

vector<aresta> imp_graph[MAXN];

void restart()
{
	for (int i = 0; i < MAXN; i++)
	{
		is_target[i] = 0;
		imp_graph[i].clear();
	}
	
	for (int i = 0; i < TOTAL; i++)
	{
		adj[i].clear();
	}
	
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &N, &I, &G, &S);
		--I;
		scanf("%d", &n_targets);
		
		for (int i = 0; i < n_targets; i++)
		{
			scanf("%d", &u);
			--u;
			is_target[u] = 1;
		}
		
		db("d1");
		
		scanf("%d", &M);
		
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d%d", &u, &v, &p, &t);
			--u, --v;
			
			imp_graph[u].push_back(aresta{v, p, t});
		}
		db("d2");
		
		u = 0;
		for (int i = 0; i <= S; i++)
		{
			for (int j = 0; j < N; j++)
			{
				db(u);
				if (is_target[j])
				{
					add_edge(u, ST, INF);
				}
				
				for (aresta e : imp_graph[j])
				{
					if ((i + e.t) * N + e.v < TOTAL)
					{
						add_edge(u, (i + e.t) * N + e.v, e.p);
					}
				}
				
				if (u + N < TOTAL)
				{
					add_edge(u, u + N, INF);
				}
				
				++u;
			}
		}
		
		add_edge(SS, I, G);
		
		printf("%d\n", dinic(TOTAL, SS, ST));
		
		restart();
	}
	return 0;
}
