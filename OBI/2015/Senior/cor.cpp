#include <bits/stdc++.h>

using namespace std;
#define MAXN 1123
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;

int N;
int grid[MAXN][MAXN];

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < N;
}

vector<pii> get_neighs(pii p)
{
	vector<pii> res;
	
	if (valid(p.fi - 1, p.se))
	{
		res.pb({p.fi - 1, p.se});
	}
	if (valid(p.fi + 1, p.se))
	{
		res.pb({p.fi + 1, p.se});
	}
	if (valid(p.fi, p.se - 1))
	{
		res.pb({p.fi, p.se - 1});
	}
	if (valid(p.fi, p.se + 1))
	{
		res.pb({p.fi, p.se + 1});
	}
	return res;
}

int main()
{
	scanf("%d\n", &N);
	queue<pii> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			scanf("%c", &c);
			
			grid[i][j] = -1;
			
			if (c != '*')
			{
				grid[i][j] = 0;
				q.push({i, j});
			}
		}
		scanf("\n");
	}
	
	while (!q.empty())
	{
		pii p = q.front();
		q.pop();
		
		for (auto n : get_neighs(p))
		{
			if (grid[n.fi][n.se] == -1)
			{
				db(grid[n.fi][n.se]);
				grid[n.fi][n.se] = min(grid[p.fi][p.se] + 1, 9);
				db(grid[n.fi][n.se]);
				q.push(n);
			}
		}
		
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
	
}
