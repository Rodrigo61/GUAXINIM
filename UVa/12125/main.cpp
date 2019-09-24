#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) x.begin(), x.end()

namespace dinic
{
struct edge
{
	int dest, cap, re, flow;
};

const int inf = 0x3f3f3f3f;
const int MAXV = 312345;

int n, s, t, d[MAXV], q[MAXV], next[MAXV];
vector<vector<edge>> graph;

void init(int _n, int _s, int _t)
{
	n = _n, s = _s, t = _t;
	graph = vector<vector<edge>>(n + 1);
}

void put_edge(int u, int v, int cap)
{
	graph[u].push_back({v, cap, (int)graph[v].size(), 0});
	graph[v].push_back({u, 0, (int)graph[u].size() - 1, 0});
}

bool bfs()
{
	int qb = 0, qe = 0;
	q[qe++] = s;
	memset(d, 0x3f, sizeof(int) * (n + 1));
	d[s] = 0;
	while (qb < qe)
	{
		int a = q[qb++];
		if (a == t)
			return true;
		for (int i = 0; i < (int)graph[a].size(); i++)
		{
			edge &e = graph[a][i];
			if (e.cap - e.flow > 0 && d[e.dest] == inf)
				d[q[qe++] = e.dest] = d[a] + 1;
		}
	}

	return false;
}

int dfs(int a, int flow)
{
	if (a == t)
		return flow;
	for (int &i = next[a]; i < (int)graph[a].size(); i++)
	{
		edge &e = graph[a][i];
		if (d[a] + 1 == d[e.dest] && e.cap - e.flow > 0)
		{
			int x = dfs(e.dest, min(flow, e.cap - e.flow));
			if (x == 0)
				continue;
			e.flow += x;
			graph[e.dest][e.re].flow -= x;
			return x;
		}
	}

	d[a] = inf;
	return 0;
}

long long max_flow()
{
	long long total_flow = 0;
	while (bfs())
	{
		memset(next, 0, sizeof(int) * (n + 1));
		while (int path_flow = dfs(s, inf))
			total_flow += path_flow;
	}

	return total_flow;
}
}

double dist(pii a, pii b)
{
	return sqrt((a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se - b.se));
}

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		int N;
		double D;
		scanf("%d%lf", &N, &D);
		vector<pii> coords(N);
		vi in_flow(N);
		vi max_flow(N);
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d%d%d", &coords[i].fi, &coords[i].se, &in_flow[i], &max_flow[i]); 
			total += in_flow[i];
		}
		
		vi res;
		for (int k = 0; k < N; ++k)
		{
			int ssource = 2 * N;
			int sink = k + N;
			dinic::init(2 * N + 1, ssource, sink);
			
			for (int i = 0; i < N; i++)
			{
				dinic::put_edge(ssource, i + N, in_flow[i]);
				if (i == k)
					dinic::put_edge(i + N, i, INF);
				else
					dinic::put_edge(i + N, i, max_flow[i]);
				for (int j = 0; j < N; j++)
				{
					if (i != j && dist(coords[i], coords[j]) <= D)
					{
						dinic::put_edge(i, j + N, INF);
					}
				}
			}
			
			int aux = dinic::max_flow();
			if (aux == total)
				res.pb(k);
		}
		
		if (res.empty())
		{
			printf("-1\n");
		}
		else
		{
			for (int i = 0; i < res.size(); i++)
			{
				printf("%d", res[i]);
				if (i != res.size() - 1)
					printf(" ");
			}
			printf("\n");
		}			
		
	}
}
