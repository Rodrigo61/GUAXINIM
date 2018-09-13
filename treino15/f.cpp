#include<bits/stdc++.h>

using namespace std;

#define MAXN 1509

vector<int> adj[MAXN];
vector<bool> used(MAXN), visit(MAXN);
int match[MAXN], dist[MAXN];


void bfs(int n1, int n2)
{
	fill(dist, dist + n1, -1);
	queue<int> q;
	for (int u = 0; u < n1; u++)
	{
		if (!used[u])
		{
			q.push(u);
			dist[u] = 0;
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int j = 0; j < (int)adj[u].size(); j++)
		{
			int v = match[adj[u][j]];
			
			if (v >= 0 && dist[v] < 0)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			
		}
		
	}
}

bool dfs(int u)
{
	visit[u] = true;
	for (int j = 0; j < (int)adj[u].size(); ++j)
	{
		int v = match[adj[u][j]];
		if (v < 0 || (!visit[v] && dist[v] == dist[u] + 1 && dfs(v)))
		{
			match[adj[u][j]] = u;
			used[u] = true;
			return true;
		}
	}
	
	return false;
}

int hopcroft_karp(int n1, int n2)
{
	fill(match, match + n2, -1);
	fill(used.begin(), used.end(), false);
	int res = 0;
	for (;;)
	{
		bfs(n1, n2);
		fill(visit.begin(), visit.end(), false);
		int f = 0;
		for (int u = 0; u < n1; u++)
		{
			if (!used[u] && dfs(u))
			{
				f++;
			}
		}
		if (f == 0)
		{
			return res;
		}
		res += f;
	}
	
	return res;
}

int myrandom (int i) { return std::rand()%i;}

int main()
{
	std::srand ( unsigned ( std::time(0) ) );
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	
	int u, v;
	for (int i = 0; i < K; i++)
	{
		scanf("%d%d", &u, &v);
		--u, --v;
		
		adj[u].push_back(v);
	}
	
	int base_flow = hopcroft_karp(N, M);
	
	int max_flow = base_flow;
	
	vector<int> rands(N);
	for (int i = 0; i < N; i++)
	{
		rands[i] = i;
	}
	
	random_shuffle(rands.begin(), rands.end(), myrandom);
	
	for (int i = 0; i < min(N, 120); i++)
	{
		adj[N].clear();
		adj[N + 1].clear();
		
		for (int v : adj[rands[i]])
		{
			adj[N].push_back(v);
			adj[N+1].push_back(v);
		}
		
		int curr_flow = hopcroft_karp(N + 2, M);
		
		max_flow = max(max_flow, curr_flow);
		
		if (max_flow == base_flow + 2)
			break;
	}

	
	printf("%d\n", max_flow);
	
	return 0;
}
