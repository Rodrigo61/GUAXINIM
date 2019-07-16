#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 112

int N;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN];

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < N;
}

vii get_neighs(pii u)
{
	vii res;
	
	if (valid(u.fi - 1, u.se))
	{
		res.pb({u.fi - 1, u.se});
	}
	if (valid(u.fi + 1, u.se))
	{
		res.pb({u.fi + 1, u.se});
	}
	if (valid(u.fi, u.se - 1))
	{
		res.pb({u.fi, u.se - 1});
	}
	if (valid(u.fi, u.se + 1))
	{
		res.pb({u.fi, u.se + 1});
	}
	
	return res;
}

int dijkstra()
{
	set<pair<int, pii>> pq;
	pq.insert({0, {0, 0}});
	dist[0][0] = 0;
	
	while (!pq.empty())
	{
		pii u = pq.begin()->se;
		int du = pq.begin()->fi;
		pq.erase(pq.begin());
		
		if (du > dist[u.fi][u.se])
			continue;
			
		for (auto v : get_neighs(u))
		{
			if (du + grid[v.fi][v.se] < dist[v.fi][v.se])
			{
				dist[v.fi][v.se] = du + grid[v.fi][v.se];
				pq.insert({dist[v.fi][v.se], v});
			}
		}
	}
	
	return dist[N - 1][N - 1];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);
			dist[i][j] = INF;
		}
	}

	printf("%d\n", dijkstra());
	
}
