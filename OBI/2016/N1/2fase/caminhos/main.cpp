#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()

#define MAXN 112345

int dist_r[MAXN];
int dist_c[MAXN];
int cycle_node[MAXN];
int cycle_len;
int N;
int adj[MAXN];
int in_degree[MAXN];

int cycle_dist(int u, int v)
{
	if (dist_r[u] <= dist_r[v])
		return dist_r[v] - dist_r[u];
	return cycle_len + (dist_r[v] - dist_r[u]);
}

void dfs_periferico(int u, int d_dist, int &last_node, int &h_dist)
{
	if (in_degree[u] == 2)
	{
		last_node = u;
		h_dist = 0;
		return;
	}
	
	dist_r[u] = d_dist;
	dfs_periferico(adj[u], d_dist + 1, last_node, h_dist);
	cycle_node[u] = last_node;
	dist_c[u] = ++h_dist;
}

void dfs_ciclo(int rep, int u, int dist)
{
	dist_r[u] = dist;
	cycle_len = max(cycle_len, dist + 1);
	if (adj[u] != rep)
		dfs_ciclo(rep, adj[u], dist + 1);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int v;
		scanf("%d", &v);
		adj[i] = v;
		in_degree[v]++;
	}
	
	bool did_cycle_dfs = false;
	for (int i = 1; i <= N; i++)
	{
		if (in_degree[i] == 0)
		{
			int aux1, aux2;
			dfs_periferico(i, 0, aux1, aux2);
		}
		else if (!did_cycle_dfs && in_degree[i] == 2)
		{
			dfs_ciclo(i, i, 0);
			did_cycle_dfs = true;
		}
	}
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		
		if (cycle_node[u] != 0 && cycle_node[u] == cycle_node[v])
		{
			// caso 1: mesma periferia
			printf("%d\n", abs(dist_r[u] - dist_r[v]));
		}
		else if (cycle_node[u] == 0 && cycle_node[v] == 0)
		{
			// caso 2: dentro do ciclo
			printf("%d\n", min(cycle_dist(u, v), cycle_dist(v, u)));
		}
		else if (cycle_node[u] != 0 && cycle_node[v] != 0 && cycle_node[u] != cycle_node[v])
		{
			// caso 3: diferentes periferias

			// u fica parado
			int res = max(dist_c[u], dist_c[v] + cycle_dist(cycle_node[v], cycle_node[u]));
			
			// v fica parado
			res = min(res, max(dist_c[v], dist_c[u] + cycle_dist(cycle_node[u], cycle_node[v])));
						  
			printf("%d\n", res);
		}
		else
		{
			// caso 4: u na periferia, v no ciclo
			if (cycle_node[v] != 0)
				swap(u, v);
				
			// u fica parado
			int res = max(dist_c[u], cycle_dist(v, cycle_node[u]));
			
			// v fica parado
			res = min(res, dist_c[u] + cycle_dist(cycle_node[u], v));
			
			printf("%d\n", res);
		}
	}
	
	
}
