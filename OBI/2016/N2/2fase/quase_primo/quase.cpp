#include <bits/stdc++.h>

using namespace std;

#define MAXK 45
#define ll long long

int N, K;
ll vals[MAXK];
ll total = 0;

void solve(int idx, int c, ll tot)
{
	if (idx == K)
	{
		if (c % 2 == 0)
		{
			total += N / tot;
		}
		else
		{
			total -= N / tot;
		}
	}
	else
	{
		solve(idx + 1, c , tot);
		if (tot * vals[idx] <= N)
		{
			solve(idx + 1, c + 1, tot * vals[idx]);
		}		
	}
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	solve(0, 0, 1);
	
	printf("%lld\n", total);
	
	return 0;
}
