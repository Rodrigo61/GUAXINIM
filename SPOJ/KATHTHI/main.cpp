#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 1005
#define INF 1e7
#define fi first
#define se second

int N, M;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

vector<pii> neighs;

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < M;
}

void get_neighs(pii u)
{
	neighs.clear();
	
	if (valid(u.fi - 1, u.se))
	{
		neighs.push_back({u.fi - 1, u.se});
	}
	if (valid(u.fi + 1, u.se))
	{
		neighs.push_back({u.fi + 1, u.se});
	}
	if (valid(u.fi, u.se - 1))
	{
		neighs.push_back({u.fi, u.se - 1});
	}
	if (valid(u.fi, u.se + 1))
	{
		neighs.push_back({u.fi, u.se + 1});
	}
	
}


int dijkstra()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = INF;
		}
	}
	dist[0][0] = 0;
	
	deque<pii> dq;
	dq.push_back({0, 0});
	
		
	while (!dq.empty())
	{
		pii u = dq.front();
		dq.pop_front();
		
		get_neighs(u);
		for (pii v : neighs)
		{
			if (grid[u.fi][u.se] == grid[v.fi][v.se])
			{
				if (dist[u.fi][u.se] < dist[v.fi][v.se])
				{
					dist[v.fi][v.se] = dist[u.fi][u.se];
					dq.push_front(v);
				}
			}
			else
			{
				if (dist[u.fi][u.se] + 1< dist[v.fi][v.se])
				{
					dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
					dq.push_back(v);
				}
			}
		}
	}

	
	return dist[N - 1][M - 1];
}

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d%d\n", &N, &M);
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%c", &grid[i][j]);
			}
			scanf("\n");
		}
		
		printf("%d\n", dijkstra());
		
	}
	
	
	return 0;
}
