#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) //cerr << #x << " = " << x << endl
#define ll long long
#define vi vector<int>

#define MOD 1000000007
#define MAXN 11234


int N;
int vis[MAXN][MAXN][2];
ll dp[MAXN][MAXN][2];

ll add_mod(ll a, ll b)
{
	return (a + b) % MOD;
}

ll solve(int stones, int stack_sz, int even)
{
	if (stones == 0)
	{
		return !even;
	}
	
	if (stones < 0)
	{
		return 0;
	}
	
	if (stack_sz > stones)
	{
		return 0;
	}

	if (vis[stones][stack_sz][even])
	{
		return dp[stones][stack_sz][even];
	}
	vis[stones][stack_sz][even] = 1;
	
	ll res = 0;
	for (int i = 0; stack_sz * i <= stones; ++i)
	{
		int used_stones = stack_sz * i;
		int r = ((stack_sz - 1) * i) % 2;
		res = add_mod(res, solve(stones - used_stones, stack_sz + 1, (even + r) % 2));
	}
	
	return dp[stones][stack_sz][even] = res;
}

int main()
{
	int T;
	scanf("%d\n", &T);
	while (T--)
	{
		scanf("%d", &N);
		printf("%lld\n", solve(N, 1, 1));
	}
}
