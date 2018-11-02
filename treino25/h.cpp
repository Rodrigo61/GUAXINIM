#include<bits/stdc++.h>
#define ll long long

ll coef[60];

void build()
{
	ll i, l;
	int j, k;
	coef[1] = 1;
	for(i = 4, j = 2; i <= 10000000000000000LL; i <<= 1, j++)
	{
		coef[j] = 2*j*(i/4);
		//printf("%d %lld\n", j, coef[j]);
	}
}

int main()
{
	ll x, i, ans;
	int N, j;
	build();
	scanf("%d", &N);
	while(N--)
	{
		scanf("%lld", &x);
		ans = 0;
		for(i = 1, j = 0; i <= x; i <<= 1, j++)
		{
			//printf("%lld %lld\n", coef[j], x/i);
			ans += coef[j]*(x/i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
