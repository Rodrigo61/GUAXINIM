#include <bits/stdc++.h>

using namespace std;
#define MAXN 20001
#define db(x) cerr << #x << " = " << x << endl;

int N, M;
int degree[MAXN];
set<int> adj[MAXN];
int erased[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	
	int u, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		degree[u]++;
		degree[v]++;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	
	int center = 0;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] >= 5)
		{
			center = i;
			break;
		}
	}	
	
	db(center);
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 1)
		{
			q.push(i);
		}
	}
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		int v = *adj[u].begin();
		
		adj[v].erase(adj[v].find(u));
		erased[u] = 1;
		db(u);
		
		if (adj[v].size() == 1)
		{
			q.push(v);
		}
	}
	
	for (auto i : adj[center])
	{
		q.push(i);
		db(i);
		adj[i].erase(adj[i].find(center));
	}
		
	erased[center] = 1;
	
	while (!q.empty())
	{
		int u = q.front();
		db(u);
		q.pop();
		int v = *adj[u].begin();
		
		if (adj[v].find(u) == adj[v].end())
		{
			db(u);
			db(v);
			db("nop");
			exit(1);
		}
		
		adj[v].erase(adj[v].find(u));
		erased[u] = 1;
		
		if (adj[v].size() == 1)
		{
			q.push(v);
		}
		db("-");
	}
	
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!erased[i])
		{
			total++;
		}
	}
	
	printf("%d\n", total);
	
}
