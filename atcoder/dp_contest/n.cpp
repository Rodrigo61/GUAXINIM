#include <bits/stdc++.h>

using namespace std;

#define MAXN 412
#define db(x) cerr << #x << " = " << x << endl;
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f

int N;
ll vals[MAXN];
int vis[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll sum(int l, int r)
{
	ll result = 0;
	
	for (int i = l; i <= r; i++)
	{
		result += vals[i];
	}
	
	return result;
}


ll solve(int l, int r)
{
	if (r == l)
	{
		return 0;
	}
	
	if (vis[l][r])
	{
		return dp[l][r];
	}
	vis[l][r] = 1;
	
	ll res = INF;
	ll s = sum(l, r);
	for (int i = l; i < r; i++)
	{
		ll left = solve(l, i);
		ll right = solve(i + 1, r);
		ll new_cost = left + right + s;
		
		if (new_cost < res)
		{
			res = new_cost;
		}
	}
	
	dp[l][r] = res;
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	printf("%lld\n", solve(0, N - 1));
}
