#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define vii vector<pii>

#define MAXN 512345

ll vals[MAXN];
ll dp[MAXN];
ll sz[MAXN];
int children[MAXN];
int N;
vector<int> adj[MAXN];

bool comp(int a, int b)
{
	return 2*sz[a] - dp[a] < 2*sz[b] - dp[b];
}

void dfs(int u, int pu)
{
	dp[u] = vals[u];
	for (int v : adj[u])
	{
		if (v != pu)
		{
			dfs(v, u);
			sz[u] += sz[v] + 1;
		}
	}

	int idx = 0;
	for (int v : adj[u])
	{
		if (v != pu)
		{
			children[idx] = v;
			++idx;
		}
	}
	
	sort(children, children + idx, comp);
	
	ll acu_path = 0;
	for (int i = 0; i < idx; i++)
	{
		db(children[i]);
		dp[u] = max(dp[u], 1 + dp[children[i]] + acu_path);
		acu_path += 2 * sz[children[i]] + 2;
	}
	if (u == 1)
	{
		dp[u] = max(dp[u], vals[u] + acu_path);
	}
	db(dp[u]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1, 0);
	
	printf("%lld\n", dp[1]);
}
