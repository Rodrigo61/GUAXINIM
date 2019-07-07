#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl
#define vi vector<int>
#define pb push_back
#define INF 0x3f3f3f3f
#define ll long long

ll N, X, D;
ll vals[20];
int vis[20][(1 << 16)];
int dp[20][(1 << 16)];

int solve(int idx, int mask)
{
	if (idx == N)
	{
		ll acu = 0;
		ll maxi = 0;
		ll mini = INF;
		for (int i = 0; i < N; i++)
		{
			if (mask & (1 << i))
			{
				acu += vals[i];
				maxi = max(maxi, vals[i]);
				mini = min(mini, vals[i]);
			}
		}
		return mask != 0 && acu >= X && maxi - mini <= D;
	}
	
	if (vis[idx][mask])
	{
		return dp[idx][mask];
	}
	vis[idx][mask] = 1;
	
	return dp[idx][mask] = solve(idx + 1, mask) + solve(idx + 1, mask | (1 << idx));
}

int main()
{
	scanf("%lld%lld%lld", &N, &X, &D);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	printf("%d\n", solve(0, 0));
	
}
