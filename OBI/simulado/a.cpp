#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 112345

int N, M;
vi adj[MAXN];
int vis[MAXN];

void dfs(int u)
{
	vis[u] = 1;
	for (auto v : adj[u])
		if (!vis[v])
			dfs(v);
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
	
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i])
		{
			++res;
			dfs(i);
		}
	}
	
	printf("%d\n", res - 1);
	
	
}
