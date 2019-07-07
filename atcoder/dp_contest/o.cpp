#include <bits/stdc++.h>

using namespace std;

#define MAXN 21
#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9 + 7;
int N;
int vals[MAXN + 5][MAXN + 5];
int vis[MAXN][(1<<MAXN)-1];
ll dp[MAXN][(1<<MAXN)-1];

void add(ll &a, ll b)
{
	a += b;
	if (a >= MOD)
	{
		a -= MOD;
	}
}

ll solve(int m, int mask)
{
	if (m == N)
	{
		return 1;
	}
	
	if (vis[m][mask])
	{
		return dp[m][mask];
	}
	vis[m][mask] = 1;
	
	ll res = 0;

	for (int i = 0; i < N; i++)
	{
		if (vals[m][i] && ((mask & (1 << i)) == 0))
		{
			add(res, solve(m + 1, mask | (1 << i)));
		}
	}

	dp[m][mask] = res;
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &vals[i][j]);
		}
	}

	printf("%lld\n", solve(0, 0));
}
