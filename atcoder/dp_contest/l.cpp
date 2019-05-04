#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 3123 
#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>

int N;
int vals[MAXN];
int vis[MAXN][MAXN][2];
pll dp[MAXN][MAXN][2];

pll solve(int l, int r, int turn)
{
	if (l > r)
	{
		return {0, 0};
	}
	
	if (vis[l][r][turn])
	{
		return dp[l][r][turn];
	}
	vis[l][r][turn] = 1;
	
	pll left_rec = solve(l + 1, r, !turn);
	pll right_rec = solve(l, r - 1, !turn);
	pll res;
	
	if (turn == 0)
	{
		if (left_rec.fi + vals[l] > right_rec.fi + vals[r])
		{
			res = left_rec;
			res.fi += vals[l];
		}
		else
		{
			res = right_rec;
			res.fi += vals[r];
		}
	}
	else
	{
		if (left_rec.se + vals[l] > right_rec.se + vals[r])
		{
			res = left_rec;
			res.se += vals[l];
		}
		else
		{
			res = right_rec;
			res.se += vals[r];
		}
	}
	
	dp[l][r][turn] = res;
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	pll res = solve(0, N - 1, 0);
	printf("%lld\n", res.fi - res.se);
	
	return 0;
}
