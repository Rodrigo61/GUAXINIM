#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;

int const MAXN = 112;
int const nprimes = 17;
int N;
int vals[MAXN];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int factors[61];
int vis[MAXN][(1 << nprimes)];
int dp[MAXN][(1 << nprimes)];
int dpr[MAXN][(1 << nprimes)];

int solve(int ind, int mask)
{
	if (ind == N)
	{
		return 0;
	}
	
	if (vis[ind][mask])
	{
		return dp[ind][mask];
	}
	vis[ind][mask] = 1;
	
	int res = solve(ind + 1, mask) + abs(vals[ind] - 1);
	dpr[ind][mask] = 1;
	
	for (int i = 2; i < 61; i++)
	{
		if ((mask & factors[i]) == 0)
		{
			int rec = solve(ind + 1, mask | factors[i]) + abs(vals[ind] - i);
			if (rec < res)
			{
				res = rec;
				dpr[ind][mask] = i;
			}
		}
	}
	
	dp[ind][mask] = res;
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	for (int i = 2; i < 61; i++)
	{
		for (int j = 0; j < nprimes; j++)
		{
			if (i % primes[j] == 0)
			{
				factors[i] |= (1 << j);
			}
		}
		
	}
	
	solve(0, 0);
	
	int ind = 0;
	int mask = 0;
	while (ind < N)
	{
		int val = dpr[ind][mask];
		printf("%d ", val);
		
		mask |= factors[val];
		ind++;
	}
	
	db(factors[0]);
}
