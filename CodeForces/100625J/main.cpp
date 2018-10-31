#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;

#define MAXN 105
#define INF 100000000
#define fi first
#define se second

typedef pair<int, int> pii;

int N, M;
char g[MAXN][MAXN];
int dist[MAXN][MAXN];
int dist_p1[MAXN][MAXN];
int dist_p2[MAXN][MAXN];
pii p[MAXN][MAXN];

vector<pii> people;

void restart()
{
	people.clear();
}

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < M && g[i][j] != '*';
}

vector<pii> get_neighs(pii u)
{
	vector<pii>	res;
	
	if (valid(u.fi - 1, u.se))
	{
		res.push_back({u.fi - 1, u.se});
	}
	if (valid(u.fi + 1, u.se))
	{
		res.push_back({u.fi + 1, u.se});
	}
	if (valid(u.fi, u.se - 1))
	{
		res.push_back({u.fi, u.se - 1});
	}
	if (valid(u.fi, u.se + 1))
	{
		res.push_back({u.fi, u.se + 1});
	}
	
	return res;
}

bool is_border(pii u)
{
	return u.fi == 0 || u.fi == N-1 || u.se == 0 || u.se == M-1;
}


void dijkstra(pii s)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = INF;
		}
	}
	dist[s.fi][s.se] = 0;
	
	deque<pii> dq;
	dq.push_back(s);
	int w;
	
	while (!dq.empty())
	{
		pii u = dq.front();
		dq.pop_front();
		
		for (pii v : get_neighs(u))
		{
			if (g[v.fi][v.se] == '#')
			{
				w = 1;
				if (dist[u.fi][u.se] + w < dist[v.fi][v.se])
				{
					dist[v.fi][v.se] = dist[u.fi][u.se] + w;
					dq.push_back(v);
				}
			}
			else
			{
				w = 0;
				if (dist[u.fi][u.se] + w < dist[v.fi][v.se])
				{
					dist[v.fi][v.se] = dist[u.fi][u.se] + w;
					dq.push_front(v);
				}
			}
			
			
		}
	}
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
				scanf("%c", &g[i][j]);
				
				if (g[i][j] == '$')
				{
					people.push_back({i, j});
				}
				
			}
			scanf("\n");
		}
		
		dijkstra(people[0]);
		memcpy(dist_p1, dist, sizeof(dist));
		dijkstra(people[1]);
		memcpy(dist_p2, dist, sizeof(dist));
		
		int mini = INF;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (is_border({i, j}) && g[i][j] != '*')
				{
					dijkstra({i, j});
					
					int extra = g[i][j] == '#' ? 1:0;
					
					for (int ii = 0; ii < N; ii++)
					{
						for (int jj = 0; jj < M; jj++)
						{		
							int extra2 = g[ii][jj] == '#' ? -2:0;
							mini = min(mini, dist[ii][jj] + extra + dist_p1[ii][jj] + dist_p2[ii][jj] + extra2);
						}
					}
				}
			}
		}
		
		printf("%d\n", mini);
		
		restart();
	}
	
	return 0;
}
