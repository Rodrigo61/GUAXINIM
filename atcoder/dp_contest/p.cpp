#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345
#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define B 1
#define W 0

set<int> G[MAXN];
int N;
int vis[MAXN][2];
ll dp[MAXN][2];
const int MOD = 1e9 + 7;

void dfs(int u, int p)
{
	G[u].erase(p);
	for (auto v : G[u])
		dfs(v, u);
}

void mul(ll &a, ll b)
{
	a = (a * b) % MOD;
}

void add(ll &a, ll b)
{
	a = (a + b) % MOD;
}

ll solve(int node, int last_color)
{
	
	if (G[node].empty())
	{
		return last_color == W ? 2:1;
	}

	ll res = 0;
	
	if (vis[node][last_color])
	{
		return dp[node][last_color];
	}
	vis[node][last_color] = 1;
	
	// PAINT BLACK	
	ll pos = 1;
	if (last_color == W)
	{
		for (auto v : G[node])
		{
			ll sub = solve(v, B);
			mul(pos, sub);
		}
		add(res, pos);
	}
	
	// PAINT WHITE
	pos = 1;
	for (auto v : G[node])
	{
		ll sub = solve(v, W);
		mul(pos, sub);
	}
	add(res, pos);
	
	dp[node][last_color] = res;
	return res;
}

int main()
{
	scanf("%d", &N);
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].insert(v);
		G[v].insert(u);
	}
	
	dfs(1, 1);
	
	printf("%lld\n", solve(1, W));
}
