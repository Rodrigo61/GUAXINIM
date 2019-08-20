#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 112345

int N;
vi adj[MAXN];
int res = INF;

int dfs(int u, int pu)
{
	int r = 1;
	for (auto v : adj[u])
	{
		if (v != pu)
		{
			int rec = dfs(v, u);
			int rest = N - rec;
			res = min(res, abs(rec - rest));
			r += rec;
		}
	}
	
	return r;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	dfs(1, 0);
	printf("%d\n", res);
	
}
