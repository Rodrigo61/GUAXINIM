#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll expbin(ll N)
{
	ll ans = 1, p = 2;
	for(ll i = 1; i <= N; i <<= 1)
	{
		if(N&i)
		{
			ans = (ans*p)%MOD;
		}
		p = (p*p)%MOD;
	}
	return ans;
}

ll solve(ll x)
{
	ll ans = ((expbin(x)*((x-3)%MOD)%MOD + (x+3)%MOD)%MOD + MOD)%MOD;
	return ans;
}

main()
{
	ll x;
	int N;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%lld", &x);
		printf("%lld\n", solve(x));
	}
	return 0;
}
