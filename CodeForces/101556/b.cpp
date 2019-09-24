#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
 
#define MAXN 112
 
int N, M;
pii pts[4];
int vis[MAXN][MAXN];
pii p[MAXN][MAXN];
pii NULL_PAIR = {-1, -1};
 
vector<pii> get_adjs(pii u)
{
	vector<pii> res;
	
	if (u.fi - 1 >= 0 && !vis[u.fi - 1][u.se])
	{
		res.pb({u.fi - 1, u.se});
	}
	if (u.se - 1 >= 0 && !vis[u.fi][u.se - 1])
	{
		res.pb({u.fi, u.se - 1});
	}
	if (u.fi + 1 <= N && !vis[u.fi + 1][u.se])
	{
		res.pb({u.fi + 1, u.se});
	}
	if (u.se + 1 <= M && !vis[u.fi][u.se + 1])
	{
		res.pb({u.fi, u.se + 1});
	}

	return res;
}
 
void BFS(pii s, pii t)
{
	queue<pii> q;
	q.push(s);
	vis[s.fi][s.se] = 1;
	
	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		
		if (u == t)
			break;
			
		for (pii v : get_adjs(u))
		{
			p[v.fi][v.se] = u;
			vis[v.fi][v.se] = 1;
			q.push(v);
		}
 
	}
}
 
void clear_p()
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			p[i][j] = {-1, -1};
		}
	}
	
}
 
int solve(pii A1, pii A2, pii B1, pii B2)
{
	memset(vis, 0, sizeof(vis));
	vis[B1.fi][B1.se] = 1;
	vis[B2.fi][B2.se] = 1;
	
	clear_p();
	BFS(A1, A2);
	
	if (!vis[A2.fi][A2.se])
		return INF;
	
	memset(vis, 0, sizeof(vis));
	pii u = A2;
	int count = 0;
	while (u != NULL_PAIR)
	{
		vis[u.fi][u.se] = 1;
		u = p[u.fi][u.se];
		++count;
	}
	
	clear_p();
	BFS(B1, B2);
	
	if (!vis[B2.fi][B2.se])
		return INF;
	
	u = B2;
	while (u != NULL_PAIR)
	{
		u = p[u.fi][u.se];
		++count;
	}
	
	return count - 2;
}
 
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d%d", &pts[i].fi, &pts[i].se);
	}
	
	int res = min(solve(pts[0], pts[1], pts[2], pts[3]), 
				  solve(pts[3], pts[2], pts[1], pts[0]));
				  
	if (res == INF)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		printf("%d\n", res);
	}
	
	
}
