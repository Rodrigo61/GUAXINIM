#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
#define MAXN 112345
#define LGN 40
#define MBITS 32
 
vi adj[MAXN];
int N;
ll ans[LGN];
ll on[MAXN][LGN];
ll off[MAXN][LGN];
ll vals[MAXN];
ll ans_test[LGN];


void dfs(int u, int p)
{
	
	vector<ll> cnt_on(MBITS);
	vector<ll> cnt_off(MBITS);
	for (int v : adj[u])
		if (v != p)
		{
			dfs(v, u);
			for (int i = 0; i < MBITS; i++)
			{
				cnt_on[i] += on[v][i];
				cnt_off[i] += off[v][i];
			}
		}
	
	db("------------------");
	db(u);
	bitset<MBITS> bs(vals[u]);
	for (int i = 0; i < MBITS; i++)
	{
		db(i);
		if (bs[i])
			on[u][i] = 1;
		else
			off[u][i] = 1;
			
		for (int v : adj[u])
		{
			if (v != p)
			{
				cnt_on[i] -= on[v][i];
				cnt_off[i] -= off[v][i];
				if (bs[i])
				{
					ans[i] += cnt_on[i] * on[v][i];
					ans[i] += cnt_off[i] * off[v][i];
					on[u][i] += off[v][i];
					off[u][i] += on[v][i];
				}
				else
				{
					off[u][i] += off[v][i];
					ans[i] += cnt_off[i] * on[v][i];
					ans[i] += cnt_on[i] * off[v][i];
					on[u][i] += on[v][i];
				}
			}
		}
		db(on[u][i]);	
		db(off[u][i]);	
		ans[i] += on[u][i];
	}
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
	
	ll res = 0;
	ll pot2 = 1;
	for (int i = 0; i < MBITS; i++)
	{
		//~ db(ans[i]);
		res += ans[i]*pot2;
		pot2 *= 2;
	}
	
	printf("%lld\n", res);
}
