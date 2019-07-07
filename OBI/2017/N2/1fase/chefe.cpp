#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define db(x) //cerr << #x <<  " = " << x << endl;
#define MAXN 505
#define fi first
#define se second
#define INF 1123456789
#define pb push_back

int N, M, I;

set<int> adj[MAXN];
int age[MAXN], id[MAXN], vis[MAXN];

int dfs(int u)
{
	vis[u] = 1;
	int mini = INF;
	for (int v : adj[u])
	{
		mini = min(mini, age[v]);
		if (!vis[v])
		{
			mini = min(mini, dfs(v));
		}
	}
	return mini;
}

int dfs2(int u, int target)
{
	vis[u] = 1;
	if (id[u] == target)
	{
		return u;
	}
	int res = 0;
	for (int v : adj[u])
	{
		if (!vis[v])
		{
			res = max(res, dfs2(v, target));
		}
	}
	return res;
}

int find_node(int target)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i])
		{
			int pos = dfs2(i, target);
			if (pos) return pos;	
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d%d", &N, &M, &I);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &age[i]);
		id[i] = i;
	}
	
	int u, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		adj[v].insert(u);
	}
	
	db("e1");
	char cmd;
	int a, b;
	for (int i = 0; i < I; i++)
	{
		scanf(" %c", &cmd);
		
		if (cmd == 'T')
		{
			
			scanf("%d%d", &a, &b);
			
			int ia = find_node(a);
			int ib = find_node(b);
			
			swap(age[ia], age[ib]);
			swap(id[ia], id[ib]);
			
		}
		else
		{
			scanf("%d", &a);
			
			int ia = find_node(a);
			memset(vis, 0, sizeof(vis));
			int rec = dfs(ia);
			
			if (rec == INF)
			{
				printf("*\n");
			}
			else
			{
				printf("%d\n", rec);
			}
		}
	}
	
	
	
	return 0;
}



