#include<bits/stdc++.h>
#define ll long long

using namespace std;

int t;

int X, K, lim;
int vis[16][16][32768];
ll pd[16][16][32768];

ll solve(int x, int y, int mask)
{
	//printf("%d %d %d\n", x, y, mask);
	if(x == X)
		return 1;
	if(vis[x][y][mask] == t)
		return pd[x][y][mask];
	vis[x][y][mask] = t;
	ll r = 0;
	if(x == 0)
	{
		for(int i = 1, j = 1; j <= lim; i++, j <<= 1)
			r += solve(x+1, i, j);
	}
	else
	{
		for(int i = 1, j = 1; j <= lim; i++, j <<= 1)
		{
			if(abs(i-y) <= K && !(mask & j))
				r += solve(x+1, i, mask | j);
		}
	}
	return pd[x][y][mask] = r;
}


int main()
{
	int N;
	scanf("%d", &N);
	while(N--)
	{
		t++;
		scanf("%d %d", &X, &K);
		lim = (1 << X) - 1;
		printf("%lld\n", solve(0, 0, 0));
	}
	return 0;
}
