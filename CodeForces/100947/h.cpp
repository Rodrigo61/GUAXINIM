#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define piii pair<int, pii>

int N, M;


bool valid(int i, int j, vector<vector<char>> &grid)
{
	return i >= 0 && i < N && j >= 0 && j < M && grid[i][j] != '#';
}
 
vector<pii> get_adj(int i, int j, vector<vector<char>> &grid)
{
	vector<pii> res;
	if (valid(i - 1, j, grid))
	{
		res.pb({i - 1, j});
	}
	if (valid(i + 1, j, grid))
	{
		res.pb({i + 1, j});
	}
	if (valid(i, j - 1, grid))
	{
		res.pb({i, j - 1});
	}
	if (valid(i, j + 1, grid))
	{
		res.pb({i, j + 1});
	}
	return res;
}
 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d\n", &N, &M);
		vector<vector<char>> grid(N, vector<char>(M));
		int vis[N][M];
		memset(vis, 0, sizeof(vis));
		
		queue<piii> pq;
		pii end;
		pii beg;
		
		// BFS PARALELO
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%c", &grid[i][j]);
				if (grid[i][j] == 'S')
				{
					beg = {i, j};
				}
				if (grid[i][j] == '*')
				{
					pq.push({1, {i, j}});
				}
				if (grid[i][j] == 'X')
				{
					end = {i, j};
				}
			}
			scanf("\n");
		}
		pq.push({0, beg});
		
		bool poss = false;
		while (!pq.empty())
		{
			int type = pq.front().fi;
			int i = pq.front().se.fi;
			int j = pq.front().se.se;
			pq.pop();
			
			db(i);
			db(j);
			
			grid[i][j] = type + '0';
			if (type == 0 && grid[i][j] != '*' && make_pair(i, j) == end)
			{
				poss = true;
				break;
			}
			if (type == 1)
			{
				grid[i][j] = '*';
			}
			
			for (auto v : get_adj(i, j, grid))
			{
				db(v.fi);
				db(v.se);
				if (!vis[v.fi][v.se])
				{
					vis[v.fi][v.se] = 1;
					pq.push({type, v});
				}
			}
		}
		
		//~ for (int i = 0; i < N; i++)
		//~ {
			//~ for (int j = 0; j < M; j++)
			//~ {
				//~ printf("%c", grid[i][j]);
			//~ }
			//~ printf("\n");
			
		//~ }
		
		
		if (poss)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
		
	}
	
}
