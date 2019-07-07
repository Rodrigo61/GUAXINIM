#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl
#define pb push_back
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define MAXN 112345

int N, M;
vi adj[MAXN];
vi vis[MAXN];
vi dp[MAXN];

int solve(int curr, int last_idx)
{
	if (last_idx >= (int)adj[curr].size())
	{
		return 1;
	}
	
	if (vis[curr][last_idx])
	{
		return dp[curr][last_idx];
	}
	vis[curr][last_idx] = 1;
	
	int &res = dp[curr][last_idx];
	res = 1;
	
	int v = adj[curr][last_idx];
	int idx_curr = upper_bound(all(adj[v]), curr) - adj[v].begin();
	res = max(solve(v, idx_curr) + 1, solve(curr, last_idx + 1));
	
	return res;
	
}

int main()
{
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for (int i = 1; i <= N; i++)
	{
		vis[i].resize(adj[i].size() + 1, 0);
		dp[i].resize(adj[i].size() + 1, 0);
		sort(all(adj[i]));
	}
	
	for (int i = 1; i <= N; i++)
	{
		printf("%d ", solve(i, 0));
	}
	
}
